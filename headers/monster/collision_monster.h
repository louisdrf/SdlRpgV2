#ifndef COLLISION_MONSTER
#define COLLISION_MONSTER
#include "../main/defines.h"
#include "../main/structs.h"

void get_position_monster(int idMonster, int distance, Map *map, Game *g, Perso *p);
void get_collision_monster(Game *g, Monster *m, Map *map, int distance, Perso *p, int idMonster);
void refresh_position_monsterXY(Monster *m);

#endif