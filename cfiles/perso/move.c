#include <SDL.h>
#include <string.h>
#include "../../headers/main/defines.h"
#include "../../headers/perso/move.h"
#include "../../headers/init/create_texture.h"
#include "../../headers/animation/animation.h"
#include "../../headers/perso/perso.h"
#include "../../headers/monster/move_monster.h"



void move(Game *g, Perso *p, Globalmap *gmap) {

    int direction = p->direction;
    int index = p->animation_index;

    switch(p->direction) {

        case LEFT:
        p->currentSprite = p->animations[direction][index];
        get_position_perso(p, gmap, g);
        break;

        case RIGHT:
        p->currentSprite = p->animations[direction][index];
        get_position_perso(p, gmap, g);
        break;

        case UP:
        p->currentSprite = p->animations[direction][index];
        get_position_perso(p, gmap, g);
        break;

        case DOWN:
        p->currentSprite = p->animations[direction][index];
        get_position_perso(p, gmap, g);
        break;

        default:
        break;
    }
        p->animation_index+=1;
        if(p->animation_index >= 4) p->animation_index = 0;

}


void actualize_perso_movement(Game *g, Perso *p, Map *m) {

    refresh_position_persoXY(p);

        SDL_RenderClear(g->renderer);
        print_map(g, m);
        print_monsters(g, m);
        SDL_RenderCopy(g->renderer, animation_perso(p), NULL, &(p->rect)); // animation_perso() retourne la texture correspondante à l'étape de l'animation en cours
        SDL_RenderPresent(g->renderer);
}


void fluid_move(Perso *p, Map *m, Game *g, Uint16 targetX, Uint16 targetY) {

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
    
        SDL_Delay(4);
        actualize_perso_movement(g, p, m);
    }

}


void timed_move(Perso *p, Game *g, Globalmap *gmap, int actualMove) {

        if(actualMove != p->lastmove) p->delay_between_animations = 0; // si on a changé de direction, le delai passe a 0
        if (SDL_GetTicks() - p->lastAnimTime >= p->delay_between_animations) 
        {
                move(g, p, gmap);
                p->lastAnimTime = SDL_GetTicks();
                p->lastmove = actualMove;
        if(p->delay_between_animations == 0) p->delay_between_animations = DELAY_BETWEEN_ANIMATIONS;
        }
}