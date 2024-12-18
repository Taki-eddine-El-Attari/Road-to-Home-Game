#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <raylib.h>

class button {
private:
    Texture2D texture;
    Vector2 position;
    float scale;
    bool isVolumeButton;
    bool isMuted;
    Music* backgroundMusic;  // Changé en pointeur

public:
    button(const char* imagepath, Vector2 imageposition, float scale, bool isVolume = false);
    ~button();
    
    void Draw();
    void DrawWithScale(float newScale);
    bool isPressed(Vector2 mousePosition, bool mousePressed);
    bool isHovered(Vector2 mousePosition) const;
    void updateVolume();
    
    Rectangle getBounds() const;
};

#endif // BUTTON_HPP
