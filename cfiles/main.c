// gcc -c *.c  $(sdl2-config --cflags --libs) -lSDL2_image
// gcc -o main *.o $(sdl2-config --cflags --libs) -lSDL2_image
//https://convert-my-image.com/ImageConverter_Fr

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

Perso perso;
    perso.positionX = 5;
    perso.positionY = 5;
    perso.rect.x = perso.positionX * TILESIZE;
    perso.rect.y = perso.positionY * TILESIZE;
    perso.rect.w = 36;
    perso.rect.h = 36;
    perso.xmap = 0; // coordonnees map x
    perso.ymap = 0; // coordonnees map y
    perso.speed = PERSO_SPEED;

Perso *pperso = &perso; 
init_perso_sprites(pperso);
init_perso_animations(pperso); 


Map map;

    map.x = 0;
    map.y = 0;
    map.currentMapPath = "../img/mapsZelda/map00.png";
    map.rect.h = SCREEN_H;
    map.rect.w = SCREEN_W;
    map.rect.x = 0;
    map.rect.y = 0;


Map *pmap = &map;



// init sdl
sdl_init(pgame);
load_perso_animations(pperso, pgame); // load textures for character
// init the main loop of the game
launch_loop(pgame, pperso, pmap);
// close the game
sdl_close(pgame);



return EXIT_SUCCESS;
}