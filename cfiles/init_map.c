#include <SDL.h>
#include <stdio.h>
#include <string.h>
#include "../headers/structs.h"
#include "../headers/defines.h"


int read_collisions(Map *m) {

     int i, j;

     FILE *file = fopen(m->collisionMapPath, "r");
     printf("ouverture du fichier de map %s\n", m->collisionMapPath);
    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier de map %s\n", m->collisionMapPath);
        return 1;
    }

    int collisions[NBTILES][NBTILES];
    int row = 0, col = 0;
    char line[500];

     while (fgets(line, sizeof(line), file) != NULL) {
        char *collision = strtok(line, ", ");
        col = 0;
        while (collision != NULL && col < NBTILES) {
            collisions[row][col] = atoi(collision);
            collision = strtok(NULL, ", ");
            col++;
        }
        row++;
    }
    fclose(file);

}


void init_collisions(Map *map, Game *g) {

    Uint16 quadmapValues[20][20];

    read_collisions(map);
            
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



Globalmap *init_global_map(Game *g) {

    Map maps[NBMAPSX][NBMAPSY];
    Globalmap *pgmap = malloc((NBMAPSX * NBMAPSY) *sizeof(Map));

    for (int i = 0; i < NBMAPSX; i++) {
        for (int j = 0; j < NBMAPSY; j++) {

            maps[i][j].x = 0;
            maps[i][j].y = 0;
            maps[i][j].rect.h = SCREEN_H;
            maps[i][j].rect.w = SCREEN_W;
            maps[i][j].rect.x = 0;
            maps[i][j].rect.y = 0;

            maps[i][j].currentMapPath = malloc(27); // 26 caracteres pour un chemin complet de map
            maps[i][j].collisionMapPath = malloc(27); 
            strcpy(maps[i][j].currentMapPath, "../img/mapsZelda/map");
            strcpy(maps[i][j].collisionMapPath, "../img/mapsZelda/collisions/map");

            char mapIndex[3];
            sprintf(mapIndex, "%d%d", i , j);
            strcat(maps[i][j].currentMapPath, mapIndex);
            strcat(maps[i][j].collisionMapPath, mapIndex);
            strcat(maps[i][j].currentMapPath, ".png");
            strcat(maps[i][j].collisionMapPath, ".txt");

            init_collisions(&(maps[i][j]), g);

            pgmap->gmap[i][j] = malloc(sizeof(Map));
            memcpy(pgmap->gmap[i][j], &(maps[i][j]), sizeof(Map)); // on copie les maps créées dans notre map globale
        }
    }
    
    return pgmap;
}