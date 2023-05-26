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


    p->currentSprite = "../img/link/linkRight1.png";
    p->animation_index = 0;

    print_image(g, m->currentMapPath, &(m->rect));
    print_image(g, p->currentSprite, &(p->rect));

    init_map(m, g); // découpe la carte en rectangles
    init_collisions(m, g); // initialise les collisions de la map

    SDL_RenderPresent(g->renderer);



    while(program_launched) {

        SDL_Event event;   

        while(SDL_PollEvent(&event)) {

            switch(event.type) {

                case SDL_QUIT: 
                    program_launched = SDL_FALSE; 
                    break;


                case SDL_KEYDOWN: 
                
                    switch(event.key.keysym.sym) { 

                                case SDLK_LEFT: 

                                        if(!strstr(lastmove, "left")) delay_between_animations = 0; // si on a changé de direction, le delai passe a 0
                                        if (SDL_GetTicks() - lastAnimTime >= delay_between_animations) {

                                                    move("left", g, p, m);

                                                    lastAnimTime = SDL_GetTicks();
                                                    lastmove = "left";
                                                    if(delay_between_animations == 0) delay_between_animations = DELAY_BETWEEN_ANIMATIONS;
                                        }

                                break;

                                ///////////////////////////////////////////////

                                case SDLK_RIGHT: 

                                        if(!strstr(lastmove, "right")) delay_between_animations = 0; // si on a changé de direction, le delai passe a 0
                                        if (SDL_GetTicks() - lastAnimTime >= delay_between_animations) {

                                                    move("right", g, p, m);
                                                    
                                                    lastAnimTime = SDL_GetTicks();
                                                    lastmove = "right";
                                                    if(delay_between_animations == 0) delay_between_animations = DELAY_BETWEEN_ANIMATIONS;
                                        }

                                break; 

                                ///////////////////////////////////////////////

                                case SDLK_UP: 

                                        if(!strstr(lastmove, "up")) delay_between_animations = 0; // si on a changé de direction, le delai passe a 0
                                        if (SDL_GetTicks() - lastAnimTime >= delay_between_animations) {

                                                    move("up", g, p, m);

                                                    lastAnimTime = SDL_GetTicks();
                                                    lastmove = "up";
                                                    if(delay_between_animations == 0) delay_between_animations = DELAY_BETWEEN_ANIMATIONS;
                                        }   

                                break;

                                ///////////////////////////////////////////////

                                case SDLK_DOWN:

                                        if(!strstr(lastmove, "down")) delay_between_animations = 0;

                                        if (SDL_GetTicks() - lastAnimTime >= delay_between_animations) {

                                                    move("down", g, p, m);

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