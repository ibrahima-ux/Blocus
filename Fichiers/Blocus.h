//Declarations Fonctions
#ifndef BLocus_H
#define BLocus_H

#include <stdio.h>
#include <stdlib.h>
#include <graph.h>

#define MAX_TAILLE 9       
#define MAX_OPTIONS 7      


extern char grille[MAX_TAILLE][MAX_TAILLE];


void initialiserJeu(int taille);         
void afficherGrille(int taille);        
void afficherGrilleJeu(int taille);    
void AfficheImageFond();                
void TailleJeux();                       

#endif 
