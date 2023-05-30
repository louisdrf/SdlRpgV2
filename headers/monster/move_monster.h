#ifndef MOVE_MONSTER
#define MOVE_MONSTER
#include "../main/defines.h"
#include "../main/structs.h"

void move_monster(Game *g, Map *map);
void get_position_monster(int idMonster, int distance, int direction, Map *map, Game *g);
void get_collision_monster(Game *g, Monster *m, Map *map, int direction, int distance);
void actualize_monster_movement(int direction, Game *g, Monster *m, Map *map);
void actualize_monster_movement(int direction, Game *g, Monster *m, Map *map);
void fluid_move_monster(Monster *m, Map *map, Game *g, Uint16 targetX, Uint16 targetY, int direction);

#endif