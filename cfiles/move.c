#include <SDL.h>
#include <string.h>
#include "../headers/defines.h"
#include "../headers/move.h"
#include "../headers/create_texture.h"
#include "../headers/animation.h"


void move(char *direction, SDL_Rect *rperso, Game *g, char *currentmap, SDL_Rect *rmap, Perso *p) {


    if(strstr(direction, "left"))   rperso->x -= p->speed;
    if(strstr(direction, "right"))  rperso->x += p->speed;
    if(strstr(direction, "up"))     rperso->y -= p->speed;
    if(strstr(direction, "down"))   rperso->y += p->speed;
    
        actualize_perso_movement(g, currentmap, rmap, p, direction, rperso); // affiche de nouveau la map puis le personnage
        
        if(p->animation_index >= 4) p->animation_index = 0;

}




void actualize_perso_movement(Game *g, char *currentmap, SDL_Rect *rmap, Perso *p, char *direction, SDL_Rect *rperso) {

        SDL_RenderClear(g->renderer);
        print_map(currentmap, g, rmap);
        SDL_RenderCopy(g->renderer, animation_perso(p, direction), NULL, rperso); /// animation_perso() retourne la texture correspondante à l'étape de l'animation en cours
        p->animation_index+=1;
        SDL_RenderPresent(g->renderer);
}