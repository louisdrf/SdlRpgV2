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


void init_perso_animations(Perso *p) {

    p->animations[0][0] = "../img/perso/tileLeft1.png";
    p->animations[0][1] = "../img/perso/tileLeft2.png";
    p->animations[0][2] = "../img/perso/tileLeft3.png";
    p->animations[0][3] = "../img/perso/tileLeft4.png";

    p->animations[1][0] = "../img/perso/tileRight1.png";
    p->animations[1][1] = "../img/perso/tileRight2.png";
    p->animations[1][2] = "../img/perso/tileRight3.png";
    p->animations[1][3] = "../img/perso/tileRight4.png";

    p->animations[2][0] = "../img/perso/tileBack1.png";
    p->animations[2][1] = "../img/perso/tileBack2.png";
    p->animations[2][2] = "../img/perso/tileBack3.png";
    p->animations[2][3] = "../img/perso/tileBack4.png";

    p->animations[3][0] = "../img/perso/tileFront1.png";
    p->animations[3][1] = "../img/perso/tileFront2.png";
    p->animations[3][2] = "../img/perso/tileFront3.png";
    p->animations[3][3] = "../img/perso/tileFront4.png";
}

