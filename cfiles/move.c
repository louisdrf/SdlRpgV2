#include <SDL.h>
#include <string.h>
#include "../headers/defines.h"
#include "../headers/move.h"
#include "../headers/create_texture.h"


void move(char *direction, int speed, SDL_Rect *rperso, Game *g, char *imgpath, char *currentmap, SDL_Rect *rmap) {

    if(strstr(direction, "left")) {

        SDL_RenderClear(g->renderer);
        rperso->x -= speed;
        print_map(currentmap, g, rmap);
        print_image(g, imgpath, rperso);

    }

    if(strstr(direction, "right")) {
                
        SDL_RenderClear(g->renderer);
        rperso->x += speed;
        print_map(currentmap, g, rmap);
        print_image(g, imgpath, rperso);
    }

    if(strstr(direction, "up")) {
                
        SDL_RenderClear(g->renderer);
        rperso->y -= speed;
        print_map(currentmap, g, rmap);
        print_image(g, imgpath, rperso);
    }

    if(strstr(direction, "down")) {

        SDL_RenderClear(g->renderer);
        rperso->y += speed;
        print_map(currentmap, g, rmap);
        print_image(g, imgpath, rperso);
    }
}