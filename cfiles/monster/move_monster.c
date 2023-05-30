#include <SDL.h>
#include <SDL_image.h>
#include <time.h>
#include "../../headers/monster/move_monster.h"
#include "../../headers/main/structs.h"


void move_monster(Game *g, Map *m) {

    srand(time(NULL));

    int idMonster = 0; // monstre qu'on va faire bouger
    int deplacement = 0; // longueur du déplacement en nombre de cases
    int direction;
}