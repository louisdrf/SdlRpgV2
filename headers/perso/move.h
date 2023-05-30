#ifndef MOVE
#define MOVE
#include <string.h>
#include "../main/structs.h"

void move(int direction, Game *g, Perso *p, Globalmap *gmap);
void actualize_perso_movement(int direction, Game *g, Perso *p, Map *m);
void fluid_move(Perso *p, Map *m, Game *g, Uint16 targetX, Uint16 targetY, int direction);


#endif 