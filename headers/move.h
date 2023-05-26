#ifndef MOVE
#define MOVE
#include <string.h>
#include "structs.h"

void move(char *direction, Game *g, Perso *p, Map *m);
void actualize_perso_movement(char *direction, Game *g, Perso *p, Map *m);

#endif 