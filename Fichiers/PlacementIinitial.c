#include <stdio.h>
#include <stdlib.h>
#include "MenuInteractions.h"
#include <graph.h>
#include "PlacementInitial.h"  


void placerPionsInitialement(int taille) {
    int positionSourisX, positionSourisY;
    int joueurActuel = 1; /* Commence avec le joueur 1 */



    etapePlacement = 1; 

    while (joueurActuel <= 2) {
        if (modeJeu == 1 && joueurActuel == 2) { /* Mode IA */
            int iaX = 0, iaY = 0; /* Choisir une position de départ pour l'IA */
            do {
                iaX = rand() % taille;
                iaY = rand() % taille;
            } while (grille[iaX][iaY] != ' '); /* Trouver une case libre */

            /* Effacer l'ancienne case de l'IA s'il y en a une */
            if (grille[joueur2X][joueur2Y] != ' ') { 
                grille[joueur2X][joueur2Y] = ' ';  /* Réinitialiser la position précédente */
                ChoisirCouleurDessin(CouleurParNom("white"));
                RemplirRectangle((LARGEUR_FENETRE - (taille * 50)) / 2 + joueur2Y * 50, (HAUTEUR_FENETRE - (taille * 50)) / 2 + joueur2X * 50, 50, 50);
            }

            joueur2X = iaX;   
           joueur2Y = iaY;  
            grille[iaX][iaY] = 'B'; 
            placerSpritePion(iaX, iaY, 'P', 2, taille);
        } else { /* Placement manuel pour le joueur humain */
            

            while (1) {
                if (SourisCliquee()) {
                    SourisPosition();
                    positionSourisX = _X;
                    positionSourisY = _Y;

                    if (gererClicGrille(positionSourisX, positionSourisY, joueurActuel, taille)) {
                        break; /* Passe au joueur suivant une fois un placement valide effectué */
                    }
                }
            }
        }
        joueurActuel++; 
    }
}
