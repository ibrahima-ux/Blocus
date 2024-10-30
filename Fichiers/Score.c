#include "Blocus.h"
#include <graph.h>

#define IMAGE_FIN "ImageFin.png"
#define BOUTON_X (LARGEUR_FENETRE - 250)   // Position X du bouton plus vers la droite
#define BOUTON_Y 100                       // Position Y du bouton plus vers le haut
#define BOUTON_LARGEUR 200
#define BOUTON_HAUTEUR 50

// Déclaration de la fonction dans Recommencer.c
void revenirAuMenu();

void afficherScore(int gagnant) {
    // Efface l'écran et charge l'image de fond
    EffacerEcran(CouleurParNom("white"));
    ChargerImageFond(IMAGE_FIN);

    // Affiche le message de victoire au centre de l'écran
    if (gagnant == 1) {
        ChoisirCouleurDessin(CouleurParNom("Blue"));
        EcrireTexte(LARGEUR_FENETRE / 2 - 100, HAUTEUR_FENETRE / 2, "Joueur 1 a gagne !", 2);
    } else if (gagnant == 2) {
        ChoisirCouleurDessin(CouleurParNom("Red"));
        EcrireTexte(LARGEUR_FENETRE / 2 - 100, HAUTEUR_FENETRE / 2, "Joueur 2 a gagne !", 2);
    }

   
    ChoisirCouleurDessin(CouleurParNom("green"));
    RemplirRectangle(BOUTON_X, BOUTON_Y, BOUTON_LARGEUR, BOUTON_HAUTEUR);

    
    ChoisirCouleurDessin(CouleurParNom("white"));
    EcrireTexte(BOUTON_X + 60, BOUTON_Y + 30, "Rejouer", 2);

  
    ChoisirCouleurDessin(CouleurParNom("black"));
    EcrireTexte(20, 30, "Appuyez sur Echap pour quitter.", 1);  

    // Boucle d'attente pour gérer les actions de l'utili.
    while (1) {
        if (ToucheEnAttente() && Touche() == XK_Escape) {
            FermerGraphique();
            exit(0);  // Quitte complètement le jeu
        } else if (SourisCliquee()) {
            SourisPosition();
            int sourisX = _X;
            int sourisY = _Y;

            // Vérifie si le bouton "Rejouer" est cliqué
            if (sourisX >= BOUTON_X && sourisX <= BOUTON_X + BOUTON_LARGEUR &&
                sourisY >= BOUTON_Y && sourisY <= BOUTON_Y + BOUTON_HAUTEUR) {
                revenirAuMenu();  // Appelle la fonction pour réinitialiser et retourner au menu
                break;
            }
        }
    }
}
