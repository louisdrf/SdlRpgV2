#include <SDL.h>
#include <SDL_image.h>
#include <time.h>
#include "../../headers/monster/move_monster.h"
#include "../../headers/main/structs.h"
#include "../../headers/main/defines.h"
#include "../../headers/init/create_texture.h"


void print_monsters(Game *g, Map *map) {

    for (int i = 0; i < map->nbmonsters; i++) {

        Monster *currentMonster = map->monsters[i];
        SDL_Texture *currentTexture = currentMonster->animations_textures[currentMonster->direction][currentMonster->animation_index];

        SDL_RenderCopy(g->renderer, currentTexture, NULL, &(currentMonster->rect));

        currentMonster->animation_index += 1;
        if (currentMonster->animation_index >= 4)  currentMonster->animation_index = 0;
           
    }
}

void move_monster(Game *g, Map *map, Perso *p) {
    
    srand(time(NULL));

    int nbMonsterToMove = rand() % map->nbmonsters;

   for (int i = 0; i < nbMonsterToMove; i++) {
        int idMonster = rand() % map->nbmonsters;
        Monster *currentMonster = map->monsters[idMonster];
        int distance = 1;
        int direction = rand() % 3;

        currentMonster->direction = direction;

        get_position_monster(idMonster, distance, direction, map, g, p);
    }
}


void get_position_monster(int idMonster, int distance, int direction, Map *map, Game *g, Perso *p) {

    Monster *m = map->monsters[idMonster]; 

    get_collision_monster(g, m, map, direction, distance, p);

    m->positionX = (m->rect.x)/TILESIZE;
    m->positionY = (m->rect.y)/TILESIZE;
}



void get_collision_monster(Game *g, Monster *m, Map *map, int direction, int distance, Perso *p) {

// on recupere les coordonnées des cases adjacentes dans la map de collisions

    int caseGauche = map->quadmap[m->positionY + (m->rect.h/TILESIZE)/2][m->positionX - 1];
    int caseDroite = map->quadmap[m->positionY + (m->rect.h/TILESIZE)/2][(m->positionX + (m->rect.w/TILESIZE))];
    int caseHaut = map->quadmap[m->positionY - 1][m->positionX + (m->rect.w/TILESIZE)/2];
    int caseBas = map->quadmap[(m->positionY + (m->rect.h/TILESIZE))][m->positionX + (m->rect.w/TILESIZE)/2];

//
    switch(direction) {

        case LEFT:
        if(caseGauche == 0) fluid_move_monster(m, map, g, (m->positionX - distance), (m->positionY), direction, p); // on envoie la case cible a fluid_move_monster pour deplacer le monstre
        break;

        case RIGHT:
        if(caseGauche == 0) fluid_move_monster(m, map, g, (m->positionX + distance), (m->positionY), direction, p);
        break;

        case UP:
        if(caseHaut == 0) fluid_move_monster(m, map, g, (m->positionX), (m->positionY - distance), direction, p);
        break;

        case DOWN:
        if(caseBas == 0) fluid_move_monster(m, map, g, (m->positionX), (m->positionY + distance), direction, p);
        break;

        default:
        break;
    }
}



void fluid_move_monster(Monster *m, Map *map, Game *g, Uint16 targetX, Uint16 targetY, int direction, Perso *p) {

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
        SDL_RenderClear(g->renderer);
        print_map(g, map);
        print_image(g, p->animations[p->direction][p->animation_index], &(p->rect)); 
        SDL_RenderCopy(g->renderer, m->animations_textures[m->direction][m->animation_index], NULL, &(m->rect)); // animation_perso() retourne la texture correspondante à l'étape de l'animation en cours
        SDL_RenderPresent(g->renderer);
    }
}




