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
            
            ChoisirCouleurDessin(CouleurParNom("white")); 
            RemplirRectangle(x_start + j * cell_size, y_start + i * cell_size, cell_size, cell_size); 

            
            ChoisirCouleurDessin(CouleurParNom("black")); 
            DessinerRectangle(x_start + j * cell_size, y_start + i * cell_size, cell_size, cell_size); 
        }
    }
}
