#include "Blocus.h" 
#include <graph.h>

char grille[MAX_TAILLE][MAX_TAILLE]; 

void initialiserJeu(int taille) {
    for (int i = 0; i < taille; i++) {
        for (int j = 0; j < taille; j++) {
            grille[i][j] = ' '; 
        }
    }
}

void afficherGrille(int taille) {
    int x_start = (LARGEUR_FENETRE - (taille * 50)) / 2; // centrer 
    int y_start = 100; // du bord de la fnetre ala grille Y
    int cell_size = 50; 

    for (int i = 0; i < taille; i++) {
        for (int j = 0; j < taille; j++) {
            // Dessiner la cellule
            ChoisirCouleurDessin(CouleurParNom("white")); 
            RemplirRectangle(x_start + j * cell_size, y_start + i * cell_size, cell_size, cell_size); 

            // Dessiner le cadre de la cellule
            ChoisirCouleurDessin(CouleurParNom("black")); 
            DessinerRectangle(x_start + j * cell_size, y_start + i * cell_size, cell_size, cell_size); 
        }
    }
}
