#include <SDL.h>
#include "../headers/structs.h"
#include "../headers/defines.h"


void init_map(Map *map) {


    int partWidth = SCREEN_W / 2;
    int partHeight = SCREEN_H / 2;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            int partX = i * partWidth;
            int partY = j * partHeight;

            map->parts[i][j].x = partX;
            map->parts[i][j].y = partY;
            map->parts[i][j].w = partWidth;
            map->parts[i][j].h = partHeight;
        }
    }
    
}