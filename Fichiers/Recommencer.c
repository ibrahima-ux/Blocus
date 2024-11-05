#include "Blocus.h"
#include "BlocusAffichage.h"
#include <graph.h>

void revenirAuMenu() {
    int i;
    EffacerEcran(CouleurParNom("white"));

    
    choisirTaille = 0;                
    modeJeu = 0;                      
    etatJeu = 1;                      
    etapePlacement = 1;
    tourJoueur = 1;

    
    for (i = 0; i < MAX_OPTIONS; i++) {
        casesCochees[i] = 0;          
    }


    afficherFondMenu();
    TailleJeux();  
}
