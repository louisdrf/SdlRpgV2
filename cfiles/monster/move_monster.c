#include <SDL.h>
#include <SDL_image.h>
#include <time.h>
#include "../../headers/monster/move_monster.h"
#include "../../headers/main/structs.h"
#include "../../headers/main/defines.h"
#include "../../headers/init/create_texture.h"

void move_monster(Game *g, Map *map) {

    srand(time(NULL));

    int idMonster = 0; // monstre qu'on va faire bouger
    int distance = 0; // longueur du déplacement en nombre de cases
    int direction = 0;

    idMonster = rand() % ((map->nbmonsters) - 1); // 0 à (nbmonster-1) 
    distance = rand() % 4 + 1; // bouge de 0 à 3 cases
    direction = rand() % 3; // LEFT(0) RIGHT UP DOWN(3)

    get_position_monster(idMonster, distance, direction, map, g);
}


void get_position_monster(int idMonster, int distance, int direction, Map *map, Game *g) {

    Monster *m = map->monsters[idMonster]; 

    get_collision_monster(g, m, map, direction, distance);

    m->positionX = (m->rect.x)/TILESIZE;
    m->positionY = (m->rect.y)/TILESIZE;
}



void get_collision_monster(Game *g, Monster *m, Map *map, int direction, int distance) {

// on recupere les coordonnées des cases adjacentes dans la map de collisions

    int caseGauche = map->quadmap[m->positionY + (m->rect.h/TILESIZE)/2][m->positionX - 1];
    int caseDroite = map->quadmap[m->positionY + (m->rect.h/TILESIZE)/2][(m->positionX + (m->rect.w/TILESIZE))];
    int caseHaut = map->quadmap[m->positionY - 1][m->positionX + (m->rect.w/TILESIZE)/2];
    int caseBas = map->quadmap[(m->positionY + (m->rect.h/TILESIZE))][m->positionX + (m->rect.w/TILESIZE)/2];

//
    switch(direction) {

        case LEFT:
        if(caseGauche == 0) fluid_move_monster(m, map, g, (m->positionX - distance), (m->positionY), direction); // on envoie la case cible a fluid_move_monster pour deplacer le monstre
        break;

        case RIGHT:
        if(caseGauche == 0) fluid_move_monster(m, map, g, (m->positionX + distance), (m->positionY), direction);
        break;

        case UP:
        if(caseHaut == 0) fluid_move_monster(m, map, g, (m->positionX), (m->positionY - distance), direction);
        break;

        case DOWN:
        if(caseBas == 0) fluid_move_monster(m, map, g, (m->positionX), (m->positionY + distance), direction);
        break;

        default:
        break;
    }
}

void actualize_monster_movement(int direction, Game *g, Monster *m, Map *map) {

        SDL_RenderClear(g->renderer);
        print_map(g, map);
        SDL_RenderCopy(g->renderer, m->animations_textures[0][0], NULL, &(m->rect)); /// animation_perso() retourne la texture correspondante à l'étape de l'animation en cours
        SDL_RenderPresent(g->renderer);
}

void fluid_move_monster(Monster *m, Map *map, Game *g, Uint16 targetX, Uint16 targetY, int direction) {

    int currentX = m->rect.x;
    int currentY = m->rect.y;
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

             m->rect.x = currentX;
             m->rect.y = currentY;
    

        SDL_Delay(5);
        actualize_monster_movement(direction, g, m, map);
    }
}




