#include <SDL.h>
#include "../headers/structs.h"
#include "../headers/defines.h"


void init_collisions(Map *map, Game *g) {

    Uint16 quadmapValues[20][20] = {
            {305, 306, 306, 306, 306, 306, 306, 306, 306, 306, 306, 306, 306, 306, 306, 291, 0, 0, 289, 307},
            {321, 420, 421, 421, 421, 422, 342, 302, 0, 326, 326, 0, 326, 0, 326, 326, 0, 0, 326, 323},
            {321, 436, 429, 430, 431, 438, 342, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 342, 323},
            {321, 448, 432, 448, 432, 448, 342, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 323},
            {321, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 323},
            {321, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 323},
            {321, 342, 0, 0, 0, 0, 0, 0, 0, 0, 0, 342, 0, 0, 0, 0, 0, 0, 342, 323},
            {321, 0, 0, 0, 0, 0, 0, 305, 306, 306, 306, 306, 307, 0, 0, 0, 0, 0, 326, 323},
            {321, 0, 0, 0, 0, 0, 0, 321, 303, 304, 303, 304, 323, 0, 0, 0, 0, 0, 0, 323},
            {321, 342, 0, 0, 0, 0, 0, 321, 319, 320, 319, 320, 323, 0, 0, 0, 0, 0, 0, 323},
            {321, 342, 0, 0, 0, 0, 0, 321, 303, 304, 303, 304, 323, 0, 0, 0, 0, 0, 326, 323},
            {321, 0, 0, 0, 0, 0, 0, 321, 319, 320, 319, 320, 323, 0, 0, 0, 0, 0, 342, 323},
            {321, 0, 0, 0, 0, 0, 0, 337, 338, 338, 338, 338, 339, 0, 0, 0, 0, 0, 326, 323},
            {321, 326, 0, 0, 0, 0, 0, 342, 0, 0, 0, 342, 326, 0, 0, 0, 0, 0, 0, 323},
            {321, 326, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 326, 323},
            {321, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 323},
            {321, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 342, 323},
            {321, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 342, 0, 323},
            {321, 301, 342, 318, 0, 0, 0, 342, 342, 0, 0, 0, 0, 0, 0, 326, 326, 0, 0, 323},
            {337, 338, 338, 338, 338, 338, 338, 338, 338, 338, 338, 338, 338, 338, 338, 338, 338, 338, 338, 339}};

            

        Uint16 quadmapDivided[NBTILES][NBTILES];

            for (int i = 0; i < 20; i++) {
                for (int j = 0; j < 20; j++) {
                    int value = quadmapValues[i][j];
                    
                    for (int x = 0; x < NBMAPCUTS; x++) {
                        for (int y = 0; y < NBMAPCUTS; y++) {
                            quadmapDivided[i * NBMAPCUTS + y][j * NBMAPCUTS + x] = value;
                        }
                    }
                }
            }

        memcpy(map->quadmap, quadmapDivided, sizeof(quadmapDivided));

}