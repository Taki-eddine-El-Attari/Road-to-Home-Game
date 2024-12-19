#include "Joueur.hpp"

// Constructeur de la classe Joueur

Joueur::Joueur(Texture2D& right, Texture2D& left, Texture2D& up, Texture2D& down, Texture2D& house, int startX, int startY)
    : joueurTextureRight(right), joueurTextureLeft(left), joueurTextureUp(up), joueurTextureDown(down), joueurX(startX), joueurY(startY), houseTexture(house) {
    joueurTexture = &joueurTextureRight;
}

// méthode pour dessiner le joueur dans le labyrinthe

void Joueur::dessiner(int tailleCase, int offsetX, int offsetY, int largeur, int hauteur) {
    int joueurOffsetX = (tailleCase - joueurTexture->width) / 2; // Calculer les positions pour centrer la texture du joueur dans la case
    int joueurOffsetY = (tailleCase - joueurTexture->height) / 2;
    // Afficher le joueur avec la texture centrée
    DrawTexture(*joueurTexture, joueurX * tailleCase + offsetX + joueurOffsetX, joueurY * tailleCase + offsetY + joueurOffsetY, WHITE);
    // Afficher l'image de la maison à la sortie
    DrawTexture(houseTexture, (largeur - 2) * tailleCase + offsetX, (hauteur - 2) * tailleCase + offsetY, WHITE);
}

// Méthode pour déplacer le joueur dans le labyrinthe

void Joueur::deplacer(Labyrinthe& labyrinthe) {
    static float deplacementTimer = 0.0f;
    const float deplacementInterval = 0.08f; // Intervalle de temps entre les déplacements

    deplacementTimer += GetFrameTime();

    if (deplacementTimer >= deplacementInterval) {
        if (IsKeyDown(KEY_RIGHT) && labyrinthe.grille[joueurY][joueurX + 1] == 0) {
            joueurX++;
            joueurTexture = &joueurTextureRight;
        }
        if (IsKeyDown(KEY_LEFT) && labyrinthe.grille[joueurY][joueurX - 1] == 0) {
            joueurX--;
            joueurTexture = &joueurTextureLeft;
        }
        if (IsKeyDown(KEY_DOWN) && labyrinthe.grille[joueurY + 1][joueurX] == 0) {
            joueurY++;
            joueurTexture = &joueurTextureDown;
        }
        if (IsKeyDown(KEY_UP) && labyrinthe.grille[joueurY - 1][joueurX] == 0) {
            joueurY--;
            joueurTexture = &joueurTextureUp;
        }
        deplacementTimer = 0.0f; // Réinitialiser le timer après un déplacement
    }
}

// Méthode pour vérifier si le joueur a atteint la sortie

bool Joueur::aAtteintSortie(int largeur, int hauteur) {
    return joueurX == largeur - 2 && joueurY == hauteur - 2;
}

// Méthode pour réinitialiser la position du joueur

void Joueur::reinitialiser(int startX, int startY) {
    joueurX = startX;
    joueurY = startY;
    joueurTexture = &joueurTextureRight;
}

// Méthode pour dessiner une image

void Joueur::DessinerImage(const char* imagePath, Texture2D& texture, int newWidth, int newHeight) {
    Image image = LoadImage(imagePath);
    ImageResize(&image, newWidth, newHeight);
    texture = LoadTextureFromImage(image);
    UnloadImage(image);
}

// Méthode pour dessiner la voiture jaune

void Joueur::DessinerVoitureJaune(Texture2D& joueurTextureRight, Texture2D& joueurTextureLeft, Texture2D& joueurTextureUp, Texture2D& joueurTextureDown) {
    DessinerImage("Graphics/Cars/Yellow_Car/Car_Right.png", joueurTextureRight, 35, 20);
    DessinerImage("Graphics/Cars/Yellow_Car/Car_Left.png", joueurTextureLeft, 35, 20);
    DessinerImage("Graphics/Cars/Yellow_Car/Car_Top.png", joueurTextureUp, 20, 35);
    DessinerImage("Graphics/Cars/Yellow_Car/Car_Bottom.png", joueurTextureDown, 20, 35);
}

// Méthode pour dessiner la voiture bleue

void Joueur::DessinerVoitureBleue(Texture2D& joueurTextureRight, Texture2D& joueurTextureLeft, Texture2D& joueurTextureUp, Texture2D& joueurTextureDown) {
    DessinerImage("Graphics/Cars/Blue_Car/Car_Right.png", joueurTextureRight, 35, 19);
    DessinerImage("Graphics/Cars/Blue_Car/Car_Left.png", joueurTextureLeft, 35, 19);
    DessinerImage("Graphics/Cars/Blue_Car/Car_Top.png", joueurTextureUp, 19, 35);
    DessinerImage("Graphics/Cars/Blue_Car/Car_Bottom.png", joueurTextureDown, 19, 35);
}

// Méthode pour dessiner la voiture rouge

void Joueur::DessinerVoitureRouge(Texture2D& joueurTextureRight, Texture2D& joueurTextureLeft, Texture2D& joueurTextureUp, Texture2D& joueurTextureDown) {
    DessinerImage("Graphics/Cars/Red_Car/Car_Right.png", joueurTextureRight, 35, 20);
    DessinerImage("Graphics/Cars/Red_Car/Car_Left.png", joueurTextureLeft, 35, 20);
    DessinerImage("Graphics/Cars/Red_Car/Car_Top.png", joueurTextureUp, 20, 35);
    DessinerImage("Graphics/Cars/Red_Car/Car_Bottom.png", joueurTextureDown, 20, 35);
}
