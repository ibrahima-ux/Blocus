#include "Blocus.h"

int fondMenu;
int fondJeu1;
int fondJeu2;

/*Jarrive pas a mettres le simages*/

void chargerSprites() {
    fondMenu = ChargerSprite(IMAGE_MENU);   
    fondJeu1 = ChargerSprite(IMAGE_FOND1);  
    fondJeu2 = ChargerSprite(IMAGE_FOND2);  
}

void afficherFondMenu() {
    EffacerEcran(CouleurParNom("white")); 
    AfficherSprite(fondMenu, 0, 0); 
}

void afficherFondJeu1() {
    EffacerEcran(CouleurParNom("white"));
    AfficherSprite(fondJeu1, 0, 0); 
}

void afficherFondJeu2() {
    EffacerEcran(CouleurParNom("white")); 
    AfficherSprite(fondJeu2, 0, 0); 
}

void libererSprites() {
    
    LibererSprite(fondMenu);
    LibererSprite(fondJeu1);
    LibererSprite(fondJeu2);
}

void TailleJeux() {
    afficherFondMenu(); 

    EcrireTexte(100, 50, "Choisissez la taille de la grille :", 2);

    for (int i = 0; i < MAX_OPTIONS; i++) {
        int taille = i + 3; 
        int optionX = 100; 
        int optionY = 100 + (i * 30); 
        int caseX = optionX + 150; 
        int caseY = optionY - 5; 
        int caseSize = 20; 

        ChoisirCouleurDessin(CouleurParNom("purple"));
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

    // Ajout "COMMENCER"
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

    afficherOptionsJoueurs(); 
}
