#include "Blocus.h" 

void gererInteractions(int positionSourisX, int positionSourisY) {
  
    for (int i = 0; i < MAX_OPTIONS; i++) {
        int caseX = 100 + 150; 
        int caseY = 100 + (i * 30) - 5; 

       
        if (positionSourisX >= caseX && positionSourisX <= caseX + 20 &&
            positionSourisY >= caseY && positionSourisY <= caseY + 20) {
            // Décocher toutes les cases
            for (int j = 0; j < MAX_OPTIONS; j++) {
                casesCochees[j] = 0; 
            }
            casesCochees[i] = 1; 
            TailleJeux(); //Mettre a Jour
            break; 
        }
    }

    //Si "COMMENCER" a ete clike
    int boutonX = (LARGEUR_FENETRE - LARGEUR_BOUTON) / 2;
    int boutonY = 400; 

    if (positionSourisX >= boutonX && positionSourisX <= boutonX + LARGEUR_BOUTON &&
        positionSourisY >= boutonY && positionSourisY <= boutonY + HAUTEUR_BOUTON) {
        
        // Logique pour valider les choix
        for (int i = 0; i < MAX_OPTIONS; i++) {
            if (casesCochees[i]) {
                choisirTaille = i + 3; 
                break; 
            }
        }

       
        if (choisirTaille >= 3 && choisirTaille <= 9) {
            initialiserJeu(choisirTaille); 
            EffacerEcran(CouleurParNom("lightblue"));
            afficherGrilleJeu(choisirTaille); 
        } else {
            printf("Veuillez choisir au moins une taille valide.\n");
        }
    }
}
