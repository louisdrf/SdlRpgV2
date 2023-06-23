#ifndef PERSO
#define PERSO
#include <SDL.h>
#include "../main/structs.h"

void get_position_perso(Perso *p, Globalmap *gmap, Game *g);
void get_collision(Perso *p, Globalmap *gmap, Game *g);
void attack(Game *g, Perso *p, Map *m, int lastmove);
void change_map(Game *g, Perso *p, Globalmap *gmap);
void refresh_position_persoXY(Perso *p);
void free_cell(Perso *p, Map *m);

#endif