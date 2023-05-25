#ifndef MOVE
#define MOVE
#include <string.h>
#include "structs.h"

void move(char *direction, SDL_Rect *rperso, Game *g, char *currentmap, SDL_Rect *rmap, Perso *p);
void actualize_perso_movement(Game *g, char *currentmap, SDL_Rect *rmap, Perso *p, char *direction, SDL_Rect *rperso);

#endif 