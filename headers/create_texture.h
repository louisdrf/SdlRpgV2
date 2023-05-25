#ifndef CREATE_TEXTURE
#define CREATE_TEXTURE
#include <SDL.h>
#include <string.h>
#include "structs.h"

void print_image(Game *g, char *imgpath, SDL_Rect *r);
void print_map(char *index, Game *g, SDL_Rect *r);

#endif