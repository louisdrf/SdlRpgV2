#include <SDL.h>
#include <SDL_image.h>
#include <string.h>
#include "../headers/animation.h"


char *animation_perso(Perso *p, char *direction) {

    if(strstr(direction, "left")) {

        switch(p->animation_index) {

            case 0:
            return p->animations[0][0];
            break;

            case 1:
            return p->animations[0][1];
            break;

            case 2:
            return p->animations[0][2];
            break;

            case 3:
            p->animation_index = 0;
            return p->animations[0][3];
            break;

            default:
            break;
        }

    }
    if(strstr(direction, "right")) {

        switch(p->animation_index) {

            case 0:
            return p->animations[1][0];
            break;

            case 1:
            return p->animations[1][1];
            break;

            case 2:
            return p->animations[1][2];
            break;

            case 3:
            p->animation_index = 0;
            return p->animations[1][3];
            break;

            default:
            break;
        }
        
    }
    if(strstr(direction, "up")) {

        switch(p->animation_index) {

            case 0:
            return p->animations[2][0];
            break;

            case 1:
            return p->animations[2][1];
            break;

            case 2:
            return p->animations[2][2];
            break;

            case 3:
            p->animation_index = 0;
            return p->animations[2][3];
            break;

            default:
            break;
        }
        
    }
    if(strstr(direction, "down")) {

        switch(p->animation_index) {

            case 0:
            return p->animations[3][0];
            break;

            case 1:
            return p->animations[3][1];
            break;

            case 2:
            return p->animations[3][2];
            break;

            case 3:
            p->animation_index = 0;
            return p->animations[3][3];
            break;

            default:
            break;
        }
        
    }

}