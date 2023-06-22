#ifndef MOVE_MONSTER
#define MOVE_MONSTER
#include "../main/defines.h"
#include "../main/structs.h"

void print_monsters(Game *g, Map *m);
void move_monster(Game *g, Map *map, Perso *p);
void make_move_monster(Monster *m, Map *map, Game *g, Perso *p);

#endif