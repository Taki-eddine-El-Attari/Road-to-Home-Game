#ifndef LABYRINTHE_HPP
#define LABYRINTHE_HPP

#include <vector>
#include <stack>
#include <utility>
#include <raylib.h>

using namespace std;

class Labyrinthe {
public:
    int largeur, hauteur; // Dimensions du labyrinthe
    vector<vector<int>> grille; // Grille du labyrinthe

    Labyrinthe(int l, int h);
    void genererLabyrinthe();
    void dessiner(int tailleCase, int offsetX, int offsetY);
};

#endif // LABYRINTHE_HPP
