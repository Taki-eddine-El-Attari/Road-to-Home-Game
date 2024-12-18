#include <raylib.h>
#include <vector>
#include <stack>
#include <cstdlib>
#include <unistd.h>
#include <ctime>
#include "button.hpp" 
#include "Labyrinthe.hpp" 
#include "Joueur.hpp" 
#include "Niveau.hpp"
#include "Chronometre.hpp"

using namespace std;


// Fonction principale
int main() {
    // Dimensions de la fenêtre
    int screenWidth = 900; // Largeur de la fenêtre
    int screenHeight = 900; // Hauteur de la fenêtre

    // Initialisation de la fenêtre Raylib
    InitWindow(screenWidth, screenHeight, "Road To Home"); // Créer la fenêtre

    SetTargetFPS(60); // Limiter à 60 images par seconde

    // Load textures once
    Texture2D background = LoadTexture("Graphics/Backgrounds/HOME.png");
    Texture2D houseTexture = LoadTexture("Graphics/House/house.png");
    Texture2D bestRecordBackground = LoadTexture("Graphics/Backgrounds/BEST_RECORD.png"); 
    Texture2D mazeBackground = LoadTexture("Graphics/Backgrounds/Maze_Back.png");
    Texture2D joueurTextureRight, joueurTextureLeft, joueurTextureUp, joueurTextureDown;

    button startButton("Graphics/Buttons/start.png", {350, 230}, 0.7); // Appel de la classe button pour créer un bouton de démarrage
    button exitButton("Graphics/Buttons/exit.png", {365, 420}, 0.6); // Appel de la classe button pour créer un bouton de sortie

    Font customFont = LoadFontEx("Graphics/Fonts/AfacadFlux.ttf", 80, 0, 0); // Charger votre police personnalisée avec taille et gras

    bool exit = false; // Argument booléen initialisé à false
    bool gameStarted = false; // Indicateur de démarrage du jeu
    bool difficultyMenu = false;
    int largeur = 0; // Largeur du labyrinthe / facile = 13, moyen = 17, difficile = 21
    int hauteur = 0; // Hauteur du labyrinthe / facile = 13, moyen = 17, difficile = 21
    
    Niveau niveau;
    Labyrinthe* labyrinthe = nullptr;

    Joueur joueur(joueurTextureRight, joueurTextureLeft, joueurTextureUp, joueurTextureDown, houseTexture, 1, 1);

    // Remplacer l'initialisation de l'audio et du bouton de volume par :
    button volumeButton("Graphics/Volumes/volume-up.png", {(float)(screenWidth - 70), 20}, 0.60, true);
    
    bool CarsColors = false; // Indicateur pour afficher les couleurs de voiture

    // Initialiser la classe Chronometre
    Chronometre chronometre;  // Remplacer Jeu jeu

    // Boucle de jeu
    while (!WindowShouldClose() && !exit) { // Fonction pour vérifier si la touche échap est pressée et que le booléen exit est false
        Vector2 mousePos = GetMousePosition(); // Créer une position de la souris à partir de la structure Vector2 et stocker les dimensions de la souris avec cette fonction
        bool mousePres = IsMouseButtonPressed(MOUSE_BUTTON_LEFT); // Vérifier si le bouton gauche de la souris est pressé avec cette fonction

        // Mettre à jour la musique
        volumeButton.updateVolume();
        
        BeginDrawing();
        ClearBackground(BLACK);

        if (!gameStarted) { // Si le jeu n'a pas encore commencé

            if (!difficultyMenu) { // Si le menu de difficulté n'est pas affiché

                // Menu principal
                DrawTexture(background, 0, 0, WHITE);
                
                // Effet de hover sur le bouton start et exit
                if (startButton.isHovered(mousePos)) {
                    startButton.DrawWithScale(1.1f); // Agrandir de 10% quand survolé
                } else {
                    startButton.Draw(); // Taille normale
                }
                
                if (exitButton.isHovered(mousePos)) {
                    exitButton.DrawWithScale(1.1f); // Agrandir de 10% quand survolé
                } else {
                    exitButton.Draw(); // Taille normale
                }

                // Dessiner les boutons start et exit
                if (startButton.isPressed(mousePos, mousePres)) {
                    difficultyMenu = true;
                }
                if (exitButton.isPressed(mousePos, mousePres)) {
                    exit = true;
                }
            } else { // Si le menu de difficulté est affiché

                if (!CarsColors) { // Si le menu de sélection de couleur de voiture n'est pas affiché

                    niveau.afficher(); // Afficher le menu de difficulté
                    int Nouvelletaille = niveau.verifierSelection(mousePos, mousePres);
                    if (Nouvelletaille > 0) {
                        largeur = hauteur = Nouvelletaille;
                        labyrinthe = new Labyrinthe(largeur, hauteur);
                        CarsColors = true; // Afficher le bouton de début du labyrinthe
                    }
                } else { // Si le menu de sélection de couleur de voiture est affiché

                    niveau.afficherStartMaze();
                    int carSelection = niveau.verifierStartMaze(mousePos, mousePres);
                    if (carSelection > 0) {
                        if (carSelection == 1) {
                            Joueur::DessinerVoitureJaune(joueurTextureRight, joueurTextureLeft, joueurTextureUp, joueurTextureDown);
                        } else if (carSelection == 2) {
                            Joueur::DessinerVoitureBleue(joueurTextureRight, joueurTextureLeft, joueurTextureUp, joueurTextureDown);
                        } else if (carSelection == 3) {
                            Joueur::DessinerVoitureRouge(joueurTextureRight, joueurTextureLeft, joueurTextureUp, joueurTextureDown);
                        }
                        gameStarted = true;
                        CarsColors = false;
                    }
                }
            }
        } else { // Si le jeu a commencé

            double startTime = GetTime();
            double currentTime;
            int countdown = 3;
            
            while (countdown > 0) { // Compte à rebours avant de commencer
                BeginDrawing();
                DrawTexture(mazeBackground, 0, 0, WHITE);
                DrawTextEx(customFont, TextFormat("%d", countdown), {(float)(screenWidth / 2 - MeasureTextEx(customFont, TextFormat("%d", countdown), 100, 1).x / 2), (float)(screenHeight / 2 - 70)}, 100, 1, RED);
                DrawTextEx(customFont, "Preparer vous !", {(float)(screenWidth / 2 - MeasureTextEx(customFont, "Preparer vous !", 60, 1).x / 2), (float)(screenHeight / 2 + 20)}, 60, 1, WHITE);
                volumeButton.Draw();  // Ajouter ici
                EndDrawing();
                
                volumeButton.updateVolume();  // Ajouter ici
                
                currentTime = GetTime();
                if (currentTime - startTime >= 1.0) {
                    countdown--;
                    startTime = currentTime;
                }
            }
            
            if (labyrinthe == nullptr) { // Si le labyrinthe n'est pas encore initialisé
                labyrinthe = new Labyrinthe(largeur, hauteur);
            }
            
            // Taille d'une case en pixels
            int tailleCase = 35; // Taille d'une case
            
            chronometre.startTimer(); // Démarrer le timer

            // Calculer les décalages pour centrer le labyrinthe
            int offsetX = (screenWidth - largeur * tailleCase) / 2;
            int offsetY = (screenHeight - hauteur * tailleCase) / 2;
            // Afficher le compte à rebours avant de commencer
            

            while (!WindowShouldClose() && gameStarted) { // Boucle principale
                volumeButton.updateVolume();  // Mettre à jour la musique dans la boucle de jeu
                
                ClearBackground(RAYWHITE); // Effacer l'écran

                // Dessiner le background du labyrinthe avant tout
                DrawTexture(mazeBackground, 0, 0, WHITE);

                // Dessiner le labyrinthe
                labyrinthe->dessiner(tailleCase, offsetX, offsetY); // Utiliser la méthode dessiner de la classe Labyrinthe

                joueur.dessiner(tailleCase, offsetX, offsetY, largeur, hauteur);
                joueur.deplacer(*labyrinthe);

                // Gérer le clic sur le bouton de volume 
                volumeButton.Draw();

                chronometre.updateTimer(); // Mettre à jour le timer
                chronometre.drawTimer(screenWidth, screenHeight, customFont); // Dessiner le timer

                // First line with shadow
                DrawTextEx(customFont, "Cliquer sur ", {(float)(screenWidth / 2 - MeasureText("Cliquer sur ESPACE pour reinitialiser le labyrinthe", 24) / 2) + 2, (float)(screenHeight - 70) + 2}, 40, 1, BLACK);
                DrawTextEx(customFont, "ESPACE", {(float)(screenWidth / 2 - MeasureText("Cliquer sur ESPACE pour reinitialiser le labyrinthe", 24) / 2 + MeasureText("Cliquer sur   ", 20)) + 2, (float)(screenHeight - 70) + 2}, 40, 1, BLACK);
                DrawTextEx(customFont, " pour reinitialiser le labyrinthe", {(float)(screenWidth / 2 - MeasureText("Cliquer sur ESPACE pour reinitialiser le labyrinthe", 24) / 2 + MeasureText("Cliquer sur ESPACE   ", 20)) + 2, (float)(screenHeight - 70) + 2}, 40, 1, BLACK);

                DrawTextEx(customFont, "Cliquer sur ", {(float)(screenWidth / 2 - MeasureText("Cliquer sur ESPACE pour reinitialiser le labyrinthe", 24) / 2), (float)(screenHeight - 70)}, 40, 1, WHITE);
                DrawTextEx(customFont, "ESPACE", {(float)(screenWidth / 2 - MeasureText("Cliquer sur ESPACE pour reinitialiser le labyrinthe", 24) / 2 + MeasureText("Cliquer sur   ", 20)), (float)(screenHeight - 70)}, 40, 1, RED);
                DrawTextEx(customFont, " pour reinitialiser le labyrinthe", {(float)(screenWidth / 2 - MeasureText("Cliquer sur ESPACE pour reinitialiser le labyrinthe", 24) / 2 + MeasureText("Cliquer sur ESPACE   ", 20)), (float)(screenHeight - 70)}, 40, 1, WHITE);
                
                // Second line with shadow
                DrawTextEx(customFont, "Cliquer sur ", {(float)(screenWidth / 2 - MeasureText("Cliquer sur H pour retourner a la page d'accueil", 24) / 2) + 2, (float)(screenHeight - 40) + 2}, 40, 1, BLACK);
                DrawTextEx(customFont, "H", {(float)(screenWidth / 2 - MeasureText("Cliquer surpour retourner a la page d'accueil", 24) / 2 + MeasureText("Cliquer sur ", 20)) + 2, (float)(screenHeight - 40) + 2}, 40, 1, BLACK);
                DrawTextEx(customFont, " pour retourner a la page d'accueil", {(float)(screenWidth / 2 - MeasureText("Cliquer sur H pour retourner a la page d'accueil", 24) / 2 + MeasureText("Cliquer sur H   ", 20)) + 2, (float)(screenHeight - 40) + 2}, 40, 1, BLACK);

                DrawTextEx(customFont, "Cliquer sur ", {(float)(screenWidth / 2 - MeasureText("Cliquer sur H pour retourner a la page d'accueil", 24) / 2), (float)(screenHeight - 40)}, 40, 1, WHITE);
                DrawTextEx(customFont, "H", {(float)(screenWidth / 2 - MeasureText("Cliquer surpour retourner a la page d'accueil", 24) / 2 + MeasureText("Cliquer sur ", 20)), (float)(screenHeight - 40)}, 40, 1, RED);
                DrawTextEx(customFont, " pour retourner a la page d'accueil", {(float)(screenWidth / 2 - MeasureText("Cliquer sur H pour retourner a la page d'accueil", 24) / 2 + MeasureText("Cliquer sur H   ", 20)), (float)(screenHeight - 40)}, 40, 1, WHITE);
                static float meilleurScore = 0.00f; // Initialiser le meilleur score à une valeur très élevée

                if (joueur.aAtteintSortie(largeur, hauteur)) {
                    chronometre.stopTimer(); // Arrêter le timer
                    static bool Newscore = false;
                    
                    // Mettre à jour le meilleur score si le score actuel est meilleur
                    if (meilleurScore == 0.00f)
                    {
                        meilleurScore = chronometre.timer;
                    }
                    else if(chronometre.timer < meilleurScore) { // Si le score actuel est meilleur
                        meilleurScore = chronometre.timer;
                        Newscore = true;
                    }

                    // Utiliser la texture déjà chargée
                    DrawTexture(bestRecordBackground, 0, 0, WHITE);

                    // Afficher les scores avec ombre
                    DrawTextEx(customFont, TextFormat("Le meilleur record : %.2f s", meilleurScore), {(float)(screenWidth / 2 - MeasureTextEx(customFont, TextFormat("Le meilleur record : %.2f s", meilleurScore), 50, 1).x / 2) + 2, (float)(screenHeight / 2 - 80) + 2}, 50, 1, BLACK); // Afficher le meilleur score avec ombre
                    DrawTextEx(customFont, TextFormat("Le meilleur record : %.2f s", meilleurScore), {(float)(screenWidth / 2 - MeasureTextEx(customFont, TextFormat("Le meilleur record : %.2f s", meilleurScore), 50, 1).x / 2), (float)(screenHeight / 2 - 80)}, 50, 1, WHITE);
                   
                    if (Newscore == true) {
                        static float alpha = 0.0f;
                        static bool increasing = true;
                        static float lastTime = GetTime();

                        // Changer la visibilité du texte Nouveau record
                        float currentTime = GetTime();
                        if (currentTime - lastTime >= 1.0f) {
                            increasing = !increasing;
                            lastTime = currentTime;
                        }

                        if (increasing) {
                            alpha += GetFrameTime();
                            if (alpha > 1.0f) alpha = 1.0f;
                        } else {
                            alpha -= GetFrameTime();
                            if (alpha < 0.0f) alpha = 0.0f;
                        }

                        Color textColor = Fade(RED, alpha);
                        DrawTextEx(customFont, " Nouveau record!", {(float)(screenWidth / 2 + MeasureTextEx(customFont, TextFormat("Le meilleur record : %.2f s", meilleurScore), 43, 1).x / 2 + 28), (float)(screenHeight / 2 - 77)}, 43, 1, textColor);
                        
                        // Réinitialiser Newscore après affichage
                        if (!increasing && alpha <= 0.0f) {
                            Newscore = false;
                        }
                    }

                    DrawTextEx(customFont, TextFormat("Votre Score : %.2f s", chronometre.timer), {(float)(screenWidth / 2 - MeasureTextEx(customFont, TextFormat("Votre record : %.2f s", chronometre.timer), 50, 1).x / 2) + 2, (float)(screenHeight / 2 - 20) + 2}, 50, 1, BLACK); // Afficher le score avec ombre
                    DrawTextEx(customFont, TextFormat("Votre Score : %.2f s", chronometre.timer), {(float)(screenWidth / 2 - MeasureTextEx(customFont, TextFormat("Votre record : %.2f s", chronometre.timer), 50, 1).x / 2), (float)(screenHeight / 2 - 20)}, 50, 1, WHITE);

                    // Shadow text for replay message
                    DrawTextEx(customFont, "Entrer ESPACE pour rejouer", {(float)(screenWidth / 2 - MeasureTextEx(customFont, "Entrer ESPACE pour rejouer", 35, 1).x / 2) + 1, (float)(screenHeight - 80) + 1}, 35, 1, BLACK);
                    DrawTextEx(customFont, "Entrer ESPACE pour rejouer", {(float)(screenWidth / 2 - MeasureTextEx(customFont, "Entrer ESPACE pour rejouer", 35, 1).x / 2), (float)(screenHeight - 80)}, 35, 1, WHITE);

                    // Shadow text for return message
                    DrawTextEx(customFont, "Entrer H pour retourner a la page d'accueil", {(float)(screenWidth / 2 - MeasureTextEx(customFont, "Entrer H pour retourner a la page d'accueil", 35, 1).x / 2) + 1, (float)(screenHeight - 40) + 1}, 35, 1, BLACK);
                    DrawTextEx(customFont, "Entrer H pour retourner a la page d'accueil", {(float)(screenWidth / 2 - MeasureTextEx(customFont, "Entrer H pour retourner a la page d'accueil", 35, 1).x / 2), (float)(screenHeight - 40)}, 35, 1, WHITE);


                    // Dessiner le bouton de volume
                    volumeButton.Draw();
                    
                }
              

                // Dessiner le bouton de volume dans toutes les phases du jeu
                volumeButton.Draw();

                EndDrawing(); // Fin du dessin

                if (IsKeyPressed(KEY_SPACE)) {
                    // Réinitialiser le labyrinthe
                    delete labyrinthe; 
                    labyrinthe = new Labyrinthe(largeur, hauteur); // Réinitialiser labyrinthe
                    // Réinitialiser la position du joueur
                    joueur.reinitialiser(1, 1);
                    chronometre = Chronometre(); // Réinitialiser le chronomètre
                    chronometre.startTimer(); // Démarrer le timer
                }


                if (IsKeyPressed(KEY_ESCAPE) || WindowShouldClose()) {
                    exit = true; // Changer la valeur de exit pour fermer la fenêtre raylib
                    CloseWindow(); // Fermer la fenêtre raylib
                }
                if (IsKeyPressed(KEY_H)) {
                    gameStarted = false; // Changer la valeur de gameStarted pour revenir à l'écran de démarrage
                    difficultyMenu = false; // Revenir au menu principal
                    CarsColors = false; // Réinitialiser l'affichage de menu des couleurs
                    
                    joueur.reinitialiser(1, 1); // Réinitialiser la position du joueur
                    meilleurScore = 0.00f; // Réinitialiser le meilleur score
                    chronometre = Chronometre(); // Réinitialiser le chronomètre
                }
            }
        }

        // Dessiner le bouton de volume (une seule fois à la fin de la boucle principale)
        volumeButton.Draw();
        
        EndDrawing();
    }
    
    // Nettoyer les ressources avant de quitter (ajouter avant CloseWindow)
    if (labyrinthe != nullptr) {
        delete labyrinthe;
    }
    CloseAudioDevice();
    UnloadTexture(houseTexture);
    UnloadTexture(background);
    UnloadTexture(houseTexture);
    UnloadTexture(bestRecordBackground);
    UnloadTexture(mazeBackground); // Libérer la texture du background du labyrinthe
    UnloadTexture(joueurTextureRight);
    UnloadTexture(joueurTextureLeft);
    UnloadTexture(joueurTextureUp);
    UnloadTexture(joueurTextureDown);
    UnloadFont(customFont);

    CloseWindow(); // Fermer la fenêtre raylib

    return 0;
}
