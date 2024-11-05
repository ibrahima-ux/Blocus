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
    int blockX,blockY;
    if (grille[newX][newY] == ' ') {
        deplacerPion(joueur, &x, &y, newX, newY); 
        blockX, blockY;
        
       
        do {
            printf("Choisissez une case à bloquer (x, y) : ");
            scanf("%d %d", &blockX, &blockY);
        } while (grille[blockX][blockY] != ' '); 

        condamnerCase(blockX, blockY);
        
        if (estPartieTerminee(newX, newY, taille)) {
            printf("Le joueur  %d a perdu !\n", joueur);
        }
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
    int oldX,oldY;
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
            if (grille[ligne][colonne] == ' ') {  
             
                oldX, oldY;
                if (joueur == 1) {
                    oldX = joueur1X;
                    oldY = joueur1Y;
                    joueur1X = ligne;  
                    joueur1Y = colonne;
                    grille[ligne][colonne] = 'P';  

                   
                    if (grille[oldX][oldY] != 'X' && (oldX != joueur1X || oldY != joueur1Y)) {
                        grille[oldX][oldY] = ' ';  
                        ChoisirCouleurDessin(CouleurParNom("white"));
                        RemplirRectangle(x_start + oldY * cell_size, y_start + oldX * cell_size, cell_size, cell_size);
                        
                        ChoisirCouleurDessin(CouleurParNom("black"));
                        DessinerRectangle(x_start + oldY * cell_size, y_start + oldX * cell_size, cell_size, cell_size);
                    }

                    
                    AfficherSprite(spritePionBleu, x_start + colonne * cell_size + (cell_size - sprite_size) / 2,
                                   y_start + ligne * cell_size + (cell_size - sprite_size) / 2);
                } else {
                    oldX = joueur2X;
                    oldY = joueur2Y;
                    joueur2X = ligne;  
                    joueur2Y = colonne;
                    grille[ligne][colonne] = 'p';  

                    
                    if (grille[oldX][oldY] != 'X' && (oldX != joueur2X || oldY != joueur2Y)) {
                        grille[oldX][oldY] = ' ';  
                        ChoisirCouleurDessin(CouleurParNom("white"));
                        RemplirRectangle(x_start + oldY * cell_size, y_start + oldX * cell_size, cell_size, cell_size);
                       
                        ChoisirCouleurDessin(CouleurParNom("black"));
                        DessinerRectangle(x_start + oldY * cell_size, y_start + oldX * cell_size, cell_size, cell_size);
                    }

                    
                    AfficherSprite(spritePionRouge, x_start + colonne * cell_size + (cell_size - sprite_size) / 2,
                                   y_start + ligne * cell_size + (cell_size - sprite_size) / 2);
                }

            
                etapePlacement = 2;

            } else {
                afficherMessageGraphique("Case occupee. Choisissez une autre.");
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
                afficherMessageGraphique("Case occupee. Choisissez une autre.");
            }
        }
    }
}








