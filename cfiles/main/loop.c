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
    
    Uint32 lastAnimTime = 0;
    Uint32 lastAttackTime = 0;
    Uint32 lastMoveMonsterTime = 0;
    Uint8 delay_between_animations = DELAY_BETWEEN_ANIMATIONS;
    Uint8 delay_between_attacks = DELAY_BETWEEN_ATTACKS;

    int lastmove = RIGHT;

    Map *m = gmap->gmap[p->ymap][p->xmap]; // on recupere l'adresse de la map actuelle    

    print_map(g, m); // affichage map
    print_image(g, p->currentSprite, &(p->rect));  // affichage perso
    spawn_monsters(g, m); // spawn des monstres
    SDL_RenderPresent(g->renderer);

    

    while(program_launched) {

        SDL_Event event; 

        m = gmap->gmap[p->ymap][p->xmap];

            // Déplacer les monstres
            if (SDL_GetTicks() - lastMoveMonsterTime >= DELAY_MOVE_MONSTER) {  
                move_monster(g, m, p);
                lastMoveMonsterTime = SDL_GetTicks();
            }

                    while(SDL_PollEvent(&event)) {

                        switch(event.type) {

                            case SDL_QUIT: 
                                program_launched = SDL_FALSE; 
                                break;

                            case SDL_KEYDOWN: 
                            
                                switch(event.key.keysym.sym) { 

                                            case SDLK_LEFT: 
                                            p->direction = LEFT;

                                                if(lastmove != LEFT) delay_between_animations = 0; // si on a changé de direction, le delai passe a 0
                                                if (SDL_GetTicks() - lastAnimTime >= delay_between_animations) {

                                                                move(LEFT, g, p, gmap);
                                                                lastAnimTime = SDL_GetTicks();
                                                                lastmove = LEFT;
                                                                if(delay_between_animations == 0) delay_between_animations = DELAY_BETWEEN_ANIMATIONS;
                                                    }

                                            break;

                                            ///////////////////////////////////////////////

                                            case SDLK_RIGHT: 
                                            p->direction = RIGHT;

                                                    if(lastmove != RIGHT) delay_between_animations = 0; // si on a changé de direction, le delai passe a 0
                                                    if (SDL_GetTicks() - lastAnimTime >= delay_between_animations) {

                                                                move(RIGHT, g, p, gmap);
                                                                lastAnimTime = SDL_GetTicks();
                                                                lastmove = RIGHT;
                                                                if(delay_between_animations == 0) delay_between_animations = DELAY_BETWEEN_ANIMATIONS;
                                                    }

                                            break; 

                                            ///////////////////////////////////////////////

                                            case SDLK_UP:
                                            p->direction = UP;

                                                    if(lastmove != UP) delay_between_animations = 0; // si on a changé de direction, le delai passe a 0
                                                    if (SDL_GetTicks() - lastAnimTime >= delay_between_animations) {

                                                                move(UP, g, p, gmap);
                                                                lastAnimTime = SDL_GetTicks();
                                                                lastmove = UP;
                                                                if(delay_between_animations == 0) delay_between_animations = DELAY_BETWEEN_ANIMATIONS;
                                                    }   

                                            break;

                                            ///////////////////////////////////////////////

                                            case SDLK_DOWN:
                                            p->direction = DOWN;

                                                    if(lastmove != DOWN) delay_between_animations = 0;
                                                    if (SDL_GetTicks() - lastAnimTime >= delay_between_animations) {

                                                                move(DOWN, g, p, gmap);
                                                                lastAnimTime = SDL_GetTicks();
                                                                lastmove = DOWN;
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