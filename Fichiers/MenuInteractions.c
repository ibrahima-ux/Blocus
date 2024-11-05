#include "Blocus.h"
#include "BlocusAffichage.h"

void gererInteractions(int positionSourisX, int positionSourisY) {
    int i,j,caseX,caseY,boutonY1,boutonY2;
    
    for (i = 0; i < MAX_OPTIONS; i++) {
         caseX = 75 + 150;  
         caseY = 130 + (i * 30) - 5;  

        
        if (positionSourisX >= caseX && positionSourisX <= caseX + 20 &&
            positionSourisY >= caseY && positionSourisY <= caseY + 20) {
            
            
            for (int j = 0; j < MAX_OPTIONS; j++) {
                casesCochees[j] = 0;
            }
            casesCochees[i] = 1;  
            choisirTaille = i + 3;  
            TailleJeux();  
            break;
        }
    }

    
     boutonY1 = HAUTEUR_FENETRE * 0.3;  
     boutonY2 = boutonY1 + 50;  

    
    if (positionSourisX >= LARGEUR_FENETRE * 0.75 && positionSourisX <= LARGEUR_FENETRE * 0.95 &&
        positionSourisY >= boutonY1 && positionSourisY <= boutonY1 + 40) {
        modeJeu = 1;  
    }

   
    if (positionSourisX >= LARGEUR_FENETRE * 0.75 && positionSourisX <= LARGEUR_FENETRE * 0.95 &&
        positionSourisY >= boutonY2 && positionSourisY <= boutonY2 + 40) {
        modeJeu = 2;  
    }

    
    afficherFondMenu();
    TailleJeux();
    afficherOptionsJoueurs();
}



void gererMouvement(int joueur, int x, int y, int newX, int newY, int taille) {
    int dx = newX - x;
    int dy = newY - y;

    // Vérifie que le déplacement est dans les cases adjacentes uniquement (sans utiliser abs())
    if ((dx >= -1 && dx <= 1) && (dy >= -1 && dy <= 1) && grille[newX][newY] == ' ') {
        deplacerPion(joueur, &x, &y, newX, newY);

        // Choix de la case à bloquer
        int blockX, blockY;
        do {
            printf("Choisissez une case à bloquer (x, y) : ");
            scanf("%d %d", &blockX, &blockY);
        } while (grille[blockX][blockY] != ' ');

        condamnerCase(blockX, blockY);

        // Vérifie si la partie est terminée
        if (estPartieTerminee(newX, newY, taille)) {
            printf("Le joueur %d a perdu !\n", joueur);
        }
    } else {
        printf("Déplacement invalide. Vous ne pouvez déplacer le pion que vers une case adjacente libre.\n");
    }
}





void placerSpritePion(int ligne, int colonne, char type, int joueur, int taille) {
    int cell_size = 50;
    int x_start = (LARGEUR_FENETRE - (taille * cell_size)) / 2;
    int y_start = (HAUTEUR_FENETRE - (taille * cell_size)) / 2;

    
    int x = x_start + colonne * cell_size + (cell_size - 25) / 2;
    int y = y_start + ligne * cell_size + (cell_size - 25) / 2;

    
    if (joueur == 1) {
        if (type == 'X') {
            AfficherSprite(spriteCroixBleue, x, y);  
        } else if (type == 'P') {
            AfficherSprite(spritePionBleu, x, y);    
        }
    } else if (joueur == 2) {
        if (type == 'X') {
            AfficherSprite(spriteCroixRouge, x, y);  
        } else if (type == 'P') {
            AfficherSprite(spritePionRouge, x, y);  
        }
    }
}


void gererClicGrille(int positionSourisX, int positionSourisY, int joueur, int taille) {
    int oldX, oldY;
    int cell_size = 50;
    int sprite_size = 25;
    int x_start = (LARGEUR_FENETRE - (taille * cell_size)) / 2;
    int y_start = (HAUTEUR_FENETRE - (taille * cell_size)) / 2;

    int colonne = (positionSourisX - x_start) / cell_size;
    int ligne = (positionSourisY - y_start) / cell_size;

    if (ligne >= 0 && ligne < taille && colonne >= 0 && colonne < taille) {
        
        if (modeJeu == 1 && joueur == 2) {
            return; 
        }
        
        if (etapePlacement == 1) {  
            int dx = ligne - (joueur == 1 ? joueur1X : joueur2X);
            int dy = colonne - (joueur == 1 ? joueur1Y : joueur2Y);
            
            // Permet le placement sans restriction lors du premier tour
            int isFirstMove = (joueur == 1 && joueur1X == 0 && joueur1Y == 0) || 
                              (joueur == 2 && joueur2X == 0 && joueur2Y == 0);

            
            if (isFirstMove || ((dx >= -1 && dx <= 1) && (dy >= -1 && dy <= 1) && grille[ligne][colonne] == ' ')) {
                oldX = (joueur == 1) ? joueur1X : joueur2X;
                oldY = (joueur == 1) ? joueur1Y : joueur2Y;

                if (joueur == 1) {
                    joueur1X = ligne;  
                    joueur1Y = colonne;
                    grille[ligne][colonne] = 'A';
                } else {
                    joueur2X = ligne;  
                    joueur2Y = colonne;
                    grille[ligne][colonne] = 'B';
                }

                
                if (grille[oldX][oldY] != 'X') {
                    grille[oldX][oldY] = ' ';  
                    ChoisirCouleurDessin(CouleurParNom("white"));
                    RemplirRectangle(x_start + oldY * cell_size, y_start + oldX * cell_size, cell_size, cell_size);
                    ChoisirCouleurDessin(CouleurParNom("black"));
                    DessinerRectangle(x_start + oldY * cell_size, y_start + oldX * cell_size, cell_size, cell_size);
                }

               
                if (joueur == 1) {
                    AfficherSprite(spritePionBleu, x_start + colonne * cell_size + (cell_size - sprite_size) / 2,
                                   y_start + ligne * cell_size + (cell_size - sprite_size) / 2);
                } else {
                    AfficherSprite(spritePionRouge, x_start + colonne * cell_size + (cell_size - sprite_size) / 2,
                                   y_start + ligne * cell_size + (cell_size - sprite_size) / 2);
                }
                etapePlacement = 2;
            } else {
                afficherMessageGraphique("Déplacement invalide. Case non adjacente.");
            }
        } else if (etapePlacement == 2) {  
            if (grille[ligne][colonne] == ' ') {  
                grille[ligne][colonne] = 'X';
                int x = x_start + colonne * cell_size + (cell_size - sprite_size) / 2;
                int y = y_start + ligne * cell_size + (cell_size - sprite_size) / 2;

                if (joueur == 1) {
                    AfficherSprite(spriteCroixBleue, x, y);
                } else {
                    AfficherSprite(spriteCroixRouge, x, y);
                }
                
                etapePlacement = 1;
                tourJoueur = (tourJoueur == 1) ? 2 : 1;
            } else {
                afficherMessageGraphique("Case occupée. Choisissez une autre case pour la croix.");
            }
        }
    }
}
