#ifndef DEFINES
#define DEFINES

#define SCREEN_H 720
#define SCREEN_W 720
#define PERSO_SPEED 36 // deplacement en pixels du perso
#define PERSO_DAMAGE 30 // degats du perso
#define NB_PERSO_ANIMATIONS 8 // nb d'animations differentes du personnage
#define DELAY_BETWEEN_ANIMATIONS 12 // en ms
#define DELAY_BETWEEN_ATTACKS 200

#define NBMAPSX 2
#define NBMAPSY 2
#define NBTILES 20 // nombre de tuiles pour diviser la map
#define NBMAPCUTS 1 // nombre de découpes de la map (pour les collisions) -> nbtiles  / 20
#define TILESIZE 36 // taille d'une tuile

#define NB_MONSTER_ANIMATIONS 4
#define MONSTER_SPEED 36
#define NBMAXMONSTER 4
#define DELAY_MOVE_MONSTER 500

#endif