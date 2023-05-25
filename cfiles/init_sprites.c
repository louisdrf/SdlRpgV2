#include <SDL.h>
#include <string.h>
#include "../headers/init_sprites.h"
#include "../headers/structs.h"


void init_perso_sprites(Perso *p) {

    p->sprites[0] = "../img/perso/tileLeft1.png";
    p->sprites[1] = "../img/perso/tileRight1.png";
    p->sprites[2] = "../img/perso/tileBack1.png";
    p->sprites[3] = "../img/perso/tileFront1.png";
}