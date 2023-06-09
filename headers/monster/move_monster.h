#ifndef MOVE_MONSTER
#define MOVE_MONSTER
#include "../main/defines.h"
#include "../main/structs.h"

void print_monsters(Game *g, Map *m);
void move_monster(Game *g, Map *map, Perso *p);
void make_move_monster(Monster *m, Map *map, Game *g, Perso *p);
void get_position_monster(int idMonster, int distance, Map *map, Game *g, Perso *p);
void get_collision_monster(Game *g, Monster *m, Map *map, int distance, Perso *p, int idMonster);
void refresh_position_monsterXY(Monster *m, Map *map);


#endif