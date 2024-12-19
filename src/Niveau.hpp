#ifndef NIVEAU_HPP
#define NIVEAU_HPP

#include <raylib.h>
#include "button.hpp"

class Niveau {
public:
    Niveau();
    ~Niveau();

    void afficher();
    void afficherCouleurs();
    int verifierSelection(Vector2 mousePos, bool mousePres);
    int verifierMenuCouleurs(Vector2 mousePos, bool mousePres);

private:
    Texture2D background;
    Texture2D carColorsBackground; 
    button* facileBtn;
    button* moyenBtn;
    button* difficileBtn;
    button* voitureJauneBtn; 
    button* voitureBleuBtn; 
    button* voitureRougeBtn; 
};

#endif // NIVEAU_HPP
