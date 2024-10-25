#ifndef GRILLE_H
#define GRILLE_H

#define MAX_TAILLE 9

extern char grille[MAX_TAILLE][MAX_TAILLE];

void initialiserJeu(int taille);
void afficherGrille(int taille);
void afficherGrilleGraphique(int taille);

#endif
