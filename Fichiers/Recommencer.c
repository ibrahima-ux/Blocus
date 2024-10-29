#include "Blocus.h"
#include <graph.h>

void revenirAuMenu() {
    EffacerEcran(CouleurParNom("white"));
    
    // Réinitialise les variables et l'état de jeu pour retourner au menu
    choisirTaille = 0;
    modeJeu = 0;
    etatJeu = 1;  // On repasse en mode menu
    etapePlacement = 1;
    tourJoueur = 1;

    // Affiche le menu principal
    afficherFondMenu();
    TailleJeux();  // Affiche les options de taille de jeu
}
