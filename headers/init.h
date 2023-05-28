#ifndef INIT_H
#define INIT_H
#include "structs.h"

void sdl_init(Game *g);
void sdl_close(Game *g);
void clean_ressources(Globalmap *gmap, Perso *p);


#endif