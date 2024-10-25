#include "Blocus.h" 

void gererInteractions(int positionSourisX, int positionSourisY) {
    int caseX;
    int caseY;
    int boutonX;
    int boutonY;

    int i, j;

    for (i = 0; i < MAX_OPTIONS; i++) {
        caseX = 75 + 150; 
        caseY = 130 + (i * 30) - 5; 

        if (positionSourisX >= caseX && positionSourisX <= caseX + 20 &&
            positionSourisY >= caseY && positionSourisY <= caseY + 20) {
            // Décocher toutes les cases
            for (j = 0; j < MAX_OPTIONS; j++) {
                casesCochees[j] = 0; // Réinitialiser toutes les cases
            }
            casesCochees[i] = 1; // Cocher la case sélectionnée pour la taille
            TailleJeux(); // Mettre à jour
            break; 
        }
    }

    //  "Commencer" a été cliqué
    boutonX = (LARGEUR_FENETRE - LARGEUR_BOUTON) / 2; // Position X du bouton
    boutonY = 400; // Position Y du bouton

    if (positionSourisX >= boutonX && positionSourisX <= boutonX + LARGEUR_BOUTON &&
        positionSourisY >= boutonY && positionSourisY <= boutonY + HAUTEUR_BOUTON) {
        
        // Logique pour valider les choix
        for (i = 0; i < MAX_OPTIONS; i++) {
            if (casesCochees[i]) {
                choisirTaille = i + 3; 
                break; 
            }
        }

        if (choisirTaille >= 3 && choisirTaille <= 9) {
            if (modeJeu == 0) {
                printf("Veuillez choisir le mode de jeu.\n");
                return; 
            }
            EffacerEcran(CouleurParNom("white"));
            initialiserJeu(choisirTaille); 
            afficherGrilleJeu(choisirTaille); 
        } else {
            printf("Veuillez choisir une taille valide.\n");
        }
    }

    gererChoixJoueurs(positionSourisX, positionSourisY);
}
