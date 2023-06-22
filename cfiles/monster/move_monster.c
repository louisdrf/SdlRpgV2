#include <SDL.h>
#include <SDL_image.h>
#include <time.h>
#include "../../headers/monster/move_monster.h"
#include "../../headers/monster/collision_monster.h"
#include "../../headers/main/structs.h"
#include "../../headers/main/defines.h"
#include "../../headers/init/create_texture.h"


void print_monsters(Game *g, Map *map) {

    for (int i = 0; i < map->nbmonsters; i++) {

        Monster *currentMonster = map->monsters[i];
        SDL_Texture *currentTexture = currentMonster->animations_textures[currentMonster->direction][currentMonster->animation_index];

        SDL_RenderCopy(g->renderer, currentTexture, NULL, &(currentMonster->rect));           
    }
}

void move_monster(Game *g, Map *map, Perso *p) {
    
    srand(time(NULL));

    int nbMonsterToMove = rand() % map->nbmonsters;

   for (int i = 0; i < nbMonsterToMove; i++) {

        int idMonster = rand() % map->nbmonsters;
        Monster *currentMonster = map->monsters[idMonster];
        int distance = 1;
        int direction = rand() % 4;

        currentMonster->direction = direction;

        get_position_monster(idMonster, distance, map, g, p);
        currentMonster->animation_index += 1;
        if (currentMonster->animation_index >= 4)  currentMonster->animation_index = 0;
    }
            
}


void make_move_monster(Monster *m, Map *map, Game *g, Perso *p) {

        switch(m->direction) {

            case LEFT:
            m->rect.x -= TILESIZE;
            refresh_position_monsterXY(m);                // on actualise la position X et Y du monstre sur la map de collisions
            map->quadmap[m->positionY][m->positionX + 1] = 0; // l'ancienne case devient libre
            map->quadmap[m->positionY][m->positionX] = 1;
            break;

            case RIGHT:
            m->rect.x += TILESIZE;
            refresh_position_monsterXY(m);
            map->quadmap[m->positionY][m->positionX - 1] = 0;
            map->quadmap[m->positionY][m->positionX] = 1;
            break;

            case UP:
            m->rect.y -= TILESIZE;
            refresh_position_monsterXY(m);
            map->quadmap[m->positionY + 1][m->positionX] = 0; 
            map->quadmap[m->positionY][m->positionX] = 1;
            break;

            case DOWN:
            m->rect.y += TILESIZE;
            refresh_position_monsterXY(m);
            map->quadmap[m->positionY - 1][m->positionX] = 0; 
            map->quadmap[m->positionY][m->positionX] = 1;
            break;

            default:
            break;
        }
        
        SDL_RenderClear(g->renderer);
        print_map(g, map);
        print_image(g, p->animations[p->direction][p->animation_index], &(p->rect)); 
        print_monsters(g, map);
        SDL_RenderCopy(g->renderer, m->animations_textures[m->direction][m->animation_index], NULL, &(m->rect)); 
        SDL_RenderPresent(g->renderer);
    }





