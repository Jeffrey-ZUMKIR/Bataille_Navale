#ifndef INITGAMEH_H_INCLUDED
#define INITGAMEH_H_INCLUDED
#include "InitVarH.h"

#define TAILLE 11

extern void InitGame(char plat[TAILLE][TAILLE],int joueur, bateau port);
void PoseBateau(char plat[TAILLE][TAILLE],int joueur, cara bt);
int translateCharInInt(char letter);

#endif // INITGAMEH_H_INCLUDED
