#include "Blocus.h"

int choisirTaille = 5; 
int casesCochees[MAX_OPTIONS] = {0}; 
int modeJeu = 0;

int main(void) {
    int positionSourisX; 
    int positionSourisY;

    
    if (InitialiserGraphique() == -1) {
        fprintf(stderr, "Erreur lors de l'initialisation graphique.\n");
        return EXIT_FAILURE;
    }

   
    CreerFenetre(20, 20, LARGEUR_FENETRE, HAUTEUR_FENETRE); 

    // Charger fonds
    chargerSprites(); 
    afficherFondMenu(); 
    TailleJeux(); // Afficher les options de taille

    while (1) {
        if (SourisCliquee()) {
            SourisPosition(); 
            positionSourisX = _X; 
            positionSourisY = _Y; 

            // Gérer les interactions
            gererInteractions(positionSourisX, positionSourisY);
            afficherGrilleSiValidee(positionSourisX, positionSourisY); 
        }
    }

    libererSprites(); 
    FermerGraphique(); 
    return 0; 
}
void afficherGrilleSiValidee(int positionSourisX, int positionSourisY) {
    int boutonX = (LARGEUR_FENETRE - LARGEUR_BOUTON) / 2; // Position X du bouton
    int boutonY = 400; // Position Y du bouton

    // Vérifier si le bouton "Commencer" a été cliqué
    if (positionSourisX >= boutonX && positionSourisX <= boutonX + LARGEUR_BOUTON &&
        positionSourisY >= boutonY && positionSourisY <= boutonY + HAUTEUR_BOUTON) {
        
        // Effacer l'écran avant d'afficher le fond
        EffacerEcran(CouleurParNom("white")); 
        
        // Afficher le fond en fonction du mode de jeu
        if (modeJeu == 1) {
            afficherFondJeu1(); 
        } else if (modeJeu == 2) {
            afficherFondJeu2(); 
        }

        
        if (choisirTaille >= 3 && choisirTaille <= 9) {
            initialiserJeu(choisirTaille); 
            afficherGrilleJeu(choisirTaille); 
        } else {
            printf("Veuillez choisir au moins une taille valide.\n");
        }
    }
}
