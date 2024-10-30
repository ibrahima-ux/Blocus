#include "Blocus.h"
#include <graph.h>

void revenirAuMenu() {
    EffacerEcran(CouleurParNom("white"));

    
    choisirTaille = 0;                
    modeJeu = 0;                      
    etatJeu = 1;                      // Passe en mode menu
    etapePlacement = 1;
    tourJoueur = 1;

    for (int i = 0; i < MAX_OPTIONS; i++) {
        casesCochees[i] = 0;          // Désélectionne toutes les options de taille
    }

    // Affiche le menu principal
    afficherFondMenu();
    TailleJeux();  // Affiche les options de taille de jeu
}
