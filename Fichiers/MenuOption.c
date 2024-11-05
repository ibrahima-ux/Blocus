#include "Blocus.h"
#include "BlocusAffichage.h"
#include <time.h>


int spritePionIA = -1;

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
    int validMove = 0;
    int cell_size = 50;
    int x_start = (LARGEUR_FENETRE - (taille * cell_size)) / 2;
    int y_start = (HAUTEUR_FENETRE - (taille * cell_size)) / 2;

    // Efface l'ancienne position
    grille[*x][*y] = ' ';
    ChoisirCouleurDessin(CouleurParNom("white"));
    RemplirRectangle(x_start + (*y) * cell_size, y_start + (*x) * cell_size, cell_size, cell_size);
    DessinerRectangle(x_start + (*y) * cell_size, y_start + (*x) * cell_size, cell_size, cell_size);

    // Boucle pour trouver une nouvelle position adjacente
    while (!validMove) {
        newX = *x + (rand() % 3 - 1);  // Génère -1, 0 ou +1
        newY = *y + (rand() % 3 - 1);

        // Limite le mouvement aux cases adjacentes sans utiliser abs()
        if ((newX - *x >= -1 && newX - *x <= 1) && 
            (newY - *y >= -1 && newY - *y <= 1) &&
            newX >= 0 && newX < taille && newY >= 0 && newY < taille && grille[newX][newY] == ' ') {
            validMove = 1;
        }
    }

    *x = newX;
    *y = newY;
    grille[newX][newY] = 'B';

    int posX = x_start + newY * cell_size + (cell_size - 25) / 2;
    int posY = y_start + newX * cell_size + (cell_size - 25) / 2;
    AfficherSprite(spritePionRouge, posX, posY);

    // Choix d'une case à bloquer
    int blockX, blockY, attempt = 0;
    do {
        blockX = rand() % taille;
        blockY = rand() % taille;
        attempt++;
    } while (grille[blockX][blockY] != ' ' && attempt < 50);

    if (grille[blockX][blockY] == ' ') {
        grille[blockX][blockY] = 'X';
        placerSpritePion(blockX, blockY, 'X', 2, taille);
    }
}






 
int estPartieTerminee(int x, int y, int taille) {
    int newX,newY,i;
    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};  
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1}; 

    for (i = 0; i < 8; i++) {
        newX = x + dx[i];
         newY = y + dy[i];

        
        if (newX >= 0 && newX < taille && newY >= 0 && newY < taille) {
            
            if (grille[newX][newY] == ' ') {
                return 0; 
            }
        }
    }

    
    return 1;
}
