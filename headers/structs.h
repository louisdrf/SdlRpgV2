#ifndef STRUCT_H
#define STRUCT_H
#include <SDL.h>
#include "defines.h"

typedef struct Game {
    SDL_Window *window;
    SDL_Renderer *renderer;  
    SDL_Texture *buffer_draw;
    SDL_Texture *buffer_print;

} Game; 


typedef struct Perso {

    SDL_Rect rect; 
    SDL_Rect rectSword; 
    char *name; 
    int lifepoints;
    int speed; 
    char *animations[NB_PERSO_ANIMATIONS][4];
    SDL_Texture *animations_textures[NB_PERSO_ANIMATIONS][4];
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
    char *collisionMapPath;
    int x;
    int y;
    Uint16 quadmap[NBTILES][NBTILES];

} Map; 

typedef struct Globalmap {

    Map *gmap[NBMAPSX][NBMAPSY];

} Globalmap;


#endif