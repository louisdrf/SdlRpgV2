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
    perso.rect.x = 50;
    perso.rect.y = 50;
    perso.rect.w = 64;
    perso.rect.h = 64;

    perso.xmap = 0;
    perso.ymap = 0;
    perso.speed = PERSO_SPEED;

Perso *pperso = &perso; 
init_perso_sprites(pperso);
init_perso_animations(pperso); 



// init sdl
sdl_init(pgame);
load_perso_animations(pperso, pgame); // load textures for character
// init the main loop of the game
launch_loop(pgame, pperso);
// close the game
sdl_close(pgame);



return EXIT_SUCCESS;
}