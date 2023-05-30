#include <SDL.h>
#include <string.h>
#include "../../headers/main/loop.h"
#include "../../headers/main/defines.h"
#include "../../headers/perso/move.h"
#include "../../headers/init/create_texture.h"
#include "../../headers/perso/init_sprites.h"
#include "../../headers/monster/monster.h"
#include "../../headers/init/init_map.h"
#include "../../headers/perso/perso.h"




void launch_loop(Game *g, Perso *p, Globalmap *gmap) {

    SDL_bool program_launched = SDL_TRUE;
    
    Uint32 lastAnimTime = 0;
    Uint32 lastAttackTime = 0;
    Uint8 delay_between_animations = DELAY_BETWEEN_ANIMATIONS;
    Uint8 delay_between_attacks = DELAY_BETWEEN_ATTACKS;

    char *lastmove;
    lastmove = "right";

    Map *m = gmap->gmap[p->ymap][p->xmap]; // on recupere l'adresse de la map actuelle    

    print_map(g, m); // affichage map
    print_image(g, p->currentSprite, &(p->rect));  // affichage perso
    spawn_monsters(g, m); // spawn des monstres
    SDL_RenderPresent(g->renderer);

    

    while(program_launched) {

        SDL_Event event;   

        while(SDL_PollEvent(&event)) {

            p->rectSword.x = p->rect.x;
            p->rectSword.y = p->rect.y;

            switch(event.type) {

                case SDL_QUIT: 
                    program_launched = SDL_FALSE; 
                    break;

                case SDL_KEYDOWN: 
                
                    switch(event.key.keysym.sym) { 

                                case SDLK_LEFT: 

                                       if(!strstr(lastmove, "left")) delay_between_animations = 0; // si on a changé de direction, le delai passe a 0
                                       if (SDL_GetTicks() - lastAnimTime >= delay_between_animations) {

                                                    move("left", g, p, gmap);

                                                    lastAnimTime = SDL_GetTicks();
                                                    lastmove = "left";
                                                    if(delay_between_animations == 0) delay_between_animations = DELAY_BETWEEN_ANIMATIONS;
                                        }

                                break;

                                ///////////////////////////////////////////////

                                case SDLK_RIGHT: 

                                        if(!strstr(lastmove, "right")) delay_between_animations = 0; // si on a changé de direction, le delai passe a 0
                                        if (SDL_GetTicks() - lastAnimTime >= delay_between_animations) {

                                                    move("right", g, p, gmap);
                                                    
                                                    lastAnimTime = SDL_GetTicks();
                                                    lastmove = "right";
                                                    if(delay_between_animations == 0) delay_between_animations = DELAY_BETWEEN_ANIMATIONS;
                                        }

                                break; 

                                ///////////////////////////////////////////////

                                case SDLK_UP:

                                        if(!strstr(lastmove, "up")) delay_between_animations = 0; // si on a changé de direction, le delai passe a 0
                                        if (SDL_GetTicks() - lastAnimTime >= delay_between_animations) {

                                                    move("up", g, p, gmap);

                                                    lastAnimTime = SDL_GetTicks();
                                                    lastmove = "up";
                                                    if(delay_between_animations == 0) delay_between_animations = DELAY_BETWEEN_ANIMATIONS;
                                        }   

                                break;

                                ///////////////////////////////////////////////

                                case SDLK_DOWN:

                                        if(!strstr(lastmove, "down")) delay_between_animations = 0;
                                        if (SDL_GetTicks() - lastAnimTime >= delay_between_animations) {

                                                    move("down", g, p, gmap);
                                                    lastAnimTime = SDL_GetTicks();
                                                    lastmove = "down";
                                                    if(delay_between_animations == 0) delay_between_animations = DELAY_BETWEEN_ANIMATIONS;
                                        }
                                break;


                                case SDLK_s: 

                                        if (SDL_GetTicks() - lastAttackTime >= delay_between_attacks) {

                                                            attack(g, p, m, lastmove); // perso.c
                                                            lastAttackTime = SDL_GetTicks();
                                                            if(delay_between_attacks == 0) delay_between_attacks = DELAY_BETWEEN_ATTACKS;
                                                }
                                break;

                                ///////////////////////////////////////////////
                                
                                default:
                                break;
                    } // fin switch event.key
                default:
                break;
            } // fin switch event.type  
        } // fin while SDL_PollEvent   
 
    } //fin de program_launched

}