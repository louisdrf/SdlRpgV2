#include <SDL.h>
#include <stdbool.h>
#include "../../headers/perso/attack.h"
#include "../../headers/main/structs.h"
#include "../../headers/perso/move.h"
#include "../../headers/init/create_texture.h"
#include "../../headers/animation/animation_sword.h"
#include "../../headers/monster/move_monster.h"


void attack(Game *g, Perso *p, Map *m, int lastmove) {

    if(does_attack_touch(p, m)) {

        Monster *touchedMonster = get_touched_monster(m, p);

        if(touchedMonster != NULL) 
        {
            touchedMonster->lifepoints -= p->damage;
        }

                if(touchedMonster->lifepoints <= 0) 
                {
                    touchedMonster->isAlive = false;
                    m->quadmap[touchedMonster->positionY][touchedMonster->positionX] = 0; // on tue le monstre et on le fait disparaitre de la carte
                }
    }

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

bool does_attack_touch(Perso *p, Map *m) {

    int caseGauche = m->quadmap[p->positionY][p->positionX - 1];
    int caseDroite = m->quadmap[p->positionY][p->positionX + 1];
    int caseHaut = m->quadmap[p->positionY - 1][p->positionX];
    int caseBas = m->quadmap[p->positionY + 1][p->positionX];
    
    switch(p->lastmove) {

        case LEFT:
        if(caseGauche == 2) return true; // la case de la map vaut 2 si un monstre est dessus
        break;

        case RIGHT:
        if(caseDroite == 2) return true;
        break;

        case UP:
        if(caseHaut == 2) return true;
        break;

        case DOWN:
        if(caseBas == 2) return true;
        break;
    }

    return false;
}


Monster *get_touched_monster(Map *m, Perso *p) {

    int targetX = p->positionX;
    int targetY = p->positionY;

    switch(p->lastmove) {

            case LEFT:
                targetX -= 1;
                break;

            case RIGHT:
                targetX += 1;
                break;

            case UP:
                targetY -= 1;
                break;

            case DOWN:
                targetY += 1;
                break;
    }

    for (int i = 0; i < m->nbmonsters; i++) {
        Monster *currentMonster = m->monsters[i];
        if (currentMonster->positionX == targetX && currentMonster->positionY == targetY) {
            return currentMonster;
        }
    }

    return NULL; 
}