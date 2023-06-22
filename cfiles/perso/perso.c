#include <SDL.h>
#include "../../headers/perso/perso.h"
#include "../../headers/main/structs.h"
#include "../../headers/perso/move.h"
#include "../../headers/init/create_texture.h"
#include "../../headers/animation/animation_sword.h"
#include "../../headers/monster/spawn_monster.h"
#include "../../headers/monster/move_monster.h"

void refresh_position_persoXY(Perso *p) {

    p->positionX = (p->rect.x)/TILESIZE;
    p->positionY = (p->rect.y)/TILESIZE;
}

void get_position_perso(Perso *p, Globalmap *gmap, Game *g) {

     get_collision(p, gmap, g);
     refresh_position_persoXY(p);
}


void get_collision(Perso *p, Globalmap *gmap, Game *g) {

  // Y = ABSCISSE / X = ORDONNEE
  Map *m = gmap->gmap[p->ymap][p->xmap]; // on recupere la map actuelle

  int caseGauche = m->quadmap[p->positionY + (p->rect.h/TILESIZE)/2][p->positionX - 1];
  int caseDroite = m->quadmap[p->positionY + (p->rect.h/TILESIZE)/2][(p->positionX + (p->rect.w/TILESIZE))];
  int caseHaut = m->quadmap[p->positionY - 1][p->positionX + (p->rect.w/TILESIZE)/2];
  int caseBas = m->quadmap[(p->positionY + (p->rect.h/TILESIZE))][p->positionX + (p->rect.w/TILESIZE)/2];

        switch(p->direction) {

                        case LEFT:
                        if(caseGauche == 0) {
                                if((p->positionX - NBMAPCUTS) <= 0) change_map(g, p, gmap);
                                else fluid_move(p, m, g, (p->positionX - 1), (p->positionY)); 
                            }
                        break;

                        case RIGHT:
                        if(caseDroite == 0) {
                            if((p->positionX + 1) == (NBTILES-NBMAPCUTS))  change_map(g, p, gmap);
                            else fluid_move(p, m, g, (p->positionX + 1), (p->positionY));
                            }
                        break;

                        case UP:
                        if(caseHaut == 0) {
                                if((p->positionY - NBMAPCUTS) <= 0) change_map(g, p, gmap);
                                else fluid_move(p, m, g, p->positionX, (p->positionY - 1));
                            } 
                        break;

                        case DOWN:
                        if(caseBas == 0) {
                                if((p->positionY + NBMAPCUTS) == (NBTILES-1))  change_map(g, p, gmap);
                                else fluid_move(p, m, g, p->positionX, (p->positionY + 1));
                            }
                        break;

                default:
                break;
        }
}


void attack(Game *g, Perso *p, Map *m, int lastmove) {

    p->animation_index = 0;

            for(int i = 0; i<4; i++) {

                    print_map(g, m);
                    print_monsters(g, m);
                    SDL_RenderCopy(g->renderer, animation_sword(p, lastmove), NULL, &(p->rectSword)); // animation_sword.c
                    SDL_RenderPresent(g->renderer);
                    SDL_Delay(50);
                    p->animation_index += 1;
            }

    p->animation_index = 0;
}


void change_map(Game *g, Perso *p, Globalmap *gmap) {

    Map *m = gmap->gmap[p->ymap][p->xmap];

     switch(p->direction) {

                        case LEFT:
                        p->xmap -= 1;
                        p->rect.x = (SCREEN_W - (2 * (p->rect.w))); // on recale le perso à droite , vu qu'on va à gauche
                        m = gmap->gmap[p->ymap][p->xmap];
                        free_cell(p, m);
                        break;

                        case RIGHT:
                        p->xmap += 1;
                        p->rect.x = p->rect.w; // on recale le perso à gauche , vu qu'on va à droite
                        m = gmap->gmap[p->ymap][p->xmap];
                        free_cell(p, m);
                        break;

                        case UP:
                        p->ymap -= 1;
                        p->rect.y = (SCREEN_H - (2 * (p->rect.h))); // on recale le perso en bas, vu qu'on va en haut
                        m = gmap->gmap[p->ymap][p->xmap];
                        free_cell(p, m);
                        break;

                        case DOWN:
                        p->ymap += 1;
                        p->rect.y = p->rect.h; // on recale le perso en haut, vu qu'on va en bas
                        m = gmap->gmap[p->ymap][p->xmap];
                        free_cell(p, m);
                        break;

                default:
                break;
        }

    spawn_monsters(g, gmap->gmap[p->ymap][p->xmap]);
    actualize_perso_movement(g, p, gmap->gmap[p->ymap][p->xmap]);
}


void free_cell(Perso *p, Map *m) {

    switch(p->direction) {

        case LEFT:
        m->quadmap[p->positionY][p->positionX + 1] = 0;
        break;

        case RIGHT:
        m->quadmap[p->positionY][p->positionX - 1] = 0;
        break;

        case UP:
        m->quadmap[p->positionY + 1][p->positionX] = 0;
        break;

        case DOWN:
        m->quadmap[p->positionY - 1][p->positionX] = 0;
        break;

        default:
        break;
    }
}