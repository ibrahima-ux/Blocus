#include "Blocus.h" 
#include <graph.h>

char grille[MAX_TAILLE][MAX_TAILLE]; 

void initialiserJeu(int taille) {
    int i, j;
    for (i = 0; i < taille; i++) {
        for (j = 0; j < taille; j++) {
            grille[i][j] = ' '; 
        }
    }
}

void afficherGrille(int taille) {

    int x_start = (LARGEUR_FENETRE - (taille * 50)) / 2; // centrer 
    int y_start = 100; // du bord de la fenetre ala grille Y
    int cell_size = 50; 

    int i, j;
    for (i = 0; i < taille; i++) {
        for (j = 0; j < taille; j++) {
            // Dessiner la cellule
            ChoisirCouleurDessin(CouleurParNom("white")); 
            RemplirRectangle(x_start + j * cell_size, y_start + i * cell_size, cell_size, cell_size); 

            // Dessiner le cadre de la cellule
            ChoisirCouleurDessin(CouleurParNom("black")); 
            DessinerRectangle(x_start + j * cell_size, y_start + i * cell_size, cell_size, cell_size); 
        }
    }
}
