#include "Blocus.h"

void gererInteractions(int positionSourisX, int positionSourisY) {
    // Vérifie la sélection de taille de grille
    for (int i = 0; i < MAX_OPTIONS; i++) {
        int caseX = 75 + 150;  // Position X des options de taille
        int caseY = 130 + (i * 30) - 5;  // Position Y des options de taille

        // Si la souris clique sur une case de taille, on la sélectionne
        if (positionSourisX >= caseX && positionSourisX <= caseX + 20 &&
            positionSourisY >= caseY && positionSourisY <= caseY + 20) {
            
            // Décocher toutes les cases
            for (int j = 0; j < MAX_OPTIONS; j++) {
                casesCochees[j] = 0;
            }
            casesCochees[i] = 1;  // Cocher la case sélectionnée pour la taille
            choisirTaille = i + 3;  // Mettre à jour la taille choisie (entre 3 et 9)
            TailleJeux();  // Rafraîchir l'affichage de la sélection de taille
            break;
        }
    }

    // Vérifie la sélection du mode de jeu
    int boutonY1 = HAUTEUR_FENETRE * 0.3;  // Position Y pour le bouton "1 Joueur"
    int boutonY2 = boutonY1 + 50;  // Position Y pour le bouton "2 Joueurs"

    // Si clic dans la zone de "1 Joueur"
    if (positionSourisX >= LARGEUR_FENETRE * 0.75 && positionSourisX <= LARGEUR_FENETRE * 0.95 &&
        positionSourisY >= boutonY1 && positionSourisY <= boutonY1 + 40) {
        modeJeu = 1;  // Sélectionne le mode "1 Joueur"
    }

    // Si clic dans la zone de "2 Joueurs"
    if (positionSourisX >= LARGEUR_FENETRE * 0.75 && positionSourisX <= LARGEUR_FENETRE * 0.95 &&
        positionSourisY >= boutonY2 && positionSourisY <= boutonY2 + 40) {
        modeJeu = 2;  // Sélectionne le mode "2 Joueurs"
    }

    // Rafraîchir l'affichage pour montrer les options sélectionnées
    afficherFondMenu();
    TailleJeux();
    afficherOptionsJoueurs();
}


// Gère le déplacement et la condamnation pour chaque clic
void gererMouvement(int joueur, int x, int y, int newX, int newY, int taille) {
    if (grille[newX][newY] == ' ') {
        deplacerPion(joueur, &x, &y, newX, newY);  // Déplace le pion
        int blockX, blockY;
        
        // Condamner une case adjacente libre
        do {
            printf("Choisissez une case à bloquer (x, y) : ");
            scanf("%d %d", &blockX, &blockY);
        } while (grille[blockX][blockY] != ' '); 

        condamnerCase(blockX, blockY);
        
        if (estPartieTerminee(newX, newY, taille)) {
            printf("Le joueur %d a perdu !\n", joueur);
        }
    }
}




void placerSpritePion(int ligne, int colonne, char type, int joueur, int taille) {
    int cell_size = 50;
    int x_start = (LARGEUR_FENETRE - (taille * cell_size)) / 2;
    int y_start = (HAUTEUR_FENETRE - (taille * cell_size)) / 2;

    // Calcul de la position centrale dans la cellule
    int x = x_start + colonne * cell_size + (cell_size - 25) / 2;
    int y = y_start + ligne * cell_size + (cell_size - 25) / 2;

    // Sélectionne et affiche le sprite en fonction du joueur et du type de pion
    if (joueur == 1) {
        if (type == 'X') {
            AfficherSprite(spriteCroixBleue, x, y);  // Affiche la croix bleue pour le joueur 1
        } else if (type == 'P') {
            AfficherSprite(spritePionBleu, x, y);    // Affiche le pion bleu pour le joueur 1
        }
    } else if (joueur == 2) {
        if (type == 'X') {
            AfficherSprite(spriteCroixRouge, x, y);  // Affiche la croix rouge pour le joueur 2
        } else if (type == 'P') {
            AfficherSprite(spritePionRouge, x, y);   // Affiche le pion rouge pour le joueur 2
        }
    }
}
void gererClicGrille(int positionSourisX, int positionSourisY, int joueur, int taille) {
    int cell_size = 50;
    int sprite_size = 25;
    int x_start = (LARGEUR_FENETRE - (taille * cell_size)) / 2;
    int y_start = (HAUTEUR_FENETRE - (taille * cell_size)) / 2;

    int colonne = (positionSourisX - x_start) / cell_size;
    int ligne = (positionSourisY - y_start) / cell_size;

    // Vérifie si la position cliquée est dans les limites de la grille
    if (ligne >= 0 && ligne < taille && colonne >= 0 && colonne < taille) {
        if (etapePlacement == 1) {  // Déplacement du pion
            if (grille[ligne][colonne] == ' ') {  // Vérifie que la case est libre
                // Efface la position précédente du pion graphiquement si elle ne contient pas une croix
                int oldX, oldY;
                if (joueur == 1) {
                    oldX = joueur1X;
                    oldY = joueur1Y;
                    joueur1X = ligne;  // Met à jour la nouvelle position de Joueur 1
                    joueur1Y = colonne;
                    grille[ligne][colonne] = 'P';  // Place le pion à la nouvelle position

                    // Efface l'ancienne position si nécessaire
                    if (grille[oldX][oldY] != 'X' && (oldX != joueur1X || oldY != joueur1Y)) {
                        grille[oldX][oldY] = ' ';  // Vide l'ancienne case
                        ChoisirCouleurDessin(CouleurParNom("white"));
                        RemplirRectangle(x_start + oldY * cell_size, y_start + oldX * cell_size, cell_size, cell_size);
                        // Redessine la bordure de la case
                        ChoisirCouleurDessin(CouleurParNom("black"));
                        DessinerRectangle(x_start + oldY * cell_size, y_start + oldX * cell_size, cell_size, cell_size);
                    }

                    // Affiche le pion bleu dans la nouvelle position
                    AfficherSprite(spritePionBleu, x_start + colonne * cell_size + (cell_size - sprite_size) / 2,
                                   y_start + ligne * cell_size + (cell_size - sprite_size) / 2);
                } else {
                    oldX = joueur2X;
                    oldY = joueur2Y;
                    joueur2X = ligne;  // Met à jour la nouvelle position de Joueur 2
                    joueur2Y = colonne;
                    grille[ligne][colonne] = 'p';  // Place le pion à la nouvelle position

                    // Efface l'ancienne position si nécessaire
                    if (grille[oldX][oldY] != 'X' && (oldX != joueur2X || oldY != joueur2Y)) {
                        grille[oldX][oldY] = ' ';  // Vide l'ancienne case
                        ChoisirCouleurDessin(CouleurParNom("white"));
                        RemplirRectangle(x_start + oldY * cell_size, y_start + oldX * cell_size, cell_size, cell_size);
                        // Redessine la bordure de la case
                        ChoisirCouleurDessin(CouleurParNom("black"));
                        DessinerRectangle(x_start + oldY * cell_size, y_start + oldX * cell_size, cell_size, cell_size);
                    }

                    // Affiche le pion rouge dans la nouvelle position
                    AfficherSprite(spritePionRouge, x_start + colonne * cell_size + (cell_size - sprite_size) / 2,
                                   y_start + ligne * cell_size + (cell_size - sprite_size) / 2);
                }

                // Passe à l'étape suivante pour placer la croix
                etapePlacement = 2;

            } else {
                afficherMessageGraphique("Case déjà occupée. Choisissez une autre.");
            }
        } else if (etapePlacement == 2) {  // Placement de la croix
            if (grille[ligne][colonne] == ' ') {  // Vérifie que la case est libre pour la condamnation
                grille[ligne][colonne] = 'X';  // Condamne la case
                int x = x_start + colonne * cell_size + (cell_size - sprite_size) / 2;
                int y = y_start + ligne * cell_size + (cell_size - sprite_size) / 2;

                if (joueur == 1) {
                    AfficherSprite(spriteCroixBleue, x, y);
                } else {
                    AfficherSprite(spriteCroixRouge, x, y);
                }

                // Retourne à l'étape de déplacement du pion pour le prochain joueur
                etapePlacement = 1;
                tourJoueur = (tourJoueur == 1) ? 2 : 1;  // Change de joueur
            } else {
                afficherMessageGraphique("Case déjà occupée. Choisissez une autre.");
            }
        }
    }
}








