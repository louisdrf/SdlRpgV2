#ifndef MOVE
#define MOVE
#include <string.h>
#include "structs.h"

void move(char *direction, Game *g, Perso *p, Map *m);
void actualize_perso_movement(char *direction, Game *g, Perso *p, Map *m);
void fluid_move(Perso *p, Map *m, Game *g, Uint16 targetX, Uint16 targetY, char *direction);


#endif 