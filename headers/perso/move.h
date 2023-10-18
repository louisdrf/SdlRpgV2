#ifndef MOVE
#define MOVE
#include <string.h>
#include "../main/structs.h"

void move(Game *g, Perso *p, Globalmap *gmap);
void actualize_perso_movement(Game *g, Perso *p, Map *m);
void fluid_move(Perso *p, Map *m, Game *g, Uint16 targetX, Uint16 targetY);
void timed_move(Perso *p, Game *g, Globalmap *gmap, int actualMove);

#endif 