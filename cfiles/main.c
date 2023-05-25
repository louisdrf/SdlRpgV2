// gcc -c *.c  $(sdl2-config --cflags --libs) -lSDL2_image
// gcc -o main *.o $(sdl2-config --cflags --libs) -lSDL2_image
//https://convert-my-image.com/ImageConverter_Fr

#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include "../headers/structs.h"
#include "../headers/init.h"
#include "../headers/loop.h"
#include "../headers/init_sprites.h"



int main(int argc, char **argv) {

Game game; 
Game *pgame = &game;

Perso perso;
    perso.rect.x = 360;
    perso.rect.y = 360;
    perso.rect.w = 64;
    perso.rect.h = 64;

Perso *pperso = &perso; 
init_perso_sprites(pperso);


// init sdl
sdl_init(pgame);
// init the main loop of the game
launch_loop(pgame, pperso);
// close the game
sdl_close(pgame);

return EXIT_SUCCESS;
}