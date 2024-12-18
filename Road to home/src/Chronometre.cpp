#include "Chronometre.hpp"

Chronometre::Chronometre() : timer(0.00f), timerRunning(false) {}

void Chronometre::startTimer() {
    timerRunning = true;
}

void Chronometre::stopTimer() {
    timerRunning = false;
}

void Chronometre::updateTimer() {
    if (timerRunning) {
        timer += GetFrameTime();
    }
}

void Chronometre::drawTimer(int screenWidth, int screenHeight, Font font) {
    DrawTextEx(font, TextFormat("Votre Score : %.2f s", timer), {12, 12}, 40, 1, BLACK);
    DrawTextEx(font, TextFormat("Votre Score : %.2f s", timer), {10, 10}, 40, 1, WHITE);
}
