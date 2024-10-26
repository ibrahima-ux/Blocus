#include "Blocus.h"
#include <time.h>



void afficherOptionsJoueurs() {
    int optionY = HAUTEUR_FENETRE * 0.3;

    ChoisirCouleurDessin(modeJeu == 1 ? CouleurParNom("red") : CouleurParNom("lightgray"));
    RemplirRectangle(LARGEUR_FENETRE * 0.75, optionY, LARGEUR_FENETRE * 0.2, 40);
    ChoisirCouleurDessin(CouleurParNom("black"));
    EcrireTexte(LARGEUR_FENETRE * 0.75 + 35, optionY + 30, "1 Joueur", 2);

    ChoisirCouleurDessin(modeJeu == 2 ? CouleurParNom("red") : CouleurParNom("lightgray"));
    RemplirRectangle(LARGEUR_FENETRE * 0.75, optionY + 50, LARGEUR_FENETRE * 0.2, 40);
    ChoisirCouleurDessin(CouleurParNom("black"));
    EcrireTexte(LARGEUR_FENETRE * 0.75 + 35, optionY + 80, "2 Joueurs", 2);
}

void gererChoixJoueurs(int positionSourisX, int positionSourisY) {
    int boutonY1 = HAUTEUR_FENETRE * 0.3;
    int boutonY2 = boutonY1 + 50;

    if (positionSourisX >= LARGEUR_FENETRE * 0.75 && positionSourisX <= LARGEUR_FENETRE * 0.95 &&
        positionSourisY >= boutonY1 && positionSourisY <= boutonY1 + 40) {
        modeJeu = (modeJeu == 1) ? 0 : 1;
    }

    if (positionSourisX >= LARGEUR_FENETRE * 0.75 && positionSourisX <= LARGEUR_FENETRE * 0.95 &&
        positionSourisY >= boutonY2 && positionSourisY <= boutonY2 + 40) {
        modeJeu = (modeJeu == 2) ? 0 : 2;
    }

    EffacerEcran(CouleurParNom("lightblue"));
    TailleJeux();
    afficherOptionsJoueurs();
}


void mouvementIA(int *x, int *y, int taille) {
    int newX, newY;
    do {
        newX = *x + (rand() % 3 - 1);
        newY = *y + (rand() % 3 - 1);
    } while (newX < 0 || newX >= taille || newY < 0 || newY >= taille || grille[newX][newY] != ' ');

    deplacerPion(2, x, y, newX, newY);
    int blockX, blockY;
    do {
        blockX = rand() % taille;
        blockY = rand() % taille;
    } while (grille[blockX][blockY] != ' ');
    condamnerCase(blockX, blockY);
}
int estPartieTerminee(int joueurX, int joueurY, int taille) {
    return !deplacementPossible(joueurX, joueurY, taille);
}