#include "button.hpp"

// Constructeur de la classe button

button::button(const char* imagepath, Vector2 imageposition, float buttonScale, bool isVolume) 
    : position(imageposition), scale(buttonScale), isVolumeButton(isVolume), isMuted(false), backgroundMusic(nullptr) {
    Image image = LoadImage(imagepath);
    int newWidth = static_cast<int>(image.width * scale);
    int newHeight = static_cast<int>(image.height * scale);

    ImageResize(&image, newWidth, newHeight);
    texture = LoadTextureFromImage(image);
    UnloadImage(image);

    if (isVolumeButton) {
        InitAudioDevice();
        backgroundMusic = new Music;
        *backgroundMusic = LoadMusicStream("Graphics/Musics/Background_music.mp3");
        PlayMusicStream(*backgroundMusic);
        SetMusicVolume(*backgroundMusic, 1.0f);
    }
}

// Destructeur de la classe button

button::~button() {
    UnloadTexture(texture);
    if (isVolumeButton && backgroundMusic != nullptr) {
        StopMusicStream(*backgroundMusic);
        UnloadMusicStream(*backgroundMusic);
        delete backgroundMusic;
        CloseAudioDevice();
    }
}

// Méthode pour dessiner le bouton

void button::Draw() {
    DrawTextureV(texture, position, WHITE);
}

// Méthode pour vérifier si le bouton est pressé

bool button::isPressed(Vector2 mousePosition, bool mousePressed) {
    Rectangle rect = {position.x, position.y, static_cast<float>(texture.width), static_cast<float>(texture.height)};
    return CheckCollisionPointRec(mousePosition, rect) && mousePressed;
}

// Méthode pour obtenir les limites du bouton

Rectangle button::getBounds() const {
    return Rectangle{position.x, position.y, static_cast<float>(texture.width), static_cast<float>(texture.height)};
}

// Méthode pour vérifier si le bouton est survolé

bool button::isHovered(Vector2 mousePosition) const {
    Rectangle rect = {position.x, position.y, static_cast<float>(texture.width), static_cast<float>(texture.height)};
    return CheckCollisionPointRec(mousePosition, rect);
}

// Méthode pour dessiner le bouton avec une échelle

void button::DrawWithScale(float scale) {
    float centerX = position.x + texture.width / 2;
    float centerY = position.y + texture.height / 2;

    float newX = centerX - (texture.width * scale) / 2;
    float newY = centerY - (texture.height * scale) / 2;

    Rectangle source = {0, 0, (float)texture.width, (float)texture.height};
    Rectangle dest = {newX, newY, texture.width * scale, texture.height * scale};
    DrawTexturePro(texture, source, dest, {0, 0}, 0, WHITE);
}

// Méthode pour mettre à jour le volume

void button::updateVolume() {
    if (!isVolumeButton || backgroundMusic == nullptr) return;

    UpdateMusicStream(*backgroundMusic);
    Vector2 mousePos = GetMousePosition();
    
    if (isPressed(mousePos, IsMouseButtonPressed(MOUSE_BUTTON_LEFT))) {
        isMuted = !isMuted;
        SetMusicVolume(*backgroundMusic, isMuted ? 0.0f : 1.0f);
        
        UnloadTexture(texture);
        Image newImage = LoadImage(isMuted ? "Graphics/Volumes/Mute.png" : "Graphics/Volumes/volume-up.png");
        ImageResize(&newImage, static_cast<int>(newImage.width * scale), static_cast<int>(newImage.height * scale));
        texture = LoadTextureFromImage(newImage);
        UnloadImage(newImage);
    }
}
