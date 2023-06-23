#include <SDL.h>
#include <string.h>
#include "../../headers/main/loop.h"
#include "../../headers/main/defines.h"
#include "../../headers/perso/move.h"
#include "../../headers/init/create_texture.h"
#include "../../headers/perso/init_sprites.h"
#include "../../headers/monster/spawn_monster.h"
#include "../../headers/monster/move_monster.h"
#include "../../headers/init/init_map.h"
#include "../../headers/perso/perso.h"




void launch_loop(Game *g, Perso *p, Globalmap *gmap) {

    SDL_bool program_launched = SDL_TRUE;
    Uint32 lastMoveMonsterTime = 0;

    Map *m = gmap->gmap[p->ymap][p->xmap]; // on recupere l'adresse de la map actuelle
    
    print_map(g, m); // affichage map
    print_image(g, p->currentSprite, &(p->rect));  // affichage perso
    spawn_monsters(g, m); // spawn des monstres
    SDL_RenderPresent(g->renderer);

    
    while(program_launched) {

        m = gmap->gmap[p->ymap][p->xmap];

        SDL_Event event; 

            if ((SDL_GetTicks() - lastMoveMonsterTime) >= DELAY_MOVE_MONSTER) {  
                move_monster(g, m, p);
                lastMoveMonsterTime = SDL_GetTicks();
            }

                    while(SDL_PollEvent(&event)) {

                        switch(event.type) {

                            case SDL_QUIT: 
                                program_launched = SDL_FALSE; 
                                break;


                            case SDL_KEYDOWN: 
                            p->rectSword.x = p->rect.x;
                            p->rectSword.y = p->rect.y;

                            
                                switch(event.key.keysym.sym) { 

                                            case SDLK_LEFT: 
                                                        p->direction = LEFT;
                                                        timed_move(p, g, gmap, LEFT);
                                                        free_last_cell(p, m);
                                            break;

                                            case SDLK_RIGHT: 
                                                        p->direction = RIGHT;
                                                        timed_move(p, g, gmap, RIGHT);
                                                        free_last_cell(p, m);
                                            break; 

                                            case SDLK_UP:
                                                        p->direction = UP;
                                                        timed_move(p, g, gmap, UP);
                                                        free_last_cell(p, m);
                                            break;

                                            case SDLK_DOWN:
                                                        p->direction = DOWN;
                                                        timed_move(p, g, gmap, DOWN);
                                                        free_last_cell(p, m);
                                            break;
                                            

                                            case SDLK_s: 

                                                    if (SDL_GetTicks() - p->lastAttackTime >= p->delay_between_attacks) {

                                                                        attack(g, p, m, p->lastmove); // perso.c
                                                                        p->lastAttackTime = SDL_GetTicks();
                                                                        if(p->delay_between_attacks == 0) p->delay_between_attacks = DELAY_BETWEEN_ATTACKS;
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


