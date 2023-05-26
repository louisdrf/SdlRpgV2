#include <SDL.h>
#include <SDL_image.h>
#include <string.h>
#include "../headers/init_sprites.h"
#include "../headers/structs.h"


void init_perso_animations(Perso *p) {

    p->animations[0][0] = "../img/link/linkLeft1.png";
    p->animations[0][1] = "../img/link/linkLeft2.png";
    p->animations[0][2] = "../img/link/linkLeft1.png";
    p->animations[0][3] = "../img/link/linkLeft2.png";

    p->animations[1][0] = "../img/link/linkRight1.png";
    p->animations[1][1] = "../img/link/linkRight2.png";
    p->animations[1][2] = "../img/link/linkRight1.png";
    p->animations[1][3] = "../img/link/linkRight2.png";

    p->animations[2][0] = "../img/link/linkUp1.png";
    p->animations[2][1] = "../img/link/linkUp2.png";
    p->animations[2][2] = "../img/link/linkUp1.png";
    p->animations[2][3] = "../img/link/linkUp2.png";

    p->animations[3][0] = "../img/link/linkForward1.png";
    p->animations[3][1] = "../img/link/linkForward2.png";
    p->animations[3][2] = "../img/link/linkForward1.png";
    p->animations[3][3] = "../img/link/linkForward2.png";
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

