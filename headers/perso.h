#ifndef PERSO
#define PERSO
#include <SDL.h>
#include "structs.h"

void get_position_perso(Perso *p, Map *m, Game *g, char *direction);
void get_collision(Perso *p, Map *m, Game *g, char *direction);
void attack(Game *g, Perso *p, Map *m, char *lastmove);

#endif