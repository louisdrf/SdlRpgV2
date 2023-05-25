#include <SDL.h>
#include <string.h>
#include "../headers/loop.h"
#include "../headers/defines.h"
#include "../headers/move.h"
#include "../headers/create_texture.h"
#include "../headers/init_sprites.h"
#include "../headers/init_map.h"
#include "../headers/perso.h"

void launch_loop(Game *g, Perso *p, Map *m) {

    SDL_bool program_launched = SDL_TRUE;
    SDL_bool keyLeft = SDL_FALSE; 
    SDL_bool keyRight = SDL_FALSE;
    SDL_bool keyDown = SDL_FALSE;
    SDL_bool keyUp = SDL_FALSE;
    int lastAnimTime = 0;
    int delay_between_animations = DELAY_BETWEEN_ANIMATIONS;
    char *lastmove;


    p->currentSprite = "../img/perso/tileRight1.png";
    p->animation_index = 0;

    init_map(m); // découpe la carte en 4 rectangles
    print_image(g, m->currentMapPath, &(m->rect));
    print_image(g, p->currentSprite, &(p->rect));
    SDL_RenderPresent(g->renderer);



    while(program_launched) {

        SDL_Event event;   

        while(SDL_PollEvent(&event)) {

            switch(event.type) {

                case SDL_QUIT: 
                    program_launched = SDL_FALSE; 
                    break;

                case SDL_KEYUP:
                    if(keyLeft == SDL_TRUE) keyLeft = SDL_FALSE;
                    if(keyRight == SDL_TRUE) keyRight = SDL_FALSE;
                    if(keyDown == SDL_TRUE) keyDown = SDL_FALSE;
                    if(keyUp == SDL_TRUE) keyUp = SDL_FALSE; 
                    break;


                case SDL_KEYDOWN: 
                
                    switch(event.key.keysym.sym) { 

                                case SDLK_LEFT: 

                                        if(!strstr(lastmove, "left")) delay_between_animations = 0; // si on a changé de direction, le delai passe a 0
                                        if (SDL_GetTicks() - lastAnimTime >= delay_between_animations) {

                                                    get_position_perso(p, m);
                                                    move("left", &(p->rect), g, m->currentMapPath, &(m->rect), p);
                                                    SDL_RenderPresent(g->renderer);

                                                    lastAnimTime = SDL_GetTicks();
                                                    lastmove = "left";
                                                    if(delay_between_animations == 0) delay_between_animations = DELAY_BETWEEN_ANIMATIONS;
                                        }

                                break;

                                ///////////////////////////////////////////////

                                case SDLK_RIGHT: 

                                        if(!strstr(lastmove, "right")) delay_between_animations = 0; // si on a changé de direction, le delai passe a 0
                                        if (SDL_GetTicks() - lastAnimTime >= delay_between_animations) {

                                                    get_position_perso(p, m);
                                                    move("right", &(p->rect), g, m->currentMapPath, &(m->rect), p);
                                                    SDL_RenderPresent(g->renderer);
                                                    
                                                    lastAnimTime = SDL_GetTicks();
                                                    lastmove = "right";
                                                    if(delay_between_animations == 0) delay_between_animations = DELAY_BETWEEN_ANIMATIONS;
                                        }

                                break; 

                                ///////////////////////////////////////////////

                                case SDLK_UP: 

                                        if(!strstr(lastmove, "up")) delay_between_animations = 0; // si on a changé de direction, le delai passe a 0
                                        if (SDL_GetTicks() - lastAnimTime >= delay_between_animations) {

                                                    get_position_perso(p, m);
                                                    move("up", &(p->rect), g, m->currentMapPath, &(m->rect), p);
                                                    SDL_RenderPresent(g->renderer);

                                                    lastAnimTime = SDL_GetTicks();
                                                    lastmove = "up";
                                                    if(delay_between_animations == 0) delay_between_animations = DELAY_BETWEEN_ANIMATIONS;
                                        }   

                                break;

                                ///////////////////////////////////////////////

                                case SDLK_DOWN:

                                        if(!strstr(lastmove, "down")) delay_between_animations = 0;

                                        if (SDL_GetTicks() - lastAnimTime >= delay_between_animations) {

                                                    get_position_perso(p, m);
                                                    move("down", &(p->rect), g, m->currentMapPath, &(m->rect), p);
                                                    SDL_RenderPresent(g->renderer);

                                                    lastAnimTime = SDL_GetTicks();
                                                    lastmove = "down";
                                                    if(delay_between_animations == 0) delay_between_animations = DELAY_BETWEEN_ANIMATIONS;
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