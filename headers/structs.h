#ifndef STRUCT_H
#define STRUCT_H
#include <SDL.h>
#include "defines.h"

typedef struct Game {
    SDL_Window *window;
    SDL_Renderer *renderer;  

} Game; 


typedef struct Perso {

    SDL_Rect rect; 
    char *name; 
    int lifepoints;
    char *sprites[NB_PERSO_ANIMATIONS];

} Perso;


#endif