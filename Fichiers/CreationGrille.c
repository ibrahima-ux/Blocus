#include "Blocus.h" // Inclure le fichier d'en-tête
#include <graph.h>

char grille[MAX_TAILLE][MAX_TAILLE]; // Définition de la grille

void initialiserJeu(int taille) {
    for (int i = 0; i < taille; i++) {
        for (int j = 0; j < taille; j++) {
            grille[i][j] = '.'; // Case libre
        }
    }
}

void afficherGrille(int taille) {
    int x_start = 100; // Du bord de la fentre au debut de lz grille X
    int y_start = 100; // Du bord de la fentre au debut de lz grille Y
    int cell_size = 50; // Taille de chaque cellule

    for (int i = 0; i < taille; i++) {
        for (int j = 0; j < taille; j++) {
           
            ChoisirCouleurDessin(CouleurParNom("white")); 
            RemplirRectangle(x_start + j * cell_size, y_start + i * cell_size, cell_size, cell_size); 

           
            ChoisirCouleurDessin(CouleurParNom("black")); 
            DessinerRectangle(x_start + j * cell_size, y_start + i * cell_size, cell_size, cell_size); 
        }
    }
}
