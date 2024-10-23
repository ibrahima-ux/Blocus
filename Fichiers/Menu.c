#include "Blocus.h" 

int choisirTaille = 5; //par défaut
int casesCochees[MAX_OPTIONS] = {0}; //pour chocher aucune case au depart

void AfficheImageFond() {
    couleur couleurFond = CouleurParNom("lightblue"); // Couleur de fond souhaitée
    EffacerEcran(couleurFond); 

 ChargerImageFond("imageFond1.jpg"); 
}

void TailleJeux() {
    EcrireTexte(100, 50, "Choisissez la taille de la grille :", 2); 
    
    int i; 
    int optionX;
    int optionY; 
    int caseX; 
    int caseY; 
    int caseSize; 
    int taille; 

    for (i = 0; i < MAX_OPTIONS; i++) {
        taille = i + 3; // Pour les tailles 3 à 9
        
      
        optionX = 100; 
        optionY = 100 + (i * 30); // Position Y du texte
        caseX = optionX + 150; // Position de la case à cocher
        caseY = optionY - 5; // Position de la case à cocher
        caseSize = 20; 

        
        ChoisirCouleurDessin(CouleurParNom("green"));
        RemplirRectangle(caseX, caseY, caseSize, caseSize); // Fond de la case
        if (casesCochees[i]) { // Si la case est cochée
            ChoisirCouleurDessin(CouleurParNom("red")); 
            RemplirRectangle(caseX + 2, caseY + 2, caseSize - 4, caseSize - 4); //declage
        }

       
        char optionText[10]; //stocker les  valeurs
        sprintf(optionText, "%dx%d", taille, taille);
        ChoisirCouleurDessin(CouleurParNom("black")); 
        EcrireTexte(optionX, optionY, optionText, 2); 
    }

    // Ajt Bouton 
    int boutonX = 300; 
    int boutonY = 400; 
    int boutonLargeur = 150; 
    int boutonHauteur = 50; 

    ChoisirCouleurDessin(CouleurParNom("red")); 
    RemplirRectangle(boutonX, boutonY, boutonLargeur, boutonHauteur); 

    ChoisirCouleurDessin(CouleurParNom("black")); // Contour
    DessinerRectangle(boutonX, boutonY, boutonLargeur, boutonHauteur); 

    ChoisirCouleurDessin(CouleurParNom("black")); 
    char *texte = "Commencer"; 
    int largeurTexte = TailleChaineEcran(texte, 2); 
    int texteX = boutonX + (boutonLargeur / 2) - (largeurTexte / 2); 
    int texteY = boutonY + (boutonHauteur / 2) - (TailleSupPolice(2) / 2); 
    EcrireTexte(texteX, texteY, texte, 2); 
}

int main(void) {
    int positionSourisX; 
    int positionSourisY; 
    int i; 

  InitialiserGraphique();
    
    CreerFenetre(20, 20, 750, 600); 
    AfficheImageFond();
    TailleJeux();

    while (1) {
        if (SourisCliquee()) {
            SourisPosition(); 
            positionSourisX = _X; // Trouve X et garde sa pstion
            positionSourisY = _Y; // ....

          
            for (i = 0; i < MAX_OPTIONS; i++) {
                int caseX = 100 + 150; //Aligner 
                int caseY = 100 + (i * 30) - 5; //bien Aligner les cases 
            

                
                if (positionSourisX >= caseX && positionSourisX <= caseX + 20 &&
                    positionSourisY >= caseY && positionSourisY <= caseY + 20) {
                    // Décocher toutes les cases
                    for (int j = 0; j < MAX_OPTIONS; j++) {
                        casesCochees[j] = 0; 
                    }
                    casesCochees[i] = 1; 
                    TailleJeux(); 
                    break; 
                }
            }

            
            int boutonX = 300; 
            int boutonY = 400; 

            if (positionSourisX >= boutonX && positionSourisX <= boutonX + 150 &&
                positionSourisY >= boutonY && positionSourisY <= boutonY + 50) {
                
                
                for (i = 0; i < MAX_OPTIONS; i++) {
                    if (casesCochees[i]) {
                        choisirTaille = i + 3; 
                        break; 
                    }
                }

                
                if (choisirTaille >= 3 && choisirTaille <= 9) {
                    initialiserJeu(choisirTaille); 
                    afficherGrilleJeu(choisirTaille);
                } else {
                    printf("Veuillez choisir au moins une taille valide.\n");
                }
            }
        }
    }

    FermerGraphique(); 
    return 0; 
}
