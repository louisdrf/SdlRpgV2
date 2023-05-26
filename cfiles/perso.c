#include <SDL.h>
#include "../headers/perso.h"
#include "../headers/structs.h"

void get_position_perso(Perso *p, Map *m, char *direction) {

  get_collision(p, m, direction);

  p->positionX = (p->rect.x)/TILESIZE;
  p->positionY = (p->rect.y)/TILESIZE;

}


void get_collision(Perso *p, Map *m, char *direction) {

  // Y = ABSCISSE / X = ORDONNEE

    if(strstr(direction, "left")) {
          // on regarde le point au milieu à gauche du personnage par rapport au mur
          if(m->quadmap[p->positionY + (p->rect.h/TILESIZE)/2][p->positionX - 1] == 0) {

          p->rect.x -= p->speed;

          }
    }
      
    if(strstr(direction, "right")) {
      // on regarde le point au milieu à droite du personnage par rapport au mur
        if(m->quadmap[p->positionY + (p->rect.h/TILESIZE)/2][(p->positionX + (p->rect.w/TILESIZE))] != 0) {

          p->rect.x += p->speed;

        }
    }

    if(strstr(direction, "up")) {
      // on regarde le point en haut à gauche du personnage par rapport au mur
        if(m->quadmap[p->positionY - 1][p->positionX + (p->rect.w/TILESIZE)/2] != 0) {

          p->rect.y -= p->speed;
        } 
    }

    if(strstr(direction, "down")) {
        // on regarde le point au milieu bas du personnage par rapport au mur 
        if(m->quadmap[(p->positionY + (p->rect.h/TILESIZE))][p->positionX + (p->rect.w/TILESIZE)/2] != 0) {

          p->rect.y += p->speed;
        }

    }
}