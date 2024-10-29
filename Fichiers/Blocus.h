#ifndef BLocus_H
#define BLocus_H

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
#define IMAGE_FOND1 "ImageFond1.jpg"
#define IMAGE_FOND2 "ImageFond2.jpg"  

extern char grille[MAX_TAILLE][MAX_TAILLE]; 

// Variables globales
extern int etatJeu;  // Déclare etatJeu comme variable globale accessible partout

extern int choisirTaille;           
extern int casesCochees[MAX_OPTIONS]; 
extern int modeJeu;         
extern int spriteCroixBleue;
extern int spritePionBleu;
extern int spriteCroixRouge;
extern int spritePionRouge;        
extern int etapePlacement;
extern int tourJoueur;
extern int joueur1X, joueur1Y;  // Position actuelle du pion du joueur 1
extern int joueur2X, joueur2Y;  // Position actuelle du pion du joueur 2


// Déclaration des fonctions
void initialiserJeu(int taille);         
void afficherGrille(int taille);        
void afficherGrilleJeu(int taille);    
void chargerSprites();                  
void libererSprites();    
void chargerSpritesPions();
void libererSpritesPions();             
void afficherFondMenu();                
void afficherFondJeu1();                
void afficherFondJeu2();                
void TailleJeux();                      
void gererInteractions(int positionSourisX, int positionSourisY); 
void afficherOptionsJoueurs();          
void gererChoixJoueurs(int positionSourisX, int positionSourisY); 
void afficherGrilleSiValidee(int positionSourisX, int positionSourisY); 
void mettreAJourCase(int x, int y);

void afficherMessageGraphique(const char *message);
void deplacerPion(int joueur, int *x, int *y, int newX, int newY);
void condamnerCase(int x, int y);
int deplacementPossible(int x, int y, int taille);
int estPartieTerminee(int joueurX, int joueurY, int taille);
void mouvementIA(int *x, int *y, int taille);  // Fonction pour l’IA
// Déclaration des fonctions pour gérer les interactions
void placerSpritePion(int ligne, int colonne, char type, int joueur, int taille);
void gererClicGrille(int positionSourisX, int positionSourisY, int joueur, int taille);
void afficherScore(int gagnant);


// Déclarations des nouvelles fonctions
void jouerContreBot(int *joueurX, int *joueurY, int taille);
void jouerDeuxJoueurs(int *joueurX1, int *joueurY1, int *joueurX2, int *joueurY2, int taille);
#endif 
