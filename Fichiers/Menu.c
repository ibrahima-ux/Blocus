#include "Blocus.h"
#include "BlocusAffichage.h"
#include <graph.h>

#define CYCLE 10000L  
int casesCochees[MAX_OPTIONS] = {0}; 
int choisirTaille = 0;
int modeJeu = 0;
int etatJeu = 1; 
int tourJoueur = 1;  
int etapePlacement = 1;  
int joueur1X = 0, joueur1Y = 0;
int joueur2X = 0, joueur2Y = 0;



int main(void) {
    int positionSourisX, positionSourisY;
    unsigned long suivant = Microsecondes() + CYCLE;

    if (InitialiserGraphique() == -1) {
        fprintf(stderr, "Erreur lors de l'initialisation graphique.\n");
        return EXIT_FAILURE;
    }

    //Fenetre graphique
    CreerFenetre(20, 20, LARGEUR_FENETRE, HAUTEUR_FENETRE);
    chargerSprites();
    chargerSpritesPions();
    afficherFondMenu();
    TailleJeux();

    int grilleAffichee = 0;

while (1) {
    if (SourisCliquee()) {
        SourisPosition();
        positionSourisX = _X;
        positionSourisY = _Y;

        if (etatJeu == 1) {  
            gererInteractions(positionSourisX, positionSourisY);
            afficherGrilleSiValidee(positionSourisX, positionSourisY);

            int boutonX = (LARGEUR_FENETRE - LARGEUR_BOUTON) / 2;
            int boutonY = 400;

            if (positionSourisX >= boutonX && positionSourisX <= boutonX + LARGEUR_BOUTON &&
                positionSourisY >= boutonY && positionSourisY <= boutonY + HAUTEUR_BOUTON) {
                
                if (choisirTaille >= 3 && choisirTaille <= 9 && modeJeu != 0) {
                    EffacerEcran(CouleurParNom("white"));

                    if (modeJeu == 1) {
                        afficherFondJeu1();
                    } else if (modeJeu == 2) {
                        afficherFondJeu2();
                    }

                    initialiserJeu(choisirTaille);
                    afficherGrilleJeu(choisirTaille);
                    afficherMessageGraphique("Joueur 1 : Placez votre pion.");

                    grilleAffichee = 1;
                    etatJeu = 2; 
                    tourJoueur = 1;
                    etapePlacement = 1;
                } else {
                    afficherMessageGraphique("Veuillez choisir une taille et un mode de jeu.");
                }
            }
        } 
        else if (etatJeu == 2) {  
            // Mode 1 joueur (Joueur contre IA) 
            if (modeJeu == 1) {
                if (tourJoueur == 1) {  
                    if (etapePlacement == 1) { 
                        afficherMessageGraphique("Joueur 1 : Placez votre pion.");
                        gererClicGrille(positionSourisX, positionSourisY, 1, choisirTaille);
                        etapePlacement = 2;  
                    } else if (etapePlacement == 2) {  
                        afficherMessageGraphique("Joueur 1 : Placez votre croix.");
                        gererClicGrille(positionSourisX, positionSourisY, 1, choisirTaille);
                        etapePlacement = 1;  // Passe au tour de l'IA
                        tourJoueur = 2;
                    }

                    
                    if (estPartieTerminee(joueur1X, joueur1Y, choisirTaille)) {
                        etatJeu = 3;      
                        afficherScore(2);  
                    }
                }
            }

            // Mode 2 joueurs (Humain contre humain) 
            else if (modeJeu == 2) {
                if (tourJoueur == 1) {  
                    if (etapePlacement == 1) {  
                        afficherMessageGraphique("Joueur 1 : Placez votre pion.");
                        gererClicGrille(positionSourisX, positionSourisY, 1, choisirTaille);
                        etapePlacement = 2;  
                    } else if (etapePlacement == 2) {  
                        afficherMessageGraphique("Joueur 1 : Placez votre croix.");
                        gererClicGrille(positionSourisX, positionSourisY, 1, choisirTaille);
                        etapePlacement = 1;  
                        tourJoueur = 2;
                    }

                    
                    if (estPartieTerminee(joueur1X, joueur1Y, choisirTaille)) {
                        etatJeu = 3;       
                        afficherScore(2);  
                    }
                } 
                else if (tourJoueur == 2) {  // Tour du Joueur 2
                    if (etapePlacement == 1) {  
                        afficherMessageGraphique("Joueur 2 : Placez votre pion.");
                        gererClicGrille(positionSourisX, positionSourisY, 2, choisirTaille);
                        etapePlacement = 2;  
                    } else if (etapePlacement == 2) {  
                        afficherMessageGraphique("Joueur 2 : Placez votre croix.");
                        gererClicGrille(positionSourisX, positionSourisY, 2, choisirTaille);
                        etapePlacement = 1;  
                        tourJoueur = 1;
                    }

                    
                    if (estPartieTerminee(joueur2X, joueur2Y, choisirTaille)) {
                        etatJeu = 3;      
                        afficherScore(1);  
                    }
                }
            }
        }

        // Tour du Joueur 2 (IA) sans clic pour le mode 1 joueur
        if (etatJeu == 2 && modeJeu == 1 && tourJoueur == 2) {  
            mouvementIA(&joueur2X, &joueur2Y, choisirTaille);  

           
            if (estPartieTerminee(joueur2X, joueur2Y, choisirTaille)) {
                etatJeu = 3;      
                afficherScore(1);  
            } else {
                tourJoueur = 1;  
            }

          
        }

        // Gestion du mode fin de jeu avec retour au menu
        if (etatJeu == 3) {
            revenirAuMenu();  
            etatJeu = 1;      
        }
    }

    if (Microsecondes() > suivant) {
        suivant = Microsecondes() + CYCLE;
    }
}







    
    libererSprites();
    libererSpritesPions();
    FermerGraphique();
    return 0;
}



void afficherMessageGraphique(const char *message) {
    ChoisirCouleurDessin(CouleurParNom("black"));
    EcrireTexte(50, HAUTEUR_FENETRE - 30, (char *)message, 2);  
}


void afficherGrilleSiValidee(int positionSourisX, int positionSourisY) {
    int boutonX = (LARGEUR_FENETRE - LARGEUR_BOUTON) / 2;
    int boutonY = 400;

    if (choisirTaille >= 3 && choisirTaille <= 9 && modeJeu != 0) {
        if (positionSourisX >= boutonX && positionSourisX <= boutonX + LARGEUR_BOUTON &&
            positionSourisY >= boutonY && positionSourisY <= boutonY + HAUTEUR_BOUTON) {
            
            static int grilleAffichee = 0;

            if (!grilleAffichee) {
                EffacerEcran(CouleurParNom("white"));

                
                if (modeJeu == 1) {
                    afficherFondJeu1();
                } else if (modeJeu == 2) {
                    afficherFondJeu2();
                }

                initialiserJeu(choisirTaille);  
                afficherGrilleJeu(choisirTaille); 
                afficherMessageGraphique("Cliquez sur la grille pour jouer.");

                grilleAffichee = 1; 
            }
        }
    } else {
        if (positionSourisX >= boutonX && positionSourisX <= boutonX + LARGEUR_BOUTON &&
            positionSourisY >= boutonY && positionSourisY <= boutonY + HAUTEUR_BOUTON) {
            afficherMessageGraphique("Veuillez choisir une taille et un mode de jeu.");
        }
    }
}
