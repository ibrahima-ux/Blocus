#ifndef BLocus_H
#define BLocus_H

#include <stdio.h>
#include <stdlib.h>
#include <graph.h>

#define MAX_TAILLE 9       
#define MAX_OPTIONS 7      
#define LARGEUR_FENETRE 900 // Largeur de la fenêtre
#define HAUTEUR_FENETRE 600 // Hauteur de la fenêtre
#define LARGEUR_BOUTON (LARGEUR_FENETRE / 4) // Largeur du bouton
#define HAUTEUR_BOUTON 50 // Hauteur du bouton

extern char grille[MAX_TAILLE][MAX_TAILLE];


 extern int choisirTaille; 
extern int casesCochees[MAX_OPTIONS]; 

// Déclaration des fonctions
void initialiserJeu(int taille);         
void afficherGrille(int taille);        
void afficherGrilleJeu(int taille);    
void AfficheImageFond();                
void TailleJeux();                       
void gererInteractions(int positionSourisX, int positionSourisY);

#endif // BLocus_H
