#ifndef BLOCUS_H
#define BLOCUS_H

#include <stdio.h>
#include <stdlib.h>
#include <graph.h>

#define MAX_TAILLE 9               
#define MAX_OPTIONS 7              
#define LARGEUR_FENETRE 900       
#define HAUTEUR_FENETRE 600        
#define LARGEUR_BOUTON (LARGEUR_FENETRE / 4) 
#define HAUTEUR_BOUTON 50        

#define IMAGE_MENU "ImageMenu.jpg"   
#define IMAGE_FOND1 "ImageFond2.jpg"
#define IMAGE_FOND2 "ImageFond2.jpg"  

// Déclaration de la grille de jeu et variables globales
extern char grille[MAX_TAILLE][MAX_TAILLE];
extern int etatJeu;
extern int choisirTaille;
extern int casesCochees[MAX_OPTIONS];
extern int modeJeu;
extern int etapePlacement;
extern int tourJoueur;
extern int joueur1X, joueur1Y;
extern int joueur2X, joueur2Y;

// Fonctions de jeu principales
void revenirAuMenu();
void initialiserJeu(int taille);
void gererInteractions(int positionSourisX, int positionSourisY);
void gererChoixJoueurs(int positionSourisX, int positionSourisY);
void deplacerPion(int joueur, int *x, int *y, int newX, int newY);
void condamnerCase(int x, int y);
int deplacementPossible(int x, int y, int taille);
int estPartieTerminee(int joueurX, int joueurY, int taille);
void mouvementIA(int *x, int *y, int taille);
void mettreAJourCase(int x, int y);
void jouerContreBot(int *joueurX, int *joueurY, int taille);
void jouerDeuxJoueurs(int *joueurX1, int *joueurY1, int *joueurX2, int *joueurY2, int taille);

#endif  // BLOCUS_H
