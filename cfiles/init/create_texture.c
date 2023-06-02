#include <SDL.h>
#include <SDL_image.h>
#include <string.h>
#include "../../headers/init/create_texture.h"


void print_image(Game *g, char *imgpath, SDL_Rect *r) {


    SDL_Surface *imgSurface = IMG_Load(imgpath);
    if (imgSurface == NULL) {
    printf("Erreur lors du chargement de l'image : %s\n", IMG_GetError());
    exit(1);
    }

    SDL_Texture *imgTexture = SDL_CreateTextureFromSurface(g->renderer, imgSurface);
    SDL_FreeSurface(imgSurface); 
    if (imgTexture == NULL) {
        printf("Erreur lors de la création de la texture : %s\n", SDL_GetError());
        exit(1);
    }

    SDL_RenderCopy(g->renderer, imgTexture, NULL, r);
    SDL_DestroyTexture(imgTexture);
}



void print_map(Game *g, Map *m) {

   SDL_Surface *imgSurface = IMG_Load(m->currentMapPath);
    if (imgSurface == NULL) {
    printf("Erreur lors du chargement de l'image : %s\n", IMG_GetError());
    exit(1);
    }

    SDL_Texture *imgTexture = SDL_CreateTextureFromSurface(g->renderer, imgSurface);
    SDL_FreeSurface(imgSurface); 
    if (imgTexture == NULL) {
        printf("Erreur lors de la création de la texture : %s\n", SDL_GetError());
        exit(1);
    }

    SDL_RenderCopy(g->renderer, imgTexture, NULL, &(m->rect));
    SDL_DestroyTexture(imgTexture);
}
