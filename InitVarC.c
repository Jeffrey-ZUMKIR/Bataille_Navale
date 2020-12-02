#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "InitVarH.h"


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

void InitPlayer(player *p){
    p->nbP=5;
    p->nbC=4;
    p->nbD=3;
    p->nbS=3;
    p->nbT=2;
}

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




void InitForGame(char plat[TAILLE][TAILLE]){
    for(int i=0;i<TAILLE;i++){
        for(int j=0;j<TAILLE;j++){
            if(plat[i][j]=='/'){
                plat[i][j]='o';
            }
        }
    }
}
