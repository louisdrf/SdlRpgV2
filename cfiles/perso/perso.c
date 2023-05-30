#include <SDL.h>
#include "../../headers/perso/perso.h"
#include "../../headers/main/structs.h"
#include "../../headers/perso/move.h"
#include "../../headers/init/create_texture.h"
#include "../../headers/animation/animation_sword.h"
#include "../../headers/monster/monster.h"

void get_position_perso(Perso *p, Globalmap *gmap, Game *g, int direction) {

  get_collision(p, gmap, g, direction);

  p->positionX = (p->rect.x)/TILESIZE;
  p->positionY = (p->rect.y)/TILESIZE;

  //printf("perso[%d][%d]\n", p->positionX, p->positionY);
}


void get_collision(Perso *p, Globalmap *gmap, Game *g, int direction) {

  // Y = ABSCISSE / X = ORDONNEE
  Map *m = gmap->gmap[p->ymap][p->xmap]; // on recupere la map actuelle

  int caseGauche = m->quadmap[p->positionY + (p->rect.h/TILESIZE)/2][p->positionX - 1];
  int caseDroite = m->quadmap[p->positionY + (p->rect.h/TILESIZE)/2][(p->positionX + (p->rect.w/TILESIZE))];
  int caseHaut = m->quadmap[p->positionY - 1][p->positionX + (p->rect.w/TILESIZE)/2];
  int caseBas = m->quadmap[(p->positionY + (p->rect.h/TILESIZE))][p->positionX + (p->rect.w/TILESIZE)/2];

        switch(direction) {

                        case LEFT:
                        if(caseGauche == 0) {
                                if((p->positionX - NBMAPCUTS) <= 0) change_map(g, p, direction, gmap);
                                else fluid_move(p, m, g, (p->positionX - 1), (p->positionY), direction); // on envoie les targets a fluid_move pour découper le mouvement
                            }
                        break;

                        case RIGHT:
                        if(caseDroite == 0) {
                            if((p->positionX + 1) == (NBTILES-NBMAPCUTS))  change_map(g, p, direction, gmap);
                            else fluid_move(p, m, g, (p->positionX + 1), (p->positionY), direction);
                            }
                        break;

                        case UP:
                        if(caseHaut == 0) {
                                if((p->positionY - NBMAPCUTS) <= 0) change_map(g, p, direction, gmap);
                                else fluid_move(p, m, g, p->positionX, (p->positionY - 1), direction);
                            } 
                        break;

                        case DOWN:
                        if(caseBas == 0) {
                                if((p->positionY + NBMAPCUTS) == (NBTILES-1))  change_map(g, p, direction, gmap);
                                else fluid_move(p, m, g, p->positionX, (p->positionY + 1), direction); 
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
              SDL_RenderCopy(g->renderer, animation_sword(p, lastmove), NULL, &(p->rectSword)); // animation_sword.c
              SDL_RenderPresent(g->renderer);
              SDL_Delay(50);
              p->animation_index += 1;
    }

    p->animation_index = 0;
}


void change_map(Game *g, Perso *p, int direction, Globalmap *gmap) {

     switch(direction) {

                        case LEFT:
                        p->xmap -= 1;
                        p->rect.x = (SCREEN_W - (2 * (p->rect.w))); // on recale le perso à droite , vu qu'on va à gauche
                        break;

                        case RIGHT:
                        p->xmap += 1;
                        p->rect.x = p->rect.w; // on recale le perso à gauche , vu qu'on va à droite
                        break;

                        case UP:
                        p->ymap -= 1;
                        p->rect.y = (SCREEN_H - (2 * (p->rect.h))); // on recale le perso en bas, vu qu'on va en haut
                        break;

                        case DOWN:
                        p->ymap += 1;
                        p->rect.y = p->rect.h; // on recale le perso en haut, vu qu'on va en bas
                        break;

                default:
                break;
        }

    actualize_perso_movement(direction, g, p, gmap->gmap[p->ymap][p->xmap]);
    spawn_monsters(g, gmap->gmap[p->ymap][p->xmap]);
}