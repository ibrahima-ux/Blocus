#include "Blocus.h"

int spriteCroixBleue, spritePionBleu, spriteCroixRouge, spritePionRouge;

void chargerSpritesPions() {
    // Charger les images et les redimensionner en 25x25 pixels
    spriteCroixBleue = ChargerSprite("croix_bleue_25x25.jpg");
    spritePionBleu = ChargerSprite("pion_bleu_25x25.jpg");
    spriteCroixRouge = ChargerSprite("croix_rouge_25x25.jpg");
    spritePionRouge = ChargerSprite("pion_rouge_25x25.jpg");

    }

void libererSpritesPions() {
    LibererSprite(spriteCroixBleue);
    LibererSprite(spritePionBleu);
    LibererSprite(spriteCroixRouge);
    LibererSprite(spritePionRouge);
}
