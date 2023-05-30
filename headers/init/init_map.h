#ifndef INIT_MAP
#define INIT_MAP
#include "../main/structs.h"

Globalmap *init_global_map();
void init_collisions(Map *m);
void read_collisions(Map *m);

#endif