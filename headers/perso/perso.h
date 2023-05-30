#ifndef PERSO
#define PERSO
#include <SDL.h>
#include "../main/structs.h"

void get_position_perso(Perso *p, Globalmap *gmap, Game *g, char *direction);
void get_collision(Perso *p, Globalmap *gmap, Game *g, char *direction);
void attack(Game *g, Perso *p, Map *m, char *lastmove);
void change_map(Game *g, Perso *p, char *direction, Globalmap *gmap);

#endif