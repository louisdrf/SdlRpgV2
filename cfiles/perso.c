#include <SDL.h>
#include "../headers/perso.h"
#include "../headers/structs.h"

void get_position_perso(Perso *p, Map *m, char *direction) {

  p->positionX = (p->rect.x)/TILESIZE;
  p->positionY = (p->rect.y)/TILESIZE;

    printf("position perso[%d][%d]\n", p->positionX , p->positionY);

  get_collision(p, m, direction);

}


void get_collision(Perso *p, Map *m, char *direction) {

    if(strstr(direction, "left")) {

        if(m->quadmap[p->positionY][p->positionX - 1] != 0) {
          printf("collision gauche\n");
        } 
        else {
          p->rect.x -= p->speed;
        }
    }

    if(strstr(direction, "right")) {

        if(m->quadmap[p->positionY][p->positionX + 1] != 0) {
          printf("collision droite\n");
        }
        else {
          p->rect.x += p->speed;
        }
    }

    if(strstr(direction, "up")) {

        if(m->quadmap[p->positionY - 1][p->positionX] != 0) {
          printf("collision haut\n");
        } 
        else {
           p->rect.y -= p->speed;
        }
    }

    if(strstr(direction, "down")) {

        if(m->quadmap[p->positionY + 1][p->positionX] != 0) {
          printf("collision bas\n");
        }
        else {
          p->rect.y += p->speed;
        }
    }
}