#include "Blocus.h"
#include "errno.h"

int fondMenu;
int fondJeu1;
int fondJeu2;

void chargerSprites() {

    int fondMenu;
    int fondJeu1;
    int fondJeu2;

    fondMenu = ChargerSprite(IMAGE_MENU);   
    fondJeu1 = ChargerSprite(IMAGE_FOND1);  
    fondJeu2 = ChargerSprite(IMAGE_FOND2);  

    //J'ai ajouté ça pour vérifier d'où venait l'erreur (C'était le format de l'image) (Je sais pas si on les retires ou si on les laisses)
    
    if (fondMenu == -1) {
        fprintf(stderr, "Erreur de chargement de l'image du menu : %s (code d'erreur: %d)\n", IMAGE_MENU, errno);
    }

    if (fondJeu1 == -1) {
        fprintf(stderr, "Erreur de chargement de l'image de fond 1 : %s (code d'erreur: %d)\n", IMAGE_FOND1, errno );
    }
    if (fondJeu2 == -1) {
        fprintf(stderr, "Erreur de chargement de l'image de fond 2 : %s (code d'erreur: %d)\n", IMAGE_FOND2, errno);
    }

    if (fondMenu == -1 || fondJeu1 == -1 || fondJeu2 == -1) {
        exit(EXIT_FAILURE);
    }
}


void afficherFondMenu() {
    ChargerImageFond(IMAGE_MENU);  // Remplit l'écran avec l'image du menu
}

void afficherFondJeu1() {
    ChargerImageFond(IMAGE_FOND1); // Affiche l'image de fond 1 à la taille de la fenêtre
}

void afficherFondJeu2() {
    ChargerImageFond(IMAGE_FOND2); // Affiche l'image de fond 2 à la taille de la fenêtre
}

void libererSprites() {
    LibererSprite(fondMenu);
    LibererSprite(fondJeu1);
    LibererSprite(fondJeu2);
}

void TailleJeux() {

    int i;
    int taille;
    int optionX;
    int optionY; 
    int caseX; 
    int caseY; 
    int caseSize;
    char optionText[10]; 
    int boutonLargeur;
    int boutonHauteur; 
    int boutonX;
    int boutonY;
    char *texte = "Commencer"; 
    int largeurTexte; 
    int texteX; 
    int texteY; 
    //Coordonnées pour le texte de la taille de la grille/plateau
    int PositionTexteX = 120; 
    int PositionTexteY = 145; 

    afficherFondMenu(); 

    // Texte pour le titre
    ChoisirCouleurDessin(CouleurParNom("white")); 
    EcrireTexte(120, 80, "Choisissez la taille de la grille :", 2);

    for (i = 0; i < MAX_OPTIONS; i++) {

        taille = i + 3; 
        optionX = 75; 
        optionY = 130 + (i * 30); 
        caseX = optionX + 150; 
        caseY = optionY - 5; 
        caseSize = 20; 

        ChoisirCouleurDessin(CouleurParNom("white"));
        RemplirRectangle(caseX, caseY, caseSize, caseSize);
        if (casesCochees[i]) { 
            ChoisirCouleurDessin(CouleurParNom("red")); 
            RemplirRectangle(caseX + 2, caseY + 2, caseSize - 4, caseSize - 4); // Fond rouge si cochée
        }

        sprintf(optionText, "%dx%d", taille, taille);
        ChoisirCouleurDessin(CouleurParNom("white")); 
        EcrireTexte(PositionTexteX, PositionTexteY + (i * 30), optionText, 2);
    }

    // Ajout "COMMENCER"
    boutonLargeur = LARGEUR_BOUTON; 
    boutonHauteur = HAUTEUR_BOUTON; 
    boutonX = (LARGEUR_FENETRE - boutonLargeur) / 2; // Centrer 
    boutonY = 400; // Position du bouton

    ChoisirCouleurDessin(CouleurParNom("red")); 
    RemplirRectangle(boutonX, boutonY, boutonLargeur, boutonHauteur); 

    ChoisirCouleurDessin(CouleurParNom("black")); 
    DessinerRectangle(boutonX, boutonY, boutonLargeur, boutonHauteur); 

    ChoisirCouleurDessin(CouleurParNom("black")); 
    largeurTexte = TailleChaineEcran(texte, 2); 
    texteX = boutonX + (boutonLargeur / 2) - (largeurTexte / 2); 
    texteY = boutonY + boutonHauteur - (TailleSupPolice(2) / 2); 
    EcrireTexte(texteX, texteY, texte, 2); 

    afficherOptionsJoueurs(); 
}
