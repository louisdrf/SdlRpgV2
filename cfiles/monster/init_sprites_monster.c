#include <SDL.h>
#include <SDL_image.h>
#include <string.h>
#include <time.h>
#include "../../headers/monster/init_sprites_monster.h"
#include "../../headers/main/structs.h"
#include "../../headers/init/create_texture.h"

void init_monster_animations(Monster *m) {

    m->animations[0][0] = "img/link/linkLeft1.png";
    m->animations[0][1] = "img/link/linkLeft2.png";
    m->animations[0][2] = "img/link/linkLeft1.png";
    m->animations[0][3] = "img/link/linkLeft2.png";

    m->animations[1][0] = "img/link/linkRight1.png";
    m->animations[1][1] = "img/link/linkRight2.png";
    m->animations[1][2] = "img/link/linkRight1.png";
    m->animations[1][3] = "img/link/linkRight2.png";

    m->animations[2][0] = "img/link/linkUp1.png";
    m->animations[2][1] = "img/link/linkUp2.png";
    m->animations[2][2] = "img/link/linkUp1.png";
    m->animations[2][3] = "img/link/linkUp2.png";

    m->animations[3][0] = "img/link/linkForward1.png";
    m->animations[3][1] = "img/link/linkForward2.png";
    m->animations[3][2] = "img/link/linkForward1.png";
    m->animations[3][3] = "img/link/linkForward2.png";

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

