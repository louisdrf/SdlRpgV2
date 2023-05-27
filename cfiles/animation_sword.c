#include <SDL.h>
#include <SDL_image.h>
#include <string.h>
#include "../headers/animation_sword.h"


SDL_Texture *animation_sword(Perso *p, char *direction) {

    if(strstr(direction, "left")) {

        switch(p->animation_index) {

            case 0:
            return p->animations_textures[4][0];
            break;
            case 1:
            return p->animations_textures[4][1];
            break;
            case 2:
            return p->animations_textures[4][2];
            break;
            case 3:
            return p->animations_textures[4][3];
            break;

            default:
            break;
        }

    }
    else if(strstr(direction, "right")) {

        switch(p->animation_index) {

            case 0:
            return p->animations_textures[5][0];
            break;
            case 1:
            return p->animations_textures[5][1];
            break;
            case 2:
            return p->animations_textures[5][2];
            break;
            case 3:
            return p->animations_textures[5][3];
            break;
            default:
            break;
        }
        
    }
    else if(strstr(direction, "up")) {

        switch(p->animation_index) {

            case 0:
            return p->animations_textures[6][0];
            break;
            case 1:
            return p->animations_textures[6][1];
            break;
            case 2:
            return p->animations_textures[6][2];
            break;
            case 3:
            return p->animations_textures[6][3];
            break;
            default:
            break;
        }
        
    }
    else if(strstr(direction, "down")) {

        switch(p->animation_index) {

            case 0:
            return p->animations_textures[7][0];
            break;
            case 1:
            return p->animations_textures[7][1];
            break;
            case 2:
            return p->animations_textures[7][2];
            break;
            case 3:
            return p->animations_textures[7][3];
            break;

            default:
            break;
        }
        
    }

}