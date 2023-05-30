#ifndef PERSO
#define PERSO
#include <SDL.h>
#include "../main/structs.h"

void get_position_perso(Perso *p, Globalmap *gmap, Game *g, int direction);
void get_collision(Perso *p, Globalmap *gmap, Game *g, int direction);
void attack(Game *g, Perso *p, Map *m, int lastmove);
void change_map(Game *g, Perso *p, int direction, Globalmap *gmap);

#endif