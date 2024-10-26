#include "Blocus.h" 

void afficherGrilleJeu(int taille) {
    int cell_size = 50;
    int totalWidth = taille * cell_size;
    int totalHeight = taille * cell_size;

    int x_start = (LARGEUR_FENETRE - totalWidth) / 2;
    int y_start = (HAUTEUR_FENETRE - totalHeight) / 2;

    int i, j;
    for (i = 0; i < taille; i++) {
        for (j = 0; j < taille; j++) {
            // Affiche la couleur en fonction du contenu de la case
            if (grille[i][j] == 'X') {
                ChoisirCouleurDessin(CouleurParNom("grey"));  // Case bloquée
            } else if (grille[i][j] == 'A') {
                ChoisirCouleurDessin(CouleurParNom("red"));   // Joueur 1
            } else if (grille[i][j] == 'B') {
                ChoisirCouleurDessin(CouleurParNom("blue"));  // Joueur 2
            } else {
                ChoisirCouleurDessin(CouleurParNom("white")); // Case libre
            }
            RemplirRectangle(x_start + j * cell_size, y_start + i * cell_size, cell_size, cell_size);

            // Dessiner le cadre
            ChoisirCouleurDessin(CouleurParNom("black"));
            DessinerRectangle(x_start + j * cell_size, y_start + i * cell_size, cell_size, cell_size);
        }
    }
}
