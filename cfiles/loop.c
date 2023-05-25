#include <SDL.h>
#include <string.h>
#include "../headers/loop.h"
#include "../headers/defines.h"
#include "../headers/move.h"
#include "../headers/create_texture.h"
#include "../headers/init_sprites.h"


void launch_loop(Game *g, Perso *p) {

    SDL_bool program_launched = SDL_TRUE;
    SDL_Rect backgroundRect = {0, 0, SCREEN_H, SCREEN_W};
    SDL_Rect *pbackgroundRect = &backgroundRect;
    char *imgmap00 = "../img/maps/map00.png";
    char *currentmap = "00";



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

                                    move("left", PERSO_SPEED, &(p->rect), g, p->sprites[0], currentmap, pbackgroundRect);

                                    SDL_RenderPresent(g->renderer);
                                break;

                                ///////////////////////////////////////////////

                                case SDLK_RIGHT: 

                                    move("right", PERSO_SPEED, &(p->rect), g, p->sprites[1], currentmap, pbackgroundRect);

                                    SDL_RenderPresent(g->renderer);
                                break; 

                                ///////////////////////////////////////////////

                                case SDLK_UP: 

                                    move("up", PERSO_SPEED, &(p->rect), g, p->sprites[2], currentmap, pbackgroundRect);

                                    SDL_RenderPresent(g->renderer);                           
                                break;

                                ///////////////////////////////////////////////

                                case SDLK_DOWN:

                                    move("down", PERSO_SPEED, &(p->rect), g, p->sprites[3], currentmap, pbackgroundRect);

                                    SDL_RenderPresent(g->renderer);
                                break;

                                ///////////////////////////////////////////////
                                
                            
                                default:
                                break;
                    } // fin switch event.key
                default:
                break;
            } // fin swtich event.type  
        } // fin while SDL_PollEvent 

    } //fin de program_launched

}