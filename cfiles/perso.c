#include <SDL.h>
#include "../headers/perso.h"
#include "../headers/structs.h"
#include "../headers/move.h"

void get_position_perso(Perso *p, Map *m, Game *g, char *direction) {

  get_collision(p, m, g, direction);

  p->positionX = (p->rect.x)/TILESIZE;
  p->positionY = (p->rect.y)/TILESIZE;

}


void get_collision(Perso *p, Map *m, Game *g, char *direction) {

  // Y = ABSCISSE / X = ORDONNEE

    if(strstr(direction, "left")) {
          // on regarde le point au milieu à gauche du personnage par rapport au mur
          if(m->quadmap[p->positionY + (p->rect.h/TILESIZE)/2][p->positionX - 1] == 0) {

            fluid_move(p, m, g, (p->positionX - 1), (p->positionY), "left"); // on envoie les targets a fluid_move pour découper le mouvement
          }
    }
      
    else if(strstr(direction, "right")) {
      // on regarde le point au milieu à droite du personnage par rapport au mur
        if(m->quadmap[p->positionY + (p->rect.h/TILESIZE)/2][(p->positionX + (p->rect.w/TILESIZE))] == 0) {

          fluid_move(p, m, g, (p->positionX + 1), (p->positionY), "right");
        }
    }

    else if(strstr(direction, "up")) {
      // on regarde le point en haut à gauche du personnage par rapport au mur
        if(m->quadmap[p->positionY - 1][p->positionX + (p->rect.w/TILESIZE)/2] == 0) {

          fluid_move(p, m, g, p->positionX, (p->positionY - 1), "up");
        } 
    }

    else if(strstr(direction, "down")) {
        // on regarde le point au milieu bas du personnage par rapport au mur 
        if(m->quadmap[(p->positionY + (p->rect.h/TILESIZE))][p->positionX + (p->rect.w/TILESIZE)/2] == 0) {

          fluid_move(p, m, g, p->positionX, (p->positionY + 1), "down");
        }

    }
}