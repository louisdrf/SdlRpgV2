#include <SDL.h>
#include <string.h>
#include "../headers/loop.h"
#include "../headers/defines.h"
#include "../headers/move.h"
#include "../headers/create_texture.h"
#include "../headers/init_sprites.h"


void launch_loop(Game *g, Perso *p) {

    SDL_bool program_launched = SDL_TRUE;

    Map currentMap; 

    currentMap.x = 0;
    currentMap.y = 0;
    currentMap.currentMapPath = "../img/maps/map00.png";
    SDL_Rect mapRect = {0, 0, SCREEN_H, SCREEN_W};
    SDL_Rect *pmapRect = &mapRect;

    p->currentSprite = "../img/perso/tileRight1.png";
    p->animation_index = 0;

    
    
    print_image(g, currentMap.currentMapPath, pmapRect);
    print_image(g, p->currentSprite, &(p->rect));
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

                                    move("left", PERSO_SPEED, &(p->rect), g, currentMap.currentMapPath, pmapRect, p);
                                    SDL_RenderPresent(g->renderer);

                                break;

                                ///////////////////////////////////////////////

                                case SDLK_RIGHT: 
                                
                                    move("right", PERSO_SPEED, &(p->rect), g, currentMap.currentMapPath, pmapRect, p);
                                    SDL_RenderPresent(g->renderer);

                                break; 

                                ///////////////////////////////////////////////

                                case SDLK_UP: 

                                    move("up", PERSO_SPEED, &(p->rect), g, currentMap.currentMapPath, pmapRect, p);
                                    SDL_RenderPresent(g->renderer);   

                                break;

                                ///////////////////////////////////////////////

                                case SDLK_DOWN:

                                    move("down", PERSO_SPEED, &(p->rect), g, currentMap.currentMapPath, pmapRect, p);
                                    SDL_RenderPresent(g->renderer);

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