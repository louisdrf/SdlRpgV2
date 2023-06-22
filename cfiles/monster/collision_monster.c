#include <SDL.h>
#include <SDL_image.h>
#include <time.h>
#include "../../headers/monster/collision_monster.h"
#include "../../headers/monster/move_monster.h"
#include "../../headers/main/structs.h"
#include "../../headers/main/defines.h"
#include "../../headers/init/create_texture.h"



void get_collision_monster(Game *g, Monster *m, Map *map, int distance, Perso *p, int idMonster) {

// on recupere les coordonnées des cases adjacentes dans la map de collisions

    int caseGauche = map->quadmap[m->positionY + ((m->rect.h/TILESIZE) / 2)][m->positionX - 1];
    int caseDroite = map->quadmap[m->positionY + ((m->rect.h/TILESIZE) / 2)][(m->positionX + (m->rect.w/TILESIZE))];
    int caseHaut = map->quadmap[m->positionY - 1][m->positionX + ((m->rect.w/TILESIZE) / 2)];
    int caseBas = map->quadmap[m->positionY + (m->rect.h/TILESIZE) + 1][m->positionX + ((m->rect.w/TILESIZE) / 2)];

//
    switch(m->direction) {

        case LEFT:
        if(caseGauche == 0) make_move_monster(m, map, g, p); 
        break;

        case RIGHT:
        if(caseDroite == 0) make_move_monster(m, map, g, p);
        break;

        case UP:
        if(caseHaut == 0) make_move_monster(m, map, g, p);
        break;

        case DOWN:
        if(caseBas == 0) make_move_monster(m, map, g, p);
        break;

        default:
        break;
    }
}


void get_position_monster(int idMonster, int distance, Map *map, Game *g, Perso *p) {

    Monster *m = map->monsters[idMonster]; 

    get_collision_monster(g, m, map, distance, p, idMonster); // move si case disponible
    refresh_position_monsterXY(m);
}


void refresh_position_monsterXY(Monster *m) {

    m->positionX = (m->rect.x)/TILESIZE;
    m->positionY = (m->rect.y)/TILESIZE;
}
