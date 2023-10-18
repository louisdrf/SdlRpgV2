#ifndef INIT_MAP
#define INIT_MAP
#include "../main/structs.h"

Globalmap *init_global_map(Game *g);
void init_collisions(Map *m);
void read_collisions(Map *m);
void init_textures(Map *m, Game *g);

#endif