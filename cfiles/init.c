#include <SDL.h>
#include "../headers/init.h"
#include "../headers/structs.h"
#include "../headers/defines.h"


void sdl_init(Game *g) {

    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
            printf("erreur d'initialisation de la SDL : %s\n", SDL_GetError());
            exit(1);
        }

    g->window = SDL_CreateWindow("Zelda", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_W, SCREEN_W, SDL_WINDOW_SHOWN);
    if(g->window == NULL) {
        printf("erreur de creation de la fenetre : %s\n", SDL_GetError());
        exit(1);
    }

    g->renderer = SDL_CreateRenderer(g->window, -1, SDL_RENDERER_ACCELERATED);
    if(g->renderer == NULL) {
        printf("erreur de creation du rendu : %s\n", SDL_GetError());
        exit(1);
    }   

    g->buffer_draw = SDL_CreateTexture(g->renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, SCREEN_W, SCREEN_W);
    g->buffer_print = SDL_CreateTexture(g->renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, SCREEN_W, SCREEN_W);

}


void sdl_close(Game *g) {


    if(g->renderer != NULL) {
        SDL_DestroyRenderer(g->renderer);
    }

    if(g->window != NULL) {
        SDL_DestroyWindow(g->window);
    }

    SDL_Quit();


}


void clean_ressources(Globalmap *gmap, Perso *p) {

    free(gmap);
    free(p);
    
}
