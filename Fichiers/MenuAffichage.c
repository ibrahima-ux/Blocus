#include "Blocus.h" 

void AfficheImageFond() {
   
    ChargerImageFond("Image1.jpg"); //jarrive pas 
}

void TailleJeux() {
   
    EffacerEcran(CouleurParNom("Green")); 

    EcrireTexte(100, 50, "Choisissez la taille de la grille :", 2); 

    for (int i = 0; i < MAX_OPTIONS; i++) {
        int taille = i + 3; 
        int optionX = 100; 
        int optionY = 100 + (i * 30); 
        int caseX = optionX + 150; 
        int caseY = optionY - 5; 
        int caseSize = 20; 

       
        ChoisirCouleurDessin(CouleurParNom("lightgray"));
        RemplirRectangle(caseX, caseY, caseSize, caseSize);
        if (casesCochees[i]) { 
            ChoisirCouleurDessin(CouleurParNom("red")); 
            RemplirRectangle(caseX + 2, caseY + 2, caseSize - 4, caseSize - 4); // Fond rouge si cochée
        }

        // Afficher la taille
        char optionText[10]; 
        sprintf(optionText, "%dx%d", taille, taille);
        ChoisirCouleurDessin(CouleurParNom("black")); 
        EcrireTexte(optionX, optionY, optionText, 2); 
    }

    // Ajt "COMMENCER"
    int boutonLargeur = LARGEUR_BOUTON; 
    int boutonHauteur = HAUTEUR_BOUTON; 
    int boutonX = (LARGEUR_FENETRE - boutonLargeur) / 2; // Centrer 
    int boutonY = 400; 

    ChoisirCouleurDessin(CouleurParNom("red")); 
    RemplirRectangle(boutonX, boutonY, boutonLargeur, boutonHauteur); 

    ChoisirCouleurDessin(CouleurParNom("black")); 
    DessinerRectangle(boutonX, boutonY, boutonLargeur, boutonHauteur); 

    ChoisirCouleurDessin(CouleurParNom("black")); 
    char *texte = "Commencer"; 
    int largeurTexte = TailleChaineEcran(texte, 2); 
    int texteX = boutonX + (boutonLargeur / 2) - (largeurTexte / 2); 
    int texteY = boutonY + (boutonHauteur / 2) - (TailleSupPolice(2) / 2); 
    EcrireTexte(texteX, texteY, texte, 2); 
}
