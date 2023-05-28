#ifndef INIT_MAP
#define INIT_MAP
#include "structs.h"

Globalmap *init_global_map(Game *g);
void init_collisions(Map *m, Game *g);
int read_collisions(Map *m);

#endif