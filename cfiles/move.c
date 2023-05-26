#include <SDL.h>
#include <string.h>
#include "../headers/defines.h"
#include "../headers/move.h"
#include "../headers/create_texture.h"
#include "../headers/animation.h"
#include "../headers/perso.h"

void move(char *direction, Game *g, Perso *p, Map *m) {


    if(strstr(direction, "left")) get_position_perso(p, m, g, "left");
    if(strstr(direction, "right")) get_position_perso(p, m, g, "right");
    if(strstr(direction, "up")) get_position_perso(p, m, g, "up");
    if(strstr(direction, "down")) get_position_perso(p, m, g, "down");
    
        actualize_perso_movement(direction, g, p, m); // affiche de nouveau la map puis le personnage
        p->animation_index+=1;
        if(p->animation_index >= 4) p->animation_index = 0;

}




void actualize_perso_movement(char *direction, Game *g, Perso *p, Map *m) {

        SDL_RenderClear(g->renderer);
        print_map(g, m);
        SDL_RenderCopy(g->renderer, animation_perso(p, direction), NULL, &(p->rect)); /// animation_perso() retourne la texture correspondante à l'étape de l'animation en cours
        SDL_RenderPresent(g->renderer);
}


void fluid_move(Perso *p, Map *m, Game *g, Uint16 targetX, Uint16 targetY, char *direction) { // mouvement avec vecteur

    int currentX = p->rect.x;
    int currentY = p->rect.y;
    int deltaX = (targetX*TILESIZE) - currentX;
    int deltaY = (targetY*TILESIZE) - currentY;
    int totalDistance = abs(deltaX) + abs(deltaY);
    int stepX = deltaX / (totalDistance / 2); // Division en étapes de 4 pixels
    int stepY = deltaY / (totalDistance / 2); // Division en étapes de 4 pixels

    while (currentX != (targetX*TILESIZE) || currentY != (targetY*TILESIZE)) {
        // mise à jour des coordonnées 
        currentX += stepX;
        currentY += stepY;
        
        p->rect.x = currentX;
        p->rect.y = currentY;
        
        SDL_Delay(10); 
        actualize_perso_movement(direction, g, p, m);
    }
}