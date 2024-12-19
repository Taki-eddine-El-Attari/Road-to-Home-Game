#include "Niveau.hpp"

// Constructeur de la classe Niveau

Niveau::Niveau() {
    background = LoadTexture("Graphics/Backgrounds/HOME_Difficulty.png");
    carColorsBackground = LoadTexture("Graphics/Backgrounds/HOME_Car_Colors.png"); 
    facileBtn = new button("Graphics/Buttons/Facile.png", {358, 220}, 1.2);
    moyenBtn = new button("Graphics/Buttons/Moyenne.png", {350, 370}, 1.3);
    difficileBtn = new button("Graphics/Buttons/Difficile.png", {350, 520}, 1.3);
    voitureJauneBtn = new button("Graphics/Buttons/Y_Car_But.png", {350, 200}, 1.2); 
    voitureBleuBtn = new button("Graphics/Buttons/B_Car_But.png", {350, 370}, 1.2); 
    voitureRougeBtn = new button("Graphics/Buttons/R_Car_But.png", {350, 540}, 1.2);
}

// Destructeur de la classe Niveau

Niveau::~Niveau() {
    UnloadTexture(background);
    UnloadTexture(carColorsBackground); 
    delete facileBtn;
    delete moyenBtn;
    delete difficileBtn;
    delete voitureJauneBtn; 
    delete voitureBleuBtn; 
    delete voitureRougeBtn; 
}

// Méthode pour afficher les boutons de difficulté

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

// Méthode pour afficher les boutons de couleur de voiture

void Niveau::afficherCouleurs() {
    DrawTexture(carColorsBackground, 0, 0, WHITE); 
    Vector2 mousePos = GetMousePosition();
    
    // Appliquer l'effet hover pour chaque bouton de voiture 
    if (voitureJauneBtn->isHovered(mousePos)) {
        voitureJauneBtn->DrawWithScale(1.1f);
    } else {
        voitureJauneBtn->Draw();
    }
    
    if (voitureBleuBtn->isHovered(mousePos)) {
        voitureBleuBtn->DrawWithScale(1.1f);
    } else {
        voitureBleuBtn->Draw();
    }
    
    if (voitureRougeBtn->isHovered(mousePos)) {
        voitureRougeBtn->DrawWithScale(1.1f);
    } else {
        voitureRougeBtn->Draw();
    }
}

// Méthode pour vérifier la sélection de la difficulté

int Niveau::verifierSelection(Vector2 mousePos, bool mousePres) {
    if (facileBtn->isPressed(mousePos, mousePres)) return 13;
    if (moyenBtn->isPressed(mousePos, mousePres)) return 17;
    if (difficileBtn->isPressed(mousePos, mousePres)) return 21;
    return 0;
}

// Méthode pour vérifier la sélection de la couleur de la voiture

int Niveau::verifierMenuCouleurs(Vector2 mousePos, bool mousePres) { 
    if (voitureJauneBtn->isPressed(mousePos, mousePres)) return 1; 
    if (voitureBleuBtn->isPressed(mousePos, mousePres)) return 2;
    if (voitureRougeBtn->isPressed(mousePos, mousePres)) return 3;
    return 0;
}
