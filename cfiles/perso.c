#include <SDL.h>
#include "../headers/perso.h"
#include "../headers/structs.h"
#include "../headers/move.h"
#include "../headers/create_texture.h"
#include "../headers/animation_sword.h"
#include "../headers/init_sprites_monster.h"


void get_position_perso(Perso *p, Globalmap *gmap, Game *g, char *direction) {

  get_collision(p, gmap, g, direction);

  p->positionX = (p->rect.x)/TILESIZE;
  p->positionY = (p->rect.y)/TILESIZE;

  printf("perso[%d][%d]\n", p->positionX, p->positionY);
}


void get_collision(Perso *p, Globalmap *gmap, Game *g, char *direction) {

  // Y = ABSCISSE / X = ORDONNEE
  Map *m = gmap->gmap[p->ymap][p->xmap]; // on recupere la map actuelle

    if(strstr(direction, "left")) {
          if(m->quadmap[p->positionY + (p->rect.h/TILESIZE)/2][p->positionX - 1] == 0) {

            if((p->positionX - NBMAPCUTS) <= 0) change_map(g, p, direction, gmap);
            else fluid_move(p, m, g, (p->positionX - 1), (p->positionY), "left"); // on envoie les targets a fluid_move pour découper le mouvement
          }
    }
    else if(strstr(direction, "right")) {
        if(m->quadmap[p->positionY + (p->rect.h/TILESIZE)/2][(p->positionX + (p->rect.w/TILESIZE))] == 0) {

          if((p->positionX + 1) == (NBTILES-NBMAPCUTS))  change_map(g, p, direction, gmap);
          else fluid_move(p, m, g, (p->positionX + 1), (p->positionY), "right");
        }
    }
    else if(strstr(direction, "up")) {
        if(m->quadmap[p->positionY - 1][p->positionX + (p->rect.w/TILESIZE)/2] == 0) {

            if((p->positionY - NBMAPCUTS) <= 0) change_map(g, p, direction, gmap);
            else fluid_move(p, m, g, p->positionX, (p->positionY - 1), "up");
        } 
    }
    else if(strstr(direction, "down")) {
        if(m->quadmap[(p->positionY + (p->rect.h/TILESIZE))][p->positionX + (p->rect.w/TILESIZE)/2] == 0) {

            if((p->positionY + NBMAPCUTS) == (NBTILES-1))  change_map(g, p, direction, gmap);
            else fluid_move(p, m, g, p->positionX, (p->positionY + 1), "down"); 
        }

    }
}


void attack(Game *g, Perso *p, Map *m, char *lastmove) {

  p->animation_index = 0;

    for(int i = 0; i<4; i++) {

              print_map(g, m);
              SDL_RenderCopy(g->renderer, animation_sword(p, lastmove), NULL, &(p->rectSword)); // animation_sword.c
              SDL_RenderPresent(g->renderer);
              p->animation_index += 1;
              SDL_Delay(30);
    }
    p->animation_index = 0;
}


void change_map(Game *g, Perso *p, char *direction, Globalmap *gmap) {
    if (strstr(direction, "left")) {
        p->xmap -= 1;
        p->rect.x = (SCREEN_W - (2 * (p->rect.w))); // on recale le perso à droite , vu qu'on va à gauche
    } else if (strstr(direction, "right")) {
        p->xmap += 1;
        p->rect.x = p->rect.w; // on recale le perso à gauche , vu qu'on va à droite
    } else if (strstr(direction, "up")) {
        p->ymap -= 1;
        p->rect.y = (SCREEN_H - (2 * (p->rect.h))); // on recale le perso en bas, vu qu'on va en haut
    } else if (strstr(direction, "down")) {
        p->ymap += 1;
        p->rect.y = p->rect.h; // on recale le perso en haut, vu qu'on va en bas
    }

    actualize_perso_movement(direction, g, p, gmap->gmap[p->ymap][p->xmap]);
    spawn_monsters(g, gmap->gmap[p->ymap][p->xmap]);
}