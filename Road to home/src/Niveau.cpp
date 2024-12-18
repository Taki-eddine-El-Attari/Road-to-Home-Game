#include "Niveau.hpp"

Niveau::Niveau() {
    background = LoadTexture("Graphics/Backgrounds/HOME_Difficulty.png");
    carColorsBackground = LoadTexture("Graphics/Backgrounds/HOME_Car_Colors.png"); // Nouveau background pour la sélection de couleur de voiture
    facileBtn = new button("Graphics/Buttons/Facile.png", {358, 220}, 1.2);
    moyenBtn = new button("Graphics/Buttons/Moyenne.png", {350, 370}, 1.3);
    difficileBtn = new button("Graphics/Buttons/Difficile.png", {350, 520}, 1.3);
    startMazeBtnY = new button("Graphics/Buttons/Y_Car_But.png", {350, 200}, 1.2); // Bouton pour débuter le labyrinthe avec voiture jaune
    startMazeBtnB = new button("Graphics/Buttons/B_Car_But.png", {350, 370}, 1.2); // Bouton pour débuter le labyrinthe avec voiture bleue
    startMazeBtnR = new button("Graphics/Buttons/R_Car_But.png", {350, 540}, 1.2); // Bouton pour débuter le labyrinthe avec voiture rouge
}

Niveau::~Niveau() {
    UnloadTexture(background);
    UnloadTexture(carColorsBackground); // Libérer la mémoire du nouveau background
    delete facileBtn;
    delete moyenBtn;
    delete difficileBtn;
    delete startMazeBtnY; // Libérer la mémoire du bouton jaune
    delete startMazeBtnB; // Libérer la mémoire du bouton bleu
    delete startMazeBtnR; // Libérer la mémoire du bouton rouge
}

void Niveau::afficher() {
    DrawTexture(background, 0, 0, WHITE);
    Vector2 mousePos = GetMousePosition();
    
    // Appliquer l'effet hover pour chaque bouton

    if (facileBtn->isHovered(mousePos)) {
        facileBtn->DrawWithScale(1.1f);
    } else {
        facileBtn->Draw();
    }
    
    if (moyenBtn->isHovered(mousePos)) {
        moyenBtn->DrawWithScale(1.1f);
    } else {
        moyenBtn->Draw();
    }
    
    if (difficileBtn->isHovered(mousePos)) {
        difficileBtn->DrawWithScale(1.1f);
    } else {
        difficileBtn->Draw();
    }
}

void Niveau::afficherStartMaze() {
    DrawTexture(carColorsBackground, 0, 0, WHITE); // Utiliser le nouveau background
    Vector2 mousePos = GetMousePosition();
    
    // Appliquer l'effet hover pour chaque bouton de voiture
    if (startMazeBtnY->isHovered(mousePos)) {
        startMazeBtnY->DrawWithScale(1.1f);
    } else {
        startMazeBtnY->Draw();
    }
    
    if (startMazeBtnB->isHovered(mousePos)) {
        startMazeBtnB->DrawWithScale(1.1f);
    } else {
        startMazeBtnB->Draw();
    }
    
    if (startMazeBtnR->isHovered(mousePos)) {
        startMazeBtnR->DrawWithScale(1.1f);
    } else {
        startMazeBtnR->Draw();
    }
}

int Niveau::verifierSelection(Vector2 mousePos, bool mousePres) {
    if (facileBtn->isPressed(mousePos, mousePres)) return 13;
    if (moyenBtn->isPressed(mousePos, mousePres)) return 17;
    if (difficileBtn->isPressed(mousePos, mousePres)) return 21;
    return 0;
}

int Niveau::verifierStartMaze(Vector2 mousePos, bool mousePres) { 
    if (startMazeBtnY->isPressed(mousePos, mousePres)) return 1; 
    if (startMazeBtnB->isPressed(mousePos, mousePres)) return 2;
    if (startMazeBtnR->isPressed(mousePos, mousePres)) return 3;
    return 0;
}
