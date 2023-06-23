#ifndef ATTACK
#define ATTACK
#include "../main/structs.h"
#include <stdbool.h>

bool does_attack_touch(Perso *p, Map * m);
Monster *get_touched_monster(Map *m, Perso *p);

#endif