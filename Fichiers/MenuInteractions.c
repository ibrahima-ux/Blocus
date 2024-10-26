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
    int sprite_size = 25;  // Taille des sprites
    int x_start = (LARGEUR_FENETRE - (taille * cell_size)) / 2;
    int y_start = (HAUTEUR_FENETRE - (taille * cell_size)) / 2;

    int colonne = (positionSourisX - x_start) / cell_size;
    int ligne = (positionSourisY - y_start) / cell_size;

    if (ligne >= 0 && ligne < taille && colonne >= 0 && colonne < taille) {
        if (grille[ligne][colonne] == ' ') {  // Vérifie si la case est vide
            int x = x_start + colonne * cell_size + (cell_size - sprite_size) / 2;
            int y = y_start + ligne * cell_size + (cell_size - sprite_size) / 2;

            if (etapePlacement == 1) {  // Placement de la croix
                grille[ligne][colonne] = (joueur == 1) ? 'C' : 'c';  // Marque la case avec la croix
                if (joueur == 1) {
                    AfficherSprite(spriteCroixBleue, x, y);
                } else {
                    AfficherSprite(spriteCroixRouge, x, y);
                }
            } else if (etapePlacement == 2) {  // Placement du pion
                grille[ligne][colonne] = (joueur == 1) ? 'P' : 'p';  // Marque la case avec le pion
                if (joueur == 1) {
                    AfficherSprite(spritePionBleu, x, y);
                } else {
                    AfficherSprite(spritePionRouge, x, y);
                }
            }
        } else {
            afficherMessageGraphique("Case déjà occupée !");
        }
    }
}




