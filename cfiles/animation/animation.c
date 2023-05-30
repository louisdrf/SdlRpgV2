#include <SDL.h>
#include <SDL_image.h>
#include <string.h>
#include "../../headers/animation/animation.h"


SDL_Texture *animation_perso(Perso *p, int direction) {

     switch(direction) {

                        case LEFT:
                                switch(p->animation_index) {

                                        case 0: return p->animations_textures[0][0];
                                        case 1: return p->animations_textures[0][1];
                                        case 2: return p->animations_textures[0][2];
                                        case 3: return p->animations_textures[0][3];
                                        
                                default:
                                return NULL;
                                }
                        break;

                        case RIGHT:
                                switch(p->animation_index) {

                                        case 0: return p->animations_textures[1][0];
                                        case 1: return p->animations_textures[1][1];
                                        case 2: return p->animations_textures[1][2];
                                        case 3: return p->animations_textures[1][3];

                                default:
                                return NULL;
                                  }   
                        break;

                        case UP:
                                switch(p->animation_index) {

                                        case 0: return p->animations_textures[2][0];
                                        case 1: return p->animations_textures[2][1];
                                        case 2: return p->animations_textures[2][2];
                                        case 3: return p->animations_textures[2][3];
                                        
                                default:
                                return NULL;
                                }
                        break;

                        case DOWN:
                                switch(p->animation_index) {

                                        case 0: return p->animations_textures[3][0];
                                        case 1: return p->animations_textures[3][1];
                                        case 2: return p->animations_textures[3][2];
                                        case 3: return p->animations_textures[3][3];
                                       
                                default:
                                return NULL;
                                }
                        break;

        default:
        break;
        }

    return NULL;
}