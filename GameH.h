#ifndef GAMEH_H_INCLUDED
#define GAMEH_H_INCLUDED
#include "InitVarH.h"

#define TAILLE 11

extern void Tir(char plat[TAILLE][TAILLE],player *p,int *FinDuJeu);
void Viser(char plat[TAILLE][TAILLE],int tirNb,int *x,int *y,int x1,int y1,int x2,int y2);
void CheckTir(char plat[TAILLE][TAILLE],int x,int y,player *p);

#endif // GAMEH_H_INCLUDED
