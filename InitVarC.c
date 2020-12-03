#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "InitVarH.h"

//BUT:   Initialiser mes variables de types bateau
//ENTREE:Variable de type bateau
//SORTIE:Variables initialisés
void InitBoat(bateau *port){
    port->Porteavion.l=5;
    port->Cuirasse.l=4;
    port->Destroyer.l=3;
    port->Sousmarin.l=3;
    port->Torpilleur.l=2;

    strcpy(port->Porteavion.nom,"porte-avions");
    strcpy(port->Cuirasse.nom,"cuirasse");
    strcpy(port->Destroyer.nom,"destroyer");
    strcpy(port->Sousmarin.nom,"sous-marin");
    strcpy(port->Torpilleur.nom,"torpilleur");

    port->Porteavion.init='p';
    port->Cuirasse.init='c';
    port->Destroyer.init='d';
    port->Sousmarin.init='s';
    port->Torpilleur.init='t';
}

//BUT:   Initialisation des maps de départ
//ENTREE:La map de départ
//SORTIE:La map de départ initialisé
void InitMap(char plat[TAILLE][TAILLE]){
    for(int i=0;i<TAILLE;i++){
        for(int j=0;j<TAILLE;j++){
            if(i!=0 && j!=0){
                plat[i][j]='o';
            }
            if(i==0 && j!=10){
                plat[i][j]=j+'0';
            }
            if(j==0){
                plat[i][j]=translateIntInChar(i);
            }
        }
    }
}

//BUT:   Initialisation des varaibles de type player
//ENTREE:Variable de type player
//SORTIE:Variable de type player initialisé
void InitPlayer(player *p){
    p->nbP=5;
    p->nbC=4;
    p->nbD=3;
    p->nbS=3;
    p->nbT=2;
}

//BUT:   Conversion de nombre en lettre
//ENTREE:Un nombre
//SORTIE:Une lettre
char translateIntInChar(int i){
    char letter;
    switch(i){
    case 0:
        letter=' ';
        break;

    case 1:
        letter='A';
        break;

    case 2:
        letter='B';
        break;

    case 3:
        letter='C';
        break;

    case 4:
        letter='D';
        break;

    case 5:
        letter='E';
        break;

    case 6:
        letter='F';
        break;

    case 7:
        letter='G';
        break;

    case 8:
        letter='H';
        break;

    case 9:
        letter='I';
        break;

    case 10:
        letter='J';
        break;
    }
    return letter;
}



//BUT:   Fixe de la map de départ
//ENTREE:La map du joueur
//SORTIE:La map du joueur sans les zones au accès interdit pour les bateaux
void InitForGame(char plat[TAILLE][TAILLE]){
    for(int i=0;i<TAILLE;i++){
        for(int j=0;j<TAILLE;j++){
            if(plat[i][j]=='/'){
                plat[i][j]='o';
            }
        }
    }
}
