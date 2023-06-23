// gcc -Wall -Wextra -c *.c  $(sdl2-config --cflags --libs) -lSDL2_image
// gcc -o main *.o $(sdl2-config --cflags --libs) -lSDL2_image
//https://convert-my-image.com/ImageConverter_Fr
//https://www.spriters-resource.com/fullview/109034/

#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include "../../headers/init/init.h"
#include "../headers/main/loop.h"
#include "../../headers/perso/init_sprites.h"
#include "../../headers/init/init_map.h"
#include "../headers/main/defines.h"

int main() {

Game game; 
Game *pgame = &game;

Perso perso = {
    .delay_between_animations = DELAY_BETWEEN_ANIMATIONS,
    .delay_between_attacks = DELAY_BETWEEN_ATTACKS,
    .lastAnimTime = 0,
    .lastmove = DOWN,
    .positionX = NBTILES/2,
    .positionY = NBTILES/2,
    .rect = {
        .x = (NBTILES/2) * TILESIZE,
        .y = (NBTILES/2) * TILESIZE,
        .w = 36,
        .h = 36
    },
    .xmap = 0,
    .ymap = 0,
    .speed = PERSO_SPEED,
    .damage = PERSO_DAMAGE,
    .lifepoints = 100,
    .currentSprite = "img/link/linkRight1.png",
    .animation_index = 0,
    .rectSword = {
        .x = (NBTILES/2) * TILESIZE,
        .y = (NBTILES/2) * TILESIZE,
        .w = 36,
        .h = 36
    }
};
Perso *pperso = &perso;



Globalmap *pgmap = init_global_map(); // on recupere la map complete


init_perso_animations(pperso); 
init_perso_animations_attack(pperso);

// init sdl
sdl_init(pgame);


load_perso_animations(pperso, pgame); // load textures for character
// init the main loop of the game
launch_loop(pgame, pperso, pgmap);
// close the game
sdl_close(pgame);


return EXIT_SUCCESS;
}