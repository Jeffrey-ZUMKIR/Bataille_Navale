#include <stdio.h>
#include <stdlib.h>
#include "InitVarH.h"
#include "AffichageH.h"
#include "InitGameH.h"
#include "GameH.h"

int main()
{
    plateau plat;
    bateau port;
    player play1;
    player play2;
    int FinDuJeu=0;

    InitBoat(&port);
    InitMap(&plat.tab_j1);
    InitMap(&plat.tab_j2);
    InitPlayer(&play1);
    InitPlayer(&play2);

    AfficheMap(plat.tab_j1);
    InitGame(&plat.tab_j1,1,port);
    system("cls");
    AfficheMap(plat.tab_j2);
    InitGame(&plat.tab_j2,2,port);


    InitForGame(&plat.tab_j1);
    InitForGame(&plat.tab_j2);

    do{
        //Tour joueur 1
        if(FinDuJeu==0){
            system("cls");
            printf("\n");
            AfficheGameMap(plat.tab_j2);
            Tir(&plat.tab_j2,&play2,&FinDuJeu);
            //system("cls");
            //AfficheGameMap(plat.tab_j2);
            system("pause");
        }

        //Tour joueur 2
        if(FinDuJeu==0){
            system("cls");
            printf("\n");
            AfficheGameMap(plat.tab_j1);
            Tir(&plat.tab_j1,&play1,&FinDuJeu);
            //system("cls");
            //AfficheGameMap(plat.tab_j1);
            system("pause");
        }
    }while(FinDuJeu==0);

    if(play1.nbC+play1.nbD+play1.nbP+play1.nbS+play1.nbT==0){
        printf("Joueur 2 gagne!");
    }else{
        printf("Joueur 1 gagne!");
    }

    return 0;
}
