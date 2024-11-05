#include "Blocus.h" 
#include "BlocusAffichage.h"

void afficherGrilleJeu(int taille) {
    int cell_size = 50;  
    int totalWidth = taille * cell_size;
    int totalHeight = taille * cell_size;

    int x_start = (LARGEUR_FENETRE - totalWidth) / 2;
    int y_start = (HAUTEUR_FENETRE - totalHeight) / 2;
    int border_thickness = 3;  // Épaisseur des bordures

    int i, j,k;
    for (i = 0; i < taille; i++) {
        for (j = 0; j < taille; j++) {
            
            if (grille[i][j] == 'X') {
                ChoisirCouleurDessin(CouleurParNom("grey")); 
            } else if (grille[i][j] == 'A') {
                ChoisirCouleurDessin(CouleurParNom("red"));   // Joueur 1
            } else if (grille[i][j] == 'B') {
                ChoisirCouleurDessin(CouleurParNom("blue"));  // Joueur 2
            } else {
                ChoisirCouleurDessin(CouleurParNom("white")); 
            }
            RemplirRectangle(x_start + j * cell_size, y_start + i * cell_size, cell_size, cell_size);

            
            ChoisirCouleurDessin(CouleurParNom("black"));
            for (k = 0; k < border_thickness; k++) {
                DessinerRectangle(x_start + j * cell_size + k, y_start + i * cell_size + k,
                                  cell_size - 2 * k, cell_size - 2 * k);
            }
        }
    }
}
