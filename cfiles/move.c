#include <SDL.h>
#include <string.h>
#include "../headers/defines.h"
#include "../headers/move.h"
#include "../headers/create_texture.h"
#include "../headers/animation.h"
#include "../headers/perso.h"

void move(char *direction, Game *g, Perso *p, Map *m) {


    if(strstr(direction, "left")) get_position_perso(p, m, "left");
    if(strstr(direction, "right")) get_position_perso(p, m, "right");
    if(strstr(direction, "up")) get_position_perso(p, m, "up");
    if(strstr(direction, "down")) get_position_perso(p, m, "down");
    
        actualize_perso_movement(direction, g, p, m); // affiche de nouveau la map puis le personnage
        
        if(p->animation_index >= 4) p->animation_index = 0;

}




void actualize_perso_movement(char *direction, Game *g, Perso *p, Map *m) {

        SDL_RenderClear(g->renderer);
        print_map(g, m);
        SDL_RenderCopy(g->renderer, animation_perso(p, direction), NULL, &(p->rect)); /// animation_perso() retourne la texture correspondante à l'étape de l'animation en cours
        p->animation_index+=1;
        SDL_RenderPresent(g->renderer);
}