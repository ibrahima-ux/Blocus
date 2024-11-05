#ifndef BLOCUS_AFFICHAGE_H
#define BLOCUS_AFFICHAGE_H

#include "Blocus.h" 

// Variables pour les sprites
extern int spriteCroixBleue;
extern int spritePionBleu;
extern int spriteCroixRouge;
extern int spritePionRouge;


void afficherGrille(int taille);
void afficherGrilleJeu(int taille);
void afficherFondMenu();
void afficherFondJeu1();
void afficherFondJeu2();
void afficherOptionsJoueurs();
void afficherScore(int gagnant);
void afficherMessageGraphique(const char *message);
void afficherGrilleSiValidee(int positionSourisX, int positionSourisY);


void TailleJeux();  
void gererClicGrille(int positionSourisX, int positionSourisY, int joueur, int taille);
void placerSpritePion(int ligne, int colonne, char type, int joueur, int taille);


void chargerSprites();
void chargerSpritesPions();
void libererSprites();
void libererSpritesPions();

#endif  
