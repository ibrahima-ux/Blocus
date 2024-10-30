#include "Blocus.h"
#include <graph.h>

void revenirAuMenu() {
    EffacerEcran(CouleurParNom("white"));

    // Réinitialise les variables de l'état de jeu
    choisirTaille = 0;                // Réinitialise la taille sélectionnée
    modeJeu = 0;                      // Réinitialise le mode de jeu
    etatJeu = 1;                      // Passe en mode menu
    etapePlacement = 1;
    tourJoueur = 1;

    // Réinitialise toutes les cases des options de taille
    for (int i = 0; i < MAX_OPTIONS; i++) {
        casesCochees[i] = 0;          // Désélectionne toutes les options de taille
    }

    // Affiche le menu principal
    afficherFondMenu();
    TailleJeux();  // Affiche les options de taille de jeu
}
