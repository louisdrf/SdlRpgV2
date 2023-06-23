#include <SDL.h>
#include <SDL_image.h>
#include <time.h>
#include "../../headers/monster/move_monster.h"
#include "../../headers/main/structs.h"
#include "../../headers/main/defines.h"
#include "../../headers/init/create_texture.h"


void print_monsters(Game *g, Map *map) {

    for (int i = 0; i < map->nbmonsters; i++) {

        Monster *currentMonster = map->monsters[i];
        int direction = currentMonster->direction;
        int animation = currentMonster->animation_index;

        SDL_Texture *currentTexture = currentMonster->animations_textures[direction][animation];
        SDL_RenderCopy(g->renderer, currentTexture, NULL, &(currentMonster->rect));           
    }
}

void move_monster(Game *g, Map *map, Perso *p) {
    
    srand(time(NULL));

    int nbMonsterToMove = rand() % (map->nbmonsters) + 1;

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
            map->quadmap[m->positionY][m->positionX] = 0;
            m->rect.x -= TILESIZE;
            refresh_position_monsterXY(m, map);                // on actualise la position X et Y du monstre sur la map de collisions
            break;

            case RIGHT:
            map->quadmap[m->positionY][m->positionX] = 0;
            m->rect.x += TILESIZE;
            refresh_position_monsterXY(m, map);
            
            break;

            case UP:
            map->quadmap[m->positionY][m->positionX] = 0; 
            m->rect.y -= TILESIZE;
            refresh_position_monsterXY(m, map);
            break;

            case DOWN:
            map->quadmap[m->positionY][m->positionX] = 0; 
            m->rect.y += TILESIZE;
            refresh_position_monsterXY(m, map);
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




void get_position_monster(int idMonster, int distance, Map *map, Game *g, Perso *p) {

    Monster *m = map->monsters[idMonster]; 

    get_collision_monster(g, m, map, distance, p, idMonster); // move si case disponible
    refresh_position_monsterXY(m, map);
}




void get_collision_monster(Game *g, Monster *m, Map *map, int distance, Perso *p, int idMonster) {

// on recupere les coordonnées des cases adjacentes dans la map de collisions

    int caseGauche = map->quadmap[m->positionY][m->positionX - 1];
    int caseDroite = map->quadmap[m->positionY][m->positionX + 1];
    int caseHaut = map->quadmap[m->positionY - 1][m->positionX];
    int caseBas = map->quadmap[m->positionY + 1][m->positionX];

//
    switch(m->direction) {

        case LEFT:
        if(caseGauche == 0) make_move_monster(m, map, g, p); 
        break;

        case RIGHT:
        if(caseDroite == 0) make_move_monster(m, map, g, p);
        break;

        case UP:
        if(caseHaut == 0) make_move_monster(m, map, g, p);
        break;

        case DOWN:
        if(caseBas == 0) make_move_monster(m, map, g, p);
        break;

        default:
        break;
    }
}



void refresh_position_monsterXY(Monster *m, Map *map) {

    m->positionX = (m->rect.x)/TILESIZE;
    m->positionY = (m->rect.y)/TILESIZE;

    map->quadmap[m->positionY][m->positionX] = 2;
}

