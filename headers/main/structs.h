#ifndef STRUCT_H
#define STRUCT_H
#include <SDL.h>
#include <stdbool.h>
#include "defines.h"

typedef enum {
    LEFT,
    RIGHT,
    UP,
    DOWN
} Direction;

typedef struct Game {
    SDL_Window *window;
    SDL_Renderer *renderer;  
} Game; 


typedef struct Perso {

    long lastAnimTime;
    long lastAttackTime;
    Uint8 delay_between_animations;
    Uint8 delay_between_attacks;
    Uint8 lastmove;
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
    Uint8 positionX;
    Uint8 positionY;
    Uint8 direction;
    int damage;

} Perso;


typedef struct Monster {
    SDL_Rect rect;
    int lifepoints;
    int speed;
    char *animations[NB_MONSTER_ANIMATIONS][4];
    SDL_Texture *animations_textures[NB_MONSTER_ANIMATIONS][4];
    int animation_index;
    char *currentSprite; 
    int positionX;
    int positionY;
    int direction;
    bool isAlive;
    
} Monster;


typedef struct Map {

    SDL_Rect rect; 
    SDL_Texture *texture;
    SDL_Surface *surface;
    char *currentMapPath; 
    char *collisionMapPath;
    int x;
    int y;
    int quadmap[NBTILES][NBTILES];
    int nbmonsters;
    Monster *monsters[NBMAXMONSTER];

} Map; 

typedef struct Globalmap {

    Map *gmap[NBMAPSY][NBMAPSX];

} Globalmap;


#endif