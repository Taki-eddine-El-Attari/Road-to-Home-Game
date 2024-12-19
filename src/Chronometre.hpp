#ifndef CHRONOMETRE_HPP
#define CHRONOMETRE_HPP

#include <raylib.h>

class Chronometre {
public:
    float timer;
    bool timerRunning;

    Chronometre();
    void startTimer();
    void stopTimer();
    void updateTimer();
    void drawTimer(int screenWidth, int screenHeight, Font font);
};

#endif // CHRONOMETRE_HPP
