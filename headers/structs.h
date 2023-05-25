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
    int speed; 
    char *sprites[NB_PERSO_ANIMATIONS];
    char *animations[4][4];
    SDL_Texture *animations_textures[4][4];
    int animation_index;
    char *currentSprite; 
    int xmap;
    int ymap;
    int positionX;
    int positionY;

} Perso;


typedef struct Map {

    SDL_Rect rect; 
    char *currentMapPath; 
    int x;
    int y;
    SDL_Rect parts[2][2];


} Map; 


#endif