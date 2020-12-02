#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AffichageH.h"

void AfficheMap(char plat[TAILLE][TAILLE]){
    for(int i=0;i<TAILLE;i++){
        for(int j=0;j<TAILLE;j++){
            if(plat[i][j]=='o'){
                printf("%c ",'_');
            }else{
                if(i==0 && j==10){
                    printf("%s","10");
                }
                printf("%c ",plat[i][j]);
            }
        }
        printf("\n");
    }
}

void AfficheGameMap(char plat[TAILLE][TAILLE]){
    for(int i=0;i<TAILLE;i++){
        for(int j=0;j<TAILLE;j++){

            if (i==0 && j==10){
                printf("%s","10");
            } else{
                if(plat[i][j]=='o' || strchr("pcdst",plat[i][j])){
                    printf("%c ",'_');
                }else{
                    printf("%c ",plat[i][j]);
                }
            }
        }
        printf("\n");
    }
}
