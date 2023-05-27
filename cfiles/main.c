// gcc -c *.c  $(sdl2-config --cflags --libs) -lSDL2_image
// gcc -o main *.o $(sdl2-config --cflags --libs) -lSDL2_image
//https://convert-my-image.com/ImageConverter_Fr
//https://www.spriters-resource.com/fullview/109034/

#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include "../headers/init.h"
#include "../headers/loop.h"
#include "../headers/init_sprites.h"



int main(int argc, char **argv) {

Game game; 
Game *pgame = &game;

Perso perso = {
    .positionX = NBTILES/4,
    .positionY = NBTILES/4,
    .rect = {
        .x = (NBTILES/4) * TILESIZE,
        .y = (NBTILES/4) * TILESIZE,
        .w = 36,
        .h = 36
    },
    .xmap = 0,
    .ymap = 0,
    .speed = PERSO_SPEED,
    .currentSprite = "../img/link/linkRight1.png",
    .animation_index = 0,
    .rectSword = {
        .x = (NBTILES/4) * TILESIZE,
        .y = (NBTILES/4) * TILESIZE,
        .w = 40,
        .h = 40
    }
};
Perso *pperso = &perso;


Map map = {
    .x = 0,
    .y = 0,
    .currentMapPath = "../img/mapsZelda/map01.png",
    .rect = {
        .h = SCREEN_H,
        .w = SCREEN_W,
        .x = 0,
        .y = 0
    }
};

Map *pmap = &map;

init_perso_animations(pperso); 
init_perso_animations_attack(pperso);

// init sdl
sdl_init(pgame);
load_perso_animations(pperso, pgame); // load textures for character
// init the main loop of the game
launch_loop(pgame, pperso, pmap);
// close the game
sdl_close(pgame);



return EXIT_SUCCESS;
}