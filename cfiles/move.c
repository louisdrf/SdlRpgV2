#include <SDL.h>
#include <string.h>
#include "../headers/defines.h"
#include "../headers/move.h"
#include "../headers/create_texture.h"
#include "../headers/animation.h"


void move(char *direction, SDL_Rect *rperso, Game *g, char *currentmap, SDL_Rect *rmap, Perso *p) {

    p->animation_index+=1;


    if(strstr(direction, "left")) {

        SDL_RenderClear(g->renderer);
        rperso->x -= p->speed;
        print_map(currentmap, g, rmap);
        SDL_RenderCopy(g->renderer, animation_perso(p, direction), NULL, rperso); /// animation_perso() retourne la texture correspondante
    }

            if(strstr(direction, "right")) {
                        
                SDL_RenderClear(g->renderer);
                rperso->x += p->speed;
                print_map(currentmap, g, rmap);
                SDL_RenderCopy(g->renderer, animation_perso(p, direction), NULL, rperso); 
            }


    if(strstr(direction, "up")) {
                
        SDL_RenderClear(g->renderer);
        rperso->y -= p->speed;
        print_map(currentmap, g, rmap);
        SDL_RenderCopy(g->renderer, animation_perso(p, direction), NULL, rperso); 

    }


            if(strstr(direction, "down")) {

                SDL_RenderClear(g->renderer);
                rperso->y += p->speed;
                print_map(currentmap, g, rmap);
                SDL_RenderCopy(g->renderer, animation_perso(p, direction), NULL, rperso); 
            }
}