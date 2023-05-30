#include <SDL.h>
#include <string.h>
#include "../../headers/main/defines.h"
#include "../../headers/perso/move.h"
#include "../../headers/init/create_texture.h"
#include "../../headers/animation/animation.h"
#include "../../headers/perso/perso.h"

void move(int direction, Game *g, Perso *p, Globalmap *gmap) {

    switch(direction) {

        case LEFT:
        get_position_perso(p, gmap, g, LEFT);
        break;
        case RIGHT:
        get_position_perso(p, gmap, g, RIGHT);
        break;
        case UP:
        get_position_perso(p, gmap, g, UP);
        break;
        case DOWN:
        get_position_perso(p, gmap, g, DOWN);
        break;

        default:
        break;
    }
        p->animation_index+=1;
        if(p->animation_index >= 4) p->animation_index = 0;

}


void actualize_perso_movement(int direction, Game *g, Perso *p, Map *m) {

        SDL_RenderClear(g->renderer);
        print_map(g, m);
        SDL_RenderCopy(g->renderer, animation_perso(p, direction), NULL, &(p->rect)); /// animation_perso() retourne la texture correspondante à l'étape de l'animation en cours
        SDL_RenderPresent(g->renderer);
}


void fluid_move(Perso *p, Map *m, Game *g, Uint16 targetX, Uint16 targetY, int direction) {


    int currentX = p->rect.x;
    int currentY = p->rect.y;
    int targetPosX = targetX * TILESIZE;
    int targetPosY = targetY * TILESIZE;
    int deltaX = targetPosX - currentX;
    int deltaY = targetPosY - currentY;
    int totalDistance = abs(deltaX) + abs(deltaY);
    int stepX = deltaX / (totalDistance / 2); // Division en étapes de 2 pixels
    int stepY = deltaY / (totalDistance / 2); // Division en étapes de 2 pixels


    while (currentX != targetPosX || currentY != targetPosY) {


        if (abs(currentX - targetPosX) < abs(stepX)) {
            currentX = targetPosX;
        } else {
            currentX += stepX;
        }

        if (abs(currentY - targetPosY) < abs(stepY)) {
            currentY = targetPosY;
        } else {
            currentY += stepY;
        }

             p->rect.x = currentX;
             p->rect.y = currentY;
    

        SDL_Delay(5);
        actualize_perso_movement(direction, g, p, m);
    }

}