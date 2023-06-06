#include <SDL.h>
#include <SDL_image.h>
#include <time.h>
#include "../../headers/monster/collision_monster.h"
#include "../../headers/monster/move_monster.h"
#include "../../headers/main/structs.h"
#include "../../headers/main/defines.h"
#include "../../headers/init/create_texture.h"


void get_collision_monster(Game *g, Monster *m, Map *map, int direction, int distance, Perso *p, int idMonster) {

// on recupere les coordonnées des cases adjacentes dans la map de collisions

    int caseGauche = map->quadmap[m->positionY + ((m->rect.h/TILESIZE) / 2)][m->positionX - 1];
    int caseDroite = map->quadmap[m->positionY + ((m->rect.h/TILESIZE) / 2)][(m->positionX + (m->rect.w/TILESIZE))];
    int caseHaut = map->quadmap[m->positionY - 1][m->positionX + ((m->rect.w/TILESIZE) / 2)];
    int caseBas = map->quadmap[m->positionY + (m->rect.h/TILESIZE) + 1][m->positionX + ((m->rect.w/TILESIZE) / 2)];

//
    switch(direction) {

        case LEFT:
        if(caseGauche == 0 && compare_monsters_collisions(m, map, direction, p, idMonster) == 0) make_move_monster(m, map, g, direction, p); // on envoie la case cible a fluid_move_monster pour deplacer le monstre
        break;

        case RIGHT:
        if(caseDroite == 0 && compare_monsters_collisions(m, map, direction, p, idMonster) == 0) make_move_monster(m, map, g, direction, p);
        break;

        case UP:
        if(caseHaut == 0 && compare_monsters_collisions(m, map, direction, p, idMonster) == 0) make_move_monster(m, map, g, direction, p);
        break;

        case DOWN:
        if(caseBas == 0 && compare_monsters_collisions(m, map, direction, p, idMonster) == 0) make_move_monster(m, map, g, direction, p);
        break;

        default:
        break;
    }
}


void get_position_monster(int idMonster, int distance, int direction, Map *map, Game *g, Perso *p) {

    Monster *m = map->monsters[idMonster]; 

    get_collision_monster(g, m, map, direction, distance, p, idMonster);

    m->positionX = (m->rect.x)/TILESIZE;
    m->positionY = (m->rect.y)/TILESIZE;
}

int compare_monsters_collisions(Monster *m, Map *map, int direction, Perso *p, int idMonster) {

    int xleft = m->positionX; 
    int ytop = m->positionY; 
    int xright = (m->positionX + (m->rect.w/TILESIZE)); // coordonnées du monstre à déplacer
    int ybottom = (m->positionY + (m->rect.h/TILESIZE));


    for(int i = 0; i < map->nbmonsters; i++) {

        Monster *currentM = map->monsters[i];

        if(idMonster != i) {

                int cmleftX = currentM->positionX;
                int cmtopY = currentM->positionY ;
                int cmrightX = currentM->positionX + (currentM->rect.w/TILESIZE); // coordonnées du monstre dans le tableau 
                int cmbottomY = currentM->positionY + (currentM->rect.h/TILESIZE);

            switch(direction) {

                        case LEFT:
                        if((xleft - 1) <= cmrightX) {
                            if(ytop == cmtopY || ybottom == cmbottomY) return 1;
                            else if(ytop == (cmtopY - 1) || ybottom == (cmbottomY + 1)) return 1;
                        }
                        break;

                        case RIGHT:
                        if((xright + 1) >= cmleftX) {
                            if(ytop == cmtopY || ybottom == cmbottomY) return 1;
                            else if(ytop == (cmtopY - 1) || ybottom == (cmbottomY + 1)) return 1;
                        }
                        break;

                        case UP:
                        if((ytop - 1) <= cmbottomY) {
                            if(xleft == cmleftX || xright == cmrightX) return 1;
                            else if(xleft == (cmleftX - 1) || xright == (cmrightX + 1)) return 1;
                        }
                        break;

                        case DOWN:
                        if((ybottom + 1) >= cmtopY) {
                            if(xleft == cmleftX || xright == cmrightX) return 1;
                            else if(xleft == (cmleftX - 1) || xright == (cmrightX + 1)) return 1;
                        }
                        break;

                        default:
                        break;
            }

        }
    }

    return 0;
}