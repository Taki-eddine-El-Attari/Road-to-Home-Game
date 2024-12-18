#ifndef JOUEUR_HPP
#define JOUEUR_HPP

#include <raylib.h>
#include "Labyrinthe.hpp"

class Joueur {
public:
    Joueur(Texture2D& right, Texture2D& left, Texture2D& up, Texture2D& down, Texture2D& house, int startX, int startY);

    void dessiner(int tailleCase, int offsetX, int offsetY, int largeur, int hauteur);
    void deplacer(Labyrinthe& labyrinthe);
    bool aAtteintSortie(int largeur, int hauteur);
    void reinitialiser(int startX, int startY);

    static void DessinerImage(const char* imagePath, Texture2D& texture, int newWidth, int newHeight);
    static void DessinerVoitureJaune(Texture2D& joueurTextureRight, Texture2D& joueurTextureLeft, Texture2D& joueurTextureUp, Texture2D& joueurTextureDown);
    static void DessinerVoitureBleue(Texture2D& joueurTextureRight, Texture2D& joueurTextureLeft, Texture2D& joueurTextureUp, Texture2D& joueurTextureDown);
    static void DessinerVoitureRouge(Texture2D& joueurTextureRight, Texture2D& joueurTextureLeft, Texture2D& joueurTextureUp, Texture2D& joueurTextureDown);

private:
    Texture2D& joueurTextureRight;
    Texture2D& joueurTextureLeft;
    Texture2D& joueurTextureUp;
    Texture2D& joueurTextureDown;
    int joueurX;
    int joueurY;
    Texture2D* joueurTexture;
    Texture2D& houseTexture;
};

#endif // JOUEUR_HPP
