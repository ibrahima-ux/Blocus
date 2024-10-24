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
extern int choisirTaille;           
extern int casesCochees[MAX_OPTIONS]; 
extern int modeJeu;                 

// Déclaration des fonctions
void initialiserJeu(int taille);         
void afficherGrille(int taille);        
void afficherGrilleJeu(int taille);    
void chargerSprites();                  
void libererSprites();                 
void afficherFondMenu();                
void afficherFondJeu1();                
void afficherFondJeu2();                
void TailleJeux();                      
void gererInteractions(int positionSourisX, int positionSourisY); 
void afficherOptionsJoueurs();          
void gererChoixJoueurs(int positionSourisX, int positionSourisY); 
void afficherGrilleSiValidee(int positionSourisX, int positionSourisY); 

#endif 
