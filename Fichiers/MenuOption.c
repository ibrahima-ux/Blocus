#include "MenuOption.h"
#include "CreationGrille.h"
#include "MenuInteractions.h"
#include <graph.h>
#include "constantes.h"
#include <time.h>
#include "MenuAffichage.h"
#include "Sprites.h"
#include <stdlib.h> 



extern int joueur1X, joueur1Y;

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
    int newX, newY,i, k,randomDirection, attempt;
    int dx[] = {1, 0, 0, -1};  /* Priorité de directions : bas, droite, gauche, haut */
    int dy[] = {0, 1, -1, 0};
    int cell_size = 50;
    int x_start = (LARGEUR_FENETRE - (taille * cell_size)) / 2;
    int y_start = (HAUTEUR_FENETRE - (taille * cell_size)) / 2;
    int border_thickness = 3;  /* Épaisseur de bordure cohérente avec celle définie dans afficherGrilleJeu() */
    int bx, by;
    int foundMove = 0;  
  int posX, posY;
   int blockX = -1, blockY = -1;

    for (i = 0; i < 4; i++) {
        newX = *x + dx[i];
        newY = *y + dy[i];

        if (newX >= 0 && newX < taille && newY >= 0 && newY < taille && grille[newX][newY] == ' ') {
            foundMove = 1;
            break;
        }
    }

    if (!foundMove) {
        srand(time(NULL));  /* Initialiser le générateur de nombres aléatoires */

        for (attempt = 0; attempt < 10; attempt++) {  /* Limite à 10 tentatives pour éviter une boucle infinie */
             randomDirection = rand() % 4;  /* Choisir une direction aléatoire */
            newX = *x + dx[randomDirection];
            newY = *y + dy[randomDirection];

            if (newX >= 0 && newX < taille && newY >= 0 && newY < taille && grille[newX][newY] == ' ') {
                foundMove = 1;
                break;
            }
        }
    }

    /* Déplacement si un mouvement valide est trouvé */
    if (foundMove) {
        /* Efface l'ancienne position */
        grille[*x][*y] = ' ';
        ChoisirCouleurDessin(CouleurParNom("white"));
        RemplirRectangle(x_start + (*y) * cell_size, y_start + (*x) * cell_size, cell_size, cell_size);
        
        /* Redessine la bordure de l'ancienne case */
        ChoisirCouleurDessin(CouleurParNom("black"));
        for (k = 0; k < border_thickness; k++) {
            DessinerRectangle(x_start + (*y) * cell_size + k, y_start + (*x) * cell_size + k, cell_size - 2 * k, cell_size - 2 * k);
        }

        /* Met à jour la position de l'IA */
        *x = newX;
        *y = newY;
        grille[newX][newY] = 'B';

         posX = x_start + newY * cell_size + (cell_size - 25) / 2;
        posY = y_start + newX * cell_size + (cell_size - 25) / 2;
        AfficherSprite(spritePionRouge, posX, posY);

        /* Redessine la bordure de la nouvelle case */
        ChoisirCouleurDessin(CouleurParNom("black"));
        for (k = 0; k < border_thickness; k++) {
            DessinerRectangle(x_start + newY * cell_size + k, y_start + newX * cell_size + k, cell_size - 2 * k, cell_size - 2 * k);
        }
    }

    /* Choix d'une case adjacente au joueur à bloquer */
    blockX = -1, blockY = -1;
    for (i = 0; i < 4; i++) {
         bx = joueur1X + dx[i];
        by = joueur1Y + dy[i];

        if (bx >= 0 && bx < taille && by >= 0 && by < taille && grille[bx][by] == ' ') {
            blockX = bx;
            blockY = by;
            break;
        }
    }

    if (blockX != -1 && blockY != -1) {
        grille[blockX][blockY] = 'X';
        placerSpritePion(blockX, blockY, 'X', 2, taille);

        /* Redessine la bordure de la case bloquée */
        ChoisirCouleurDessin(CouleurParNom("black"));
        for ( k = 0; k < border_thickness; k++) {
            DessinerRectangle(x_start + blockY * cell_size + k, y_start + blockX * cell_size + k, cell_size - 2 * k, cell_size - 2 * k);
        }
    }
}


 

