#include "Blocus.h"

void afficherOptionsJoueurs() {
    int optionY = HAUTEUR_FENETRE * 0.3; // Position Y pour afficher les options

    // Cadre "1 Joueur"

    ChoisirCouleurDessin(modeJeu == 1 ? CouleurParNom("red") : CouleurParNom("lightgray"));
    RemplirRectangle(LARGEUR_FENETRE * 0.75, optionY, LARGEUR_FENETRE * 0.2, 40); // Ajustez la position
    ChoisirCouleurDessin(CouleurParNom("black"));
    EcrireTexte(LARGEUR_FENETRE * 0.75 + 10, optionY + 10, "1 Joueur", 2); // centré

    // Cadre  "2 Joueurs"
    ChoisirCouleurDessin(modeJeu == 2 ? CouleurParNom("red") : CouleurParNom("lightgray"));
    RemplirRectangle(LARGEUR_FENETRE * 0.75, optionY + 50, LARGEUR_FENETRE * 0.2, 40); 
    ChoisirCouleurDessin(CouleurParNom("black"));
    EcrireTexte(LARGEUR_FENETRE * 0.75 + 10, optionY + 60, "2 Joueurs", 2); 
}

void gererChoixJoueurs(int positionSourisX, int positionSourisY) {
    int boutonY1 = HAUTEUR_FENETRE * 0.3; // Position Y pour "1 Joueur"
    int boutonY2 = boutonY1 + 50; // Position Y pour "2 Joueurs"

    //  choix "1 Joueur"
    if (positionSourisX >= LARGEUR_FENETRE * 0.75 && positionSourisX <= LARGEUR_FENETRE * 0.95 &&
        positionSourisY >= boutonY1 && positionSourisY <= boutonY1 + 40) {
        modeJeu = (modeJeu == 1) ? 0 : 1; // Permet de décocher si déjà sélectionné
    }

    //  choix "2 Joueurs"
    if (positionSourisX >= LARGEUR_FENETRE * 0.75 && positionSourisX <= LARGEUR_FENETRE * 0.95 &&
        positionSourisY >= boutonY2 && positionSourisY <= boutonY2 + 40) {
        modeJeu = (modeJeu == 2) ? 0 : 2; 
    }


     EffacerEcran(CouleurParNom("lightblue"));
    TailleJeux(); 
    afficherOptionsJoueurs(); 
}

