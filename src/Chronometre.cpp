#include "Chronometre.hpp"

// Constructeur de la classe Chronometre

Chronometre::Chronometre() : timer(0.00f), timerRunning(false) {}

// Méthode pour démarrer le chronomètre

void Chronometre::startTimer() {
    timerRunning = true;
}

// Méthode pour arrêter le chronomètre

void Chronometre::stopTimer() {
    timerRunning = false;
}

// Méthode pour mettre à jour le chronomètre

void Chronometre::updateTimer() {
    if (timerRunning) {
        timer += GetFrameTime();
    }
}

// Méthode pour dessiner le chronomètre

void Chronometre::drawTimer(int screenWidth, int screenHeight, Font font) {
    DrawTextEx(font, TextFormat("Votre Score : %.2f s", timer), {12, 12}, 40, 1, BLACK);
    DrawTextEx(font, TextFormat("Votre Score : %.2f s", timer), {10, 10}, 40, 1, WHITE);
}
