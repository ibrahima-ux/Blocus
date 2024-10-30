#include "Blocus.h"
#include <graph.h>

#define CYCLE 10000L  
int casesCochees[MAX_OPTIONS] = {0}; 
int choisirTaille = 0;
int modeJeu = 0;
int etatJeu = 1;  // 1 pour le menu, 2 pour le jeu
int tourJoueur = 1;  // 1 pour joueur 1, 2 pour joueur 2
int etapePlacement = 1;  // 1 pour placer la croix, 2 pour placer le pion
int joueur1X, joueur1Y;
int joueur2X, joueur2Y;

#include "Blocus.h"
#include <graph.h>

#include "Blocus.h"
#include <graph.h>

int main(void) {
    int positionSourisX, positionSourisY;
    unsigned long suivant = Microsecondes() + CYCLE;

    if (InitialiserGraphique() == -1) {
        fprintf(stderr, "Erreur lors de l'initialisation graphique.\n");
        return EXIT_FAILURE;
    }

    // Crée la fenêtre graphique
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

            if (etatJeu == 1) {  // Mode Menu
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
                        etatJeu = 2;  // Passe en mode jeu
                        tourJoueur = 1;
                        etapePlacement = 1;
                    } else {
                        afficherMessageGraphique("Veuillez choisir une taille et un mode de jeu.");
                    }
                }
            } else if (etatJeu == 2) {  // Mode Jeu
                if (tourJoueur == 1) {  // Tour du Joueur 1
                    if (etapePlacement == 1) {  // Placement du pion
                        afficherMessageGraphique("Joueur 1 : Placez votre pion.");
                        gererClicGrille(positionSourisX, positionSourisY, 1, choisirTaille);
                        etapePlacement = 2;  // Passe au placement de la croix
                    } else if (etapePlacement == 2) {  // Placement de la croix
                        afficherMessageGraphique("Joueur 1 : Placez votre croix.");
                        gererClicGrille(positionSourisX, positionSourisY, 1, choisirTaille);
                        etapePlacement = 1;  // Passe au tour du Joueur 2
                        tourJoueur = 2;
                    }

                    // Vérifie si le joueur 1 est bloqué
                    if (estPartieTerminee(joueur1X, joueur1Y, choisirTaille)) {
                        etatJeu = 3;       // Passe en mode fin de jeu
                        afficherScore(2);  // Affiche le gagnant (Joueur 2)
                    }
                } else if (tourJoueur == 2) {  // Tour du Joueur 2
                    if (etapePlacement == 1) {  // Placement du pion
                        afficherMessageGraphique("Joueur 2 : Placez votre pion.");
                        gererClicGrille(positionSourisX, positionSourisY, 2, choisirTaille);
                        etapePlacement = 2;  // Passe au placement de la croix
                    } else if (etapePlacement == 2) {  // Placement de la croix
                        afficherMessageGraphique("Joueur 2 : Placez votre croix.");
                        gererClicGrille(positionSourisX, positionSourisY, 2, choisirTaille);
                        etapePlacement = 1;  // Passe au tour du Joueur 1
                        tourJoueur = 1;
                    }

                    // Vérifie si le joueur 2 est bloqué
                    if (estPartieTerminee(joueur2X, joueur2Y, choisirTaille)) {
                        etatJeu = 3;       // Passe en mode fin de jeu
                        afficherScore(1);  // Affiche le gagnant (Joueur 1)
                    }
                }
            }

            // Gestion du mode fin de jeu avec retour au menu
            if (etatJeu == 3) {
                revenirAuMenu();  // Retourne au menu principal
                etatJeu = 1;      // Réinitialise et repasse en mode menu
            }
        }

        if (Microsecondes() > suivant) {
            suivant = Microsecondes() + CYCLE;
        }
    }

    // Libère les ressources et ferme la fenêtre graphique
    libererSprites();
    libererSpritesPions();
    FermerGraphique();
    return 0;
}



// Fonction pour afficher des messages dans la fenêtre graphique
void afficherMessageGraphique(const char *message) {
    ChoisirCouleurDessin(CouleurParNom("black"));
    EcrireTexte(50, HAUTEUR_FENETRE - 30, (char *)message, 2);  // Affiche le message en bas de la fenêtre
}

// Fonction pour afficher la grille si les options sont validées
void afficherGrilleSiValidee(int positionSourisX, int positionSourisY) {
    int boutonX = (LARGEUR_FENETRE - LARGEUR_BOUTON) / 2;
    int boutonY = 400;

    if (choisirTaille >= 3 && choisirTaille <= 9 && modeJeu != 0) {
        if (positionSourisX >= boutonX && positionSourisX <= boutonX + LARGEUR_BOUTON &&
            positionSourisY >= boutonY && positionSourisY <= boutonY + HAUTEUR_BOUTON) {
            
            static int grilleAffichee = 0;

            if (!grilleAffichee) {
                EffacerEcran(CouleurParNom("white"));

                // Affiche le fond de jeu en fonction du mode sélectionné
                if (modeJeu == 1) {
                    afficherFondJeu1();
                } else if (modeJeu == 2) {
                    afficherFondJeu2();
                }

                initialiserJeu(choisirTaille);  // Initialise la grille de jeu
                afficherGrilleJeu(choisirTaille);  // Affiche la grille
                afficherMessageGraphique("Cliquez sur la grille pour jouer.");

                grilleAffichee = 1;  // Marque la grille comme affichée
            }
        }
    } else {
        if (positionSourisX >= boutonX && positionSourisX <= boutonX + LARGEUR_BOUTON &&
            positionSourisY >= boutonY && positionSourisY <= boutonY + HAUTEUR_BOUTON) {
            afficherMessageGraphique("Veuillez choisir une taille et un mode de jeu.");
        }
    }
}
