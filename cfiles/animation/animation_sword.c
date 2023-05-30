#include <SDL.h>
#include <SDL_image.h>
#include <string.h>
#include "../../headers/animation/animation_sword.h"


SDL_Texture *animation_sword(Perso *p, int direction) {

    switch(direction) {

                        case LEFT:
                                switch(p->animation_index) {

                                        case 0: return p->animations_textures[4][0];
                                        case 1: return p->animations_textures[4][1];
                                        case 2: return p->animations_textures[4][2];
                                        case 3: return p->animations_textures[4][3];
                                        
                                default:
                                return NULL;
                                }
                        break;

                        case RIGHT:
                                switch(p->animation_index) {

                                        case 0: return p->animations_textures[5][0];
                                        case 1: return p->animations_textures[5][1];
                                        case 2: return p->animations_textures[5][2];
                                        case 3: return p->animations_textures[5][3];

                                default:
                                return NULL;
                                  }   
                        break;

                        case UP:
                                switch(p->animation_index) {

                                        case 0: return p->animations_textures[6][0];
                                        case 1: return p->animations_textures[6][1];
                                        case 2: return p->animations_textures[6][2];
                                        case 3: return p->animations_textures[6][3];
                                        
                                default:
                                return NULL;
                                }
                        break;

                        case DOWN:
                                switch(p->animation_index) {

                                        case 0: return p->animations_textures[7][0];
                                        case 1: return p->animations_textures[7][1];
                                        case 2: return p->animations_textures[7][2];
                                        case 3: return p->animations_textures[7][3];
                                       
                                 default:
                                return NULL;
                                }
                        break;

        default:
        break;
        }

    return NULL;
}