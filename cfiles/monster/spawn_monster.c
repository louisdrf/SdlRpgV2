#include <SDL.h>
#include <SDL_image.h>
#include <string.h>
#include <time.h>
#include "../../headers/monster/spawn_monster.h"
#include "../../headers/monster/init_sprites_monster.h"
#include "../../headers/main/structs.h"
#include "../../headers/init/create_texture.h"



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

    if(map->quadmap[topY][leftX] != 0 || map->quadmap[bottomY][leftX] != 0
        || map->quadmap[topY][rightX] != 0 || map->quadmap[bottomY][rightX] != 0) {
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

    while(is_pos_used(x, y, map, id_monster) != 0 || is_pos_collision(x, y, map, id_monster) != 0) {

         x = rand() % (NBTILES-NBMAPCUTS) + NBMAPCUTS; 
         y = rand() % (NBTILES-NBMAPCUTS) + NBMAPCUTS;
    }

    m->positionX = x;
    m->positionY = y;
    m->rect.x = m->positionX*TILESIZE;
    m->rect.y = m->positionY*TILESIZE;
    m->currentSprite = m->animations[0][0];
    m->lifepoints = 100;
    m->animation_index = 0;
    m->direction = 0;
    m->isAlive = true;

    map->quadmap[m->positionY][m->positionX] = 2; // on indique qu'un monstre est présent sur une case en affectant la valeur 2

    print_image(g, m->currentSprite, &(m->rect));
    SDL_RenderPresent(g->renderer);
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