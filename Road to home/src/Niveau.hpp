#ifndef NIVEAU_HPP
#define NIVEAU_HPP

#include <raylib.h>
#include "button.hpp"

class Niveau {
public:
    Niveau();
    ~Niveau();

    void afficher();
    void afficherStartMaze();
    int verifierSelection(Vector2 mousePos, bool mousePres);
    int verifierStartMaze(Vector2 mousePos, bool mousePres);

private:
    Texture2D background;
    Texture2D carColorsBackground; // Nouveau background pour la sélection de couleur de voiture
    button* facileBtn;
    button* moyenBtn;
    button* difficileBtn;
    button* startMazeBtnY; // Bouton pour débuter le labyrinthe avec voiture jaune
    button* startMazeBtnB; // Bouton pour débuter le labyrinthe avec voiture bleue
    button* startMazeBtnR; // Bouton pour débuter le labyrinthe avec voiture rouge
};

#endif // NIVEAU_HPP
