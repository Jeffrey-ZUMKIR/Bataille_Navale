#ifndef INITVARH_H_INCLUDED
#define INITVARH_H_INCLUDED

#define TAILLE 11


typedef struct plateau{
    char tab_j1[11][11];
    char tab_j2[11][11];
}plateau;

/*typedef struct coord{
    int x1;
    int y1;
}coord;*/

typedef struct cara{
    int l;
    //coord pos;
    char nom[13];
    char init;
}cara;

typedef struct bateau{
    cara Porteavion;
    cara Cuirasse;
    cara Destroyer;
    cara Sousmarin;
    cara Torpilleur;
}bateau;

typedef struct player{
    int nbP;
    int nbC;
    int nbD;
    int nbS;
    int nbT;
}player;

extern void InitBoat(bateau *port);
extern void InitMap(char plat[TAILLE][TAILLE]);
extern void InitPlayer(player *p);
extern void InitForGame(char plat[TAILLE][TAILLE]);
char translateIntInChar(int i);


#endif // INITVARH_H_INCLUDED
