#include "Blocus.h" 

int choisirTaille = 5; 
int casesCochees[MAX_OPTIONS] = {0}; 

int main(void) {
    int positionSourisX; 
    int positionSourisY;

    
    if (InitialiserGraphique() == -1) {
        fprintf(stderr, "Erreur lors de l'initialisation graphique.\n");
        return EXIT_FAILURE;
    }

    
    CreerFenetre(20, 20, LARGEUR_FENETRE, HAUTEUR_FENETRE); 
    AfficheImageFond(); 
    TailleJeux(); 

    while (1) {
        if (SourisCliquee()) {
            SourisPosition(); 
            positionSourisX = _X; 
            positionSourisY = _Y; 

           
            gererInteractions(positionSourisX, positionSourisY);
        }
    }

    FermerGraphique();
    return 0; 
}
