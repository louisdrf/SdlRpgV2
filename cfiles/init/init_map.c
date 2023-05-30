#include <SDL.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "../../headers/main/structs.h"
#include "../../headers/main/defines.h"


void read_collisions(Map *m) { // cree le tableau de collisions de la map a partir du fichier

     FILE *file = fopen(m->collisionMapPath, "r");
     printf("ouverture du fichier de map %s\n", m->collisionMapPath);
    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier de map %s\n", m->collisionMapPath);
        exit(1);
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
    memcpy(m->quadmap, collisions, sizeof(collisions));
}


void init_collisions(Map *map) { // initialise le masque de collisions pour la map

    read_collisions(map);
            
        int quadmapDivided[NBTILES][NBTILES];

            for (int i = 0; i < 20; i++) {
                for (int j = 0; j < 20; j++) {
                    int value = map->quadmap[i][j];
                    
                    for (int x = 0; x < NBMAPCUTS; x++) {
                        for (int y = 0; y < NBMAPCUTS; y++) {
                            quadmapDivided[i * NBMAPCUTS + y][j * NBMAPCUTS + x] = value;
                        }
                    }
                }
            }

        memcpy(map->quadmap, quadmapDivided, sizeof(quadmapDivided));
}



Globalmap *init_global_map() {

    srand(time(NULL));

    Map maps[NBMAPSY][NBMAPSX];
    Globalmap *pgmap = malloc((NBMAPSX * NBMAPSY) *sizeof(Map));

    for (int i = 0; i < NBMAPSX; i++) {
        for (int j = 0; j < NBMAPSY; j++) {

            int nbmonsters = rand() % NBMAXMONSTER + 1; // nombre de monstres pour la map

            maps[i][j].x = 0;
            maps[i][j].y = 0;
            maps[i][j].rect.h = SCREEN_H;
            maps[i][j].rect.w = SCREEN_W;
            maps[i][j].rect.x = 0;
            maps[i][j].rect.y = 0;
            maps[i][j].nbmonsters = nbmonsters;

            maps[i][j].currentMapPath = malloc(50); // 29 caracteres pour un chemin complet de map
            maps[i][j].collisionMapPath = malloc(50); 
            strcpy(maps[i][j].currentMapPath, "img/mapsZelda/maps/map");
            strcpy(maps[i][j].collisionMapPath, "img/mapsZelda/collisions/map");

            char mapIndex[3];
            sprintf(mapIndex, "%d%d", j , i);
            strcat(maps[i][j].currentMapPath, mapIndex);
            strcat(maps[i][j].collisionMapPath, mapIndex);
            strcat(maps[i][j].currentMapPath, ".png");
            strcat(maps[i][j].collisionMapPath, ".txt");

            init_collisions(&(maps[i][j]));

            pgmap->gmap[j][i] = malloc(sizeof(Map));
            memcpy(pgmap->gmap[j][i], &(maps[i][j]), sizeof(Map)); // on copie les maps créées dans notre map globale
        }
    }
    
    return pgmap;
}