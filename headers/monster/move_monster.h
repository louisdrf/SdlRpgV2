#ifndef MOVE_MONSTER
#define MOVE_MONSTER
#include "../main/defines.h"
#include "../main/structs.h"

void print_monsters(Game *g, Map *m);
void move_monster(Game *g, Map *map, Perso *p);
void get_position_monster(int idMonster, int distance, int direction, Map *map, Game *g, Perso *p);
void get_collision_monster(Game *g, Monster *m, Map *map, int direction, int distance, Perso *p, int idMonster);
int compare_monsters_collisions(Monster *m, Map *map, int direction, Perso *p, int idMonster);
void make_move_monster(Monster *m, Map *map, Game *g, int direction, Perso *p);

#endif