#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "InitGameH.h"
#include "AffichageH.h"

//BUT:   Initialisation de la pose des bateaux
//ENTREE:La map du joueur, le numéro du joueur et ses bateaux
//SORTIE:La map initialisé avec les bateaux
void InitGame(char plat[TAILLE][TAILLE],int joueur, bateau port){
    PoseBateau(plat,joueur,port.Porteavion);
    PoseBateau(plat,joueur,port.Cuirasse);
    PoseBateau(plat,joueur,port.Destroyer);
    PoseBateau(plat,joueur,port.Sousmarin);
    PoseBateau(plat,joueur,port.Torpilleur);
}

//BUT:   Poser un bateau
//ENTREE:La map du joueur, le numéro du joueur, le bateau à placer
//SORTIE:Le bateau placer
void PoseBateau(char plat[TAILLE][TAILLE],int joueur, cara bt){
    char sens;
    int x=0;
    int y=0;
    char lettre;
    int good=0;
    printf("Joueur %d, veuillez placer votre %s.\n",joueur,bt.nom);
    //Demander l'orientation du bateau
    do{
        fflush(stdin);
        printf("Voulez-vous le placer a la verticale(V) ou a l'horizontal(H)?\n");
        sens=getchar();
        if(sens=='H'||sens=='V'){
            good=1;
        }
    }while(good==0);
    good=0;
    printf("Veuillez choisir les coordonnes pour l'avant du bateau.\n");
    //Check pose bateau
    do{
        //Demande au joueur les coordonnées de la pointe du bateau
        printf("Nombre :");
        scanf("%d",&x);
        fflush(stdin);
        printf("Lettre :");
        lettre=getchar();
        fflush(stdin);
        y=translateCharInInt(lettre);

        //On check si la position est libre
        if((x>0 && x<TAILLE)&&(y>0 && y<TAILLE)){
            good=1;
            //En horizontal
            if(sens=='H'){
                for(int i=0;i<bt.l;i++){
                    if((plat[y][x+i]!='o' || x+i>=TAILLE) && good==1){
                        good=0;
                        if(plat[y][x+i]=='/'){
                            printf("Trop proche d'un autre navire!\n");
                        }
                        if(strchr("pcdst",plat[y][x+i])){
                            printf("Un navire est deja present!\n");
                        }
                        if(x+i>=TAILLE){
                            printf("Vous sortez de la map!\n");
                        }
                    }
                }
            }
            //En vertical
            if(sens=='V'){
                for(int i=0;i<bt.l;i++){
                    if((plat[y+i][x]!='o' || y+i>=TAILLE) && good==1){
                        good=0;
                        if(plat[y+i][x]=='/'){
                            printf("Trop proche d'un autre navire!\n");
                        }
                        if(strchr("pcdst",plat[y][x+i])){
                            printf("Un navire est deja present!\n");
                        }
                        if(y+i>=TAILLE){
                            printf("Vous sortez de la map!\n");
                        }
                    }
                }
            }
        }


    }while(good==0);
    //Placer le bateau
    //Horizontal
    if(sens=='H'){
        if(x-1>0){
            plat[y][x-1]='/';
        }
        for(int i=0;i<bt.l;i++){
            plat[y][x+i]=bt.init;
            if(y-1>0){
                plat[y-1][x+i]='/';
            }
            if(y+1<TAILLE){
                plat[y+1][x+i]='/';
            }
        }
        if(x+bt.l<TAILLE){
            plat[y][x+bt.l]='/';
        }
    }
    //Vertical
    if(sens=='V'){
        if(y-1>0){
            plat[y-1][x]='/';
        }
        for(int i=0;i<bt.l;i++){
            plat[y+i][x]=bt.init;
            if(x-1>0){
                plat[y+i][x-1]='/';
            }
            if(x+1<TAILLE){
                plat[y+i][x+1]='/';
            }
        }
        if(y+bt.l<TAILLE){
            plat[y+bt.l][x]='/';
        }
    }
    system("cls");
    AfficheMap(plat);
}

//BUT:   Conversion de lettre en nombre
//ENTREE:Une lettre
//SORTIE:Un chiffre
int translateCharInInt(char letter){
    int nb;
    letter=toupper(letter);
    switch(letter){
    case 'A':
        nb=1;
        break;

    case 'B':
        nb=2;
        break;

    case 'C':
        nb=3;
        break;

    case 'D':
        nb=4;
        break;

    case 'E':
        nb=5;
        break;

    case 'F':
        nb=6;
        break;

    case 'G':
        nb=7;
        break;

    case 'H':
        nb=8;
        break;

    case 'I':
        nb=9;
        break;

    case 'J':
        nb=10;
        break;

    default:
        nb=-1;
    }
    return nb;
}
