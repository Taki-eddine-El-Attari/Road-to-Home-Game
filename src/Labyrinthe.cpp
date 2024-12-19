#include "Labyrinthe.hpp"
#include <cstdlib>
#include <ctime>
using namespace std;

// Constructeur de la classe Labyrinthe

Labyrinthe::Labyrinthe(int l, int h) : largeur(l), hauteur(h) {
    srand(time(0)); // Initialisation du générateur aléatoire
    grille.resize(hauteur, vector<int>(largeur, 1)); // Initialisation : tout est mur
    genererLabyrinthe(); // Génération du labyrinthe
}

// Générer le labyrinthe avec l'algorithme de backtracking

void Labyrinthe::genererLabyrinthe() {
    // Positions initiales
    int x = 1, y = 1; 

    // Marquer la cellule de départ comme un passage
    grille[y][x] = 0; 

    // Pile pour le backtracking (retour arrière)
    stack<pair<int, int>> pile; // Pile pour les positions
    pile.push({x, y}); // Ajouter la position de départ

    // Déplacements possibles (droite, bas, gauche, haut)
    vector<pair<int, int>> directions = {{2, 0}, {0, 2}, {-2, 0}, {0, -2}};

    while (!pile.empty()) { // Tant que la pile n'est pas vide
        pair<int, int> current = pile.top(); // Position actuelle
        int cx = current.first; // Coordonnée x actuelle
        int cy = current.second; // Coordonnée y actuelle
        vector<pair<int, int>> voisins; // Liste des voisins

        // Trouver les voisins valides
        for (size_t i = 0; i < directions.size(); i++) { // Parcourir les directions
            int dx = directions[i].first; // Déplacement en x
            int dy = directions[i].second; // Déplacement en y
            int nx = cx + dx; // Nouvelle coordonnée x
            int ny = cy + dy; // Nouvelle coordonnée y
            if (nx > 0 && ny > 0 && nx < largeur - 1 && ny < hauteur - 1 && grille[ny][nx] == 1) { // Vérifier validité
                voisins.push_back(make_pair(nx, ny)); // Ajouter le voisin
            }
        }

        if (!voisins.empty()) { // S'il y a des voisins
            // Choisir un voisin aléatoire
            pair<int, int> next = voisins[rand() % voisins.size()]; // Voisin aléatoire
            int nx = next.first; // Coordonnée x du voisin
            int ny = next.second; // Coordonnée y du voisin

            // Casser le mur entre la cellule actuelle et le voisin
            grille[cy + (ny - cy) / 2][cx + (nx - cx) / 2] = 0; // Casser le mur

            // Marquer le voisin comme un passage
            grille[ny][nx] = 0;
            // Ajouter le voisin à la pile
            pile.push(make_pair(nx, ny));
        } else {
            // Retour arrière
            pile.pop();
        }
    }

    // Départ et sortie
    grille[1][1] = 0; // Départ
    grille[hauteur - 2][largeur - 2] = 0; // Sortie
}

// Dessiner le labyrinthe

void Labyrinthe::dessiner(int tailleCase, int offsetX, int offsetY) {
    for (int i = 0; i < hauteur; i++) { // Parcourir les lignes
        for (int j = 0; j < largeur; j++) { // Parcourir les colonnes
            if (grille[i][j] == 1) { // Si c'est un mur
                DrawRectangle(j * tailleCase + offsetX, i * tailleCase + offsetY, tailleCase, tailleCase, BLACK); // Dessiner un mur
            } else { // Si c'est un passage
                DrawRectangle(j * tailleCase + offsetX, i * tailleCase + offsetY, tailleCase, tailleCase, LIGHTGRAY); // Dessiner un passage
            }
        }
    }
}
