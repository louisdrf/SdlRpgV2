#include <SDL.h>
#include <SDL_image.h>
#include <string.h>
#include "../headers/animation.h"


SDL_Texture *animation_perso(Perso *p, char *direction) {

    if(strstr(direction, "left")) {

        switch(p->animation_index) {

            case 0:
            return p->animations_textures[0][0];
            break;
            case 1:
            return p->animations_textures[0][1];
            break;
            case 2:
            return p->animations_textures[0][2];
            break;
            case 3:
            return p->animations_textures[0][3];
            break;

            default:
            break;
        }

    }
    if(strstr(direction, "right")) {

        switch(p->animation_index) {

            case 0:
            return p->animations_textures[1][0];
            break;
            case 1:
            return p->animations_textures[1][1];
            break;
            case 2:
            return p->animations_textures[1][2];
            break;
            case 3:
            return p->animations_textures[1][3];
            break;
            default:
            break;
        }
        
    }
    if(strstr(direction, "up")) {

        switch(p->animation_index) {

            case 0:
            return p->animations_textures[2][0];
            break;
            case 1:
            return p->animations_textures[2][1];
            break;
            case 2:
            return p->animations_textures[2][2];
            break;
            case 3:
            return p->animations_textures[2][3];
            break;
            default:
            break;
        }
        
    }
    if(strstr(direction, "down")) {

        switch(p->animation_index) {

            case 0:
            return p->animations_textures[3][0];
            break;
            case 1:
            return p->animations_textures[3][1];
            break;
            case 2:
            return p->animations_textures[3][2];
            break;
            case 3:
            return p->animations_textures[3][3];
            break;

            default:
            break;
        }
        
    }

}