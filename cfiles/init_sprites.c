#include <SDL.h>
#include <SDL_image.h>
#include <string.h>
#include "../headers/init_sprites.h"
#include "../headers/structs.h"


void init_perso_sprites(Perso *p) {

    p->sprites[0] = "../img/perso/tileLeft1.png";
    p->sprites[1] = "../img/perso/tileRight1.png";
    p->sprites[2] = "../img/perso/tileBack1.png";
    p->sprites[3] = "../img/perso/tileFront1.png";
}


void init_perso_animations(Perso *p) {

    p->animations[0][0] = "../img/perso/tileLeft1.png";
    p->animations[0][1] = "../img/perso/tileLeft2.png";
    p->animations[0][2] = "../img/perso/tileLeft3.png";
    p->animations[0][3] = "../img/perso/tileLeft4.png";

    p->animations[1][0] = "../img/perso/tileRight1.png";
    p->animations[1][1] = "../img/perso/tileRight2.png";
    p->animations[1][2] = "../img/perso/tileRight3.png";
    p->animations[1][3] = "../img/perso/tileRight4.png";

    p->animations[2][0] = "../img/perso/tileBack1.png";
    p->animations[2][1] = "../img/perso/tileBack2.png";
    p->animations[2][2] = "../img/perso/tileBack3.png";
    p->animations[2][3] = "../img/perso/tileBack4.png";

    p->animations[3][0] = "../img/perso/tileFront1.png";
    p->animations[3][1] = "../img/perso/tileFront2.png";
    p->animations[3][2] = "../img/perso/tileFront3.png";
    p->animations[3][3] = "../img/perso/tileFront4.png";
}


void load_perso_animations(Perso *p, Game *g) {

    int i, j = 0;

    for(i = 0; i < NB_PERSO_ANIMATIONS; i++) {

            for(j = 0; j < NB_PERSO_ANIMATIONS; j++) {

                        SDL_Surface *currentSurface = IMG_Load(p->animations[i][j]); // on charge les images du perso avant de les utiliser
                        //printf("%s\n", p->animations[i][j]);
                        if (currentSurface == NULL) {
                        printf("Erreur lors du chargement de l'image %s : %s\n", p->animations[i][j], IMG_GetError());
                        exit(1);
                        }

                        p->animations_textures[i][j] = SDL_CreateTextureFromSurface(g->renderer, currentSurface);
                        SDL_FreeSurface(currentSurface); 
                        if (p->animations_textures[i][j] == NULL) {
                            printf("Erreur lors de la création de la texture perso[%d][%d] : %s\n", i, j, SDL_GetError());
                            exit(1);
                        }
            }
      }
    
}

