#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GameH.h"
#include "InitGameH.h"
#include "AffichageH.h"

#define TAILLE 11

//BUT:   Tirer 3 fois
//ENTREE:La map du joueur adverse, la varialble du joueur adverse, la variable de fin de jeu
//SORTIE:3 tirs sur la map adverse
void Tir(char plat[TAILLE][TAILLE],player *p,int *FinDuJeu){
    int x1=0;
    int y1=0;
    int x2=0;
    int y2=0;
    int x3=0;
    int y3=0;
    //3 tirs
    Viser(plat,1,&x1,&y1,x2,y2,x3,y3);
    Viser(plat,2,&x2,&y2,x1,y1,x3,y3);
    Viser(plat,3,&x3,&y3,x1,y1,x2,y2);

    system("cls");

    //3 check de tir
    CheckTir(plat,x1,y1,p);
    CheckTir(plat,x2,y2,p);
    CheckTir(plat,x3,y3,p);

    printf("\n");
    AfficheGameMap(plat);

    //Check fin de jeu
    if(p->nbC+p->nbD+p->nbP+p->nbS+p->nbT==0){
        *FinDuJeu=1;
    }

}

//BUT:   Tirer dans une zone
//ENTREE:La map du joueur adverse, le numéro du tir, position x et y du tir, la position x et y des deux autres tirs
//SORTIE:Une zone s'est fait tiré dessus
void Viser(char plat[TAILLE][TAILLE],int tirNb,int *x,int *y,int x1,int y1,int x2,int y2){
    int good=0;
    int xtemp=0;
    int ytemp=0;

    char lettre;

    //Demande au joueur une zone de tir
    do{
        printf("Tir numero %d\n",tirNb);
        printf("Nombre :");
        scanf("%d",&xtemp);
        *x=xtemp;
        fflush(stdin);
        printf("Lettre :");
        lettre=getchar();
        fflush(stdin);
        ytemp=translateCharInInt(lettre);
        *y=ytemp;
        //Check si la zone est dans la map ou qu'un autre tir n'a pas déjà était fait à cet endroit
        if((xtemp>0 && xtemp<TAILLE)&&(ytemp>0 && ytemp<TAILLE)&&(xtemp!=x1 || ytemp!=y1)&&(xtemp!=x2 || ytemp!=y2)){
            if(plat[ytemp][xtemp]=='o' || strchr("pcdst",plat[ytemp][xtemp])){
                good=1;
            }
        }
    }while(good==0);
}

//BUT:   Check si le tir à touché ou non
//ENTREE:La map du joueur adverse, les coordonnées de tir, la variable du joueur adverse
//SORTIE:
void CheckTir(char plat[TAILLE][TAILLE],int x,int y,player *p){
    //Si zone vide
    if(plat[y][x]=='o'){
        plat[y][x]='/';
        printf("A l'eau!");
    }else{
        //Si zone avec bateau
        switch(plat[y][x]){
        case 'p':
            p->nbP-=1;
            if(p->nbP==0){
                printf("Toucher couler!");
            }else{
                printf("Toucher!");
            }
            break;
        case 'c':
            p->nbC-=1;
            if(p->nbC==0){
                printf("Toucher couler!");
            }else{
                printf("Toucher!");
            }
            break;
        case 'd':
            p->nbD-=1;
            if(p->nbD==0){
                printf("Toucher couler!");
            }else{
                printf("Toucher!");
            }
            break;
        case 's':
            p->nbS-=1;
            if(p->nbS==0){
                printf("Toucher couler!");
            }else{
                printf("Toucher!");
            }
            break;
        case 't':
            p->nbT-=1;
            if(p->nbT==0){
                printf("Toucher couler!");
            }else{
                printf("Toucher!");
            }
            break;
        }
        plat[y][x]='*';
    }
}
