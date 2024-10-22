#include <stdio.h>
#include <stdlib.h>
#include <graph.h>

int tailleChoisie; 
int taille; 
char DiffValeurs[10]; 

void TailleJeux() {
    EffacerEcran(CouleurParNom("green")); 
    EcrireTexte(100, 50, "Choisissez la taille de la grille :", 2); 
   
    for (taille = 3; taille <= 9; taille++) {
        sprintf(DiffValeurs, "%dx%d", taille, taille); 
        EcrireTexte(100, 100 + (taille - 3) * 30, DiffValeurs, 2); 
    }

    EcrireTexte(100, 300, "Cliquez ici pour commencer", 2); 
}

int main(void) {
    int positionSourisX;
    int positionSourisY;
    
    InitialiserGraphique();
    

    CreerFenetre(20, 20, 500, 500); 
    TailleJeux();

    
    while (1) {
        if (SourisCliquee()) {
            SourisPosition(); //   Avoir pstion dla souris
            positionSourisX = _X; // trouve X et retient sa pstion aub moment du clic
            positionSourisY = _Y; // trouve Y au moment du clic

          
            for (taille = 3; taille <= 9; taille++) { ///Revenir au 6 choix 
                if (positionSourisX >= 100 && positionSourisX <= 200 && 
                    positionSourisY >= (100 + (taille - 3) * 30) && 
                    positionSourisY <= (100 + (taille - 2) * 30)) { //Yvertical pr prendre pstion 9x9 
                    tailleChoisie = taille; 
                }
            }

            
            if (positionSourisX >= 100 && positionSourisX <= 300 && //Pr le bouton commencer qui se trouve entre 100 >= 300
                positionSourisY >= 300 && positionSourisY <= 330) { //...
               
                if (tailleChoisie >= 3 && tailleChoisie <= 9) { 
                    printf("Démarrage du jeu avec une taille de %dx%d\n", tailleChoisie, tailleChoisie);
                    break; //Passer a lecran suivante
                } else {
                    printf("Choisissez une Taille Merci !!\n");
                }
            }
        }
    }

 
    FermerGraphique();
    return 0; 
}
