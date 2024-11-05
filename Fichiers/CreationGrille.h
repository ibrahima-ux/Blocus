#ifndef CREATION_GRILLE_H
#define CREATION_GRILLE_H
#include "Global.h"
#define MAX_TAILLE 9  

extern char grille[MAX_TAILLE][MAX_TAILLE]; 

void initialiserJeu(int taille);
void afficherGrille(int taille);
void deplacerPion(int joueur, int *x, int *y, int newX, int newY);
void condamnerCase(int x, int y);
int deplacementPossible(int x, int y, int taille);
void mettreAJourCase(int x, int y);

#endif
