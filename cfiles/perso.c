#include <SDL.h>
#include "../headers/perso.h"
#include "../headers/structs.h"

void get_position_perso(Perso *p, Map *m) {

    printf("position perso[%d][%d]\n", (p->rect.x + p->rect.w) , (p->rect.y + p->rect.h));

    /*if((p->rect.x + p->rect.w) <= (m->parts[0][0].x + m->parts[0][0].w) 
    && (p->rect.y + p->rect.h) <= (m->parts[0][0].y + m->parts[0][0].h)) {
            printf("part 1\n");
    } 
    if((p->rect.x + p->rect.w) <= (m->parts[1][0].x + m->parts[1][0].w) 
    && (p->rect.y + p->rect.h) <= (m->parts[1][0].y + m->parts[1][0].h)) {
            printf("part 2\n");
    }
    if((p->rect.x + p->rect.w) <= (m->parts[0][1].x + m->parts[0][1].w) 
    && (p->rect.y + p->rect.h) <= (m->parts[0][1].y + m->parts[0][1].h)) {
            printf("part 3\n");
    } 
    if((p->rect.x + p->rect.w) <= (m->parts[1][1].x + m->parts[1][1].w) 
    && (p->rect.y + p->rect.h) <= (m->parts[1][1].y + m->parts[1][1].h)) {
            printf("part 4\n");
    } */
}