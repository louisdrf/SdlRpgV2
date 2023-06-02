#ifndef MONSTER
#define MONSTER
#include "../main/structs.h"

void spawn(Monster *m, Game *g, Map *map, int nbmonsters);
void spawn_monsters(Game *g, Map *map);
int is_pos_used(int x, int y, Map *map, int nbmonsters);
int is_pos_collision(int x, int y, Map *map, int currentMonster);

#endif