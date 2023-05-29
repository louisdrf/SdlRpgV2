#include <SDL.h>
#include <SDL_image.h>
#include <string.h>
#include <time.h>
#include "../headers/init_sprites_monster.h"
#include "../headers/structs.h"
#include "../headers/create_texture.h"

void init_monster_animations(Monster *m) {

    m->animations[0][0] = "../img/link/linkLeft1.png";
    m->animations[0][1] = "../img/link/linkLeft2.png";
    m->animations[0][2] = "../img/link/linkLeft1.png";
    m->animations[0][3] = "../img/link/linkLeft2.png";

    m->animations[1][0] = "../img/link/linkRight1.png";
    m->animations[1][1] = "../img/link/linkRight2.png";
    m->animations[1][2] = "../img/link/linkRight1.png";
    m->animations[1][3] = "../img/link/linkRight2.png";

    m->animations[2][0] = "../img/link/linkUp1.png";
    m->animations[2][1] = "../img/link/linkUp2.png";
    m->animations[2][2] = "../img/link/linkUp1.png";
    m->animations[2][3] = "../img/link/linkUp2.png";

    m->animations[3][0] = "../img/link/linkForward1.png";
    m->animations[3][1] = "../img/link/linkForward2.png";
    m->animations[3][2] = "../img/link/linkForward1.png";
    m->animations[3][3] = "../img/link/linkForward2.png";

}

void load_monster_animations(Monster *m, Game *g) {

    int i, j = 0;

    for(i = 0; i < NB_MONSTER_ANIMATIONS; i++) {

            for(j = 0; j < 4; j++) {

                        SDL_Surface *currentSurface = IMG_Load(m->animations[i][j]); // on charge les images du perso avant de les utiliser
                        if (currentSurface == NULL) {
                        printf("Erreur lors du chargement de l'image %s : %s\n", m->animations[i][j], IMG_GetError());
                        exit(1);
                        }

                        m->animations_textures[i][j] = SDL_CreateTextureFromSurface(g->renderer, currentSurface);
                        SDL_FreeSurface(currentSurface); 
                        if (m->animations_textures[i][j] == NULL) {
                            printf("Erreur lors de la création de la texture perso[%d][%d] : %s\n", i, j, SDL_GetError());
                            exit(1);
                        }
            }
      }
}

int is_pos_used(int x, int y, Map *map, int nbmonsters) {

    int xleft = x;
    int ytop = y;
    int xright = x + (map->monsters[nbmonsters]->rect.w/TILESIZE); // coordonnées du monstre actuel
    int ybottom = y + (map->monsters[nbmonsters]->rect.h/TILESIZE);

    for (int i = 0; i < nbmonsters; i++) { 

        if(i != nbmonsters) {

                int leftX = map->monsters[i]->positionX;
                int rightX = map->monsters[i]->positionX + (map->monsters[i]->rect.w/TILESIZE); // coordonnées du monstre dans le tableau 
                int topY = map->monsters[i]->positionY;
                int bottomY = map->monsters[i]->positionY + (map->monsters[i]->rect.h/TILESIZE);

                if (xright >= leftX && xleft <= rightX && ytop <= bottomY && ybottom >= topY) { // si un des coin du monstre touche un monstre qui a deja spawn
                    return 1;
                 }
        }
    }
    return 0; 
}

int is_pos_collision(int x, int y, Map *map, int id_monster) {

    int leftX = x;
    int rightX = x + (map->monsters[id_monster]->rect.w / TILESIZE);
    int topY = y;
    int bottomY = y + (map->monsters[id_monster]->rect.h / TILESIZE);

    if(map->quadmap[topY][leftX] == 0 && map->quadmap[bottomY][leftX] == 0
        && map->quadmap[topY][rightX] == 0 && map->quadmap[bottomY][rightX] == 0)  {
            return 1;
        }
        else {
                 return 0;
        }
}


void spawn(Monster *m, Game *g, Map *map, int id_monster) {

    m->rect.h = 36;
    m->rect.w = 36;

    int x = rand() % (NBTILES-NBMAPCUTS) + NBMAPCUTS; // on evite que le monstre spawn dans les limites de la carte
    int y = rand() % (NBTILES-NBMAPCUTS) + NBMAPCUTS;

    while(is_pos_used(x, y, map, id_monster) != 0) {

         x = rand() % (NBTILES-NBMAPCUTS) + NBMAPCUTS; 
         y = rand() % (NBTILES-NBMAPCUTS) + NBMAPCUTS;
    }

    m->positionX = x;
    m->positionY = y;
    m->rect.x = m->positionX*TILESIZE;
    m->rect.y = m->positionY*TILESIZE;
    m->currentSprite = m->animations[0][0];
    print_image(g, m->currentSprite, &(m->rect));
    SDL_RenderPresent(g->renderer);
    printf("monstre x : %d y : %d\n", m->positionX, m->positionY);
}

void spawn_monsters(Game *g, Map *map) {

      srand(time(NULL));

    Monster *monsters[map->nbmonsters];

    for(int i = 0; i < (map->nbmonsters); i++) {

        Monster *m = malloc(sizeof(Monster));
        if (m == NULL) {
            printf("erreur d'allocation pour le monstre\n");
            exit(1);
        }
        
            init_monster_animations(m);
            load_monster_animations(m, g);

            monsters[i] = m;
            map->monsters[i] = monsters[i];

            spawn(m, g, map, i);
    }
}