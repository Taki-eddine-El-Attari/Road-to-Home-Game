# Road to Home 

Bienvenue dans Road to Home, un jeu de labyrinthe captivant développé en C++ avec la bibliothèque graphique Raylib. Votre mission est de guider votre véhicule à travers des labyrinthes générés procéduralement pour atteindre votre maison.

---

## 🎮 Caractéristiques du Jeu

- **Système de Génération de Labyrinthe**:
  - Utilise l'algorithme "Randomized depth-first search" avec backtracking
  - Garantit une expérience renouvelée à chaque session
- **Niveaux de Difficulté**: Facile | Moyen | Difficile
- **Personnalisation du Véhicule**:
  - Voiture Jaune
  - Voiture Bleue
  - Voiture Rouge
- **Suivi des performances**:
  - Chronomètre en temps réel
  - Système d’enregistrement des meilleurs scores
  - Notifications en cas de nouveaux records
- **Interface intuitive**:
  - Menu principal clair
  - Compte à rebours avant chaque partie
  - Contrôle du volume
  - Navigation simple entre les écrans

---

## 🎯 Gameplay

1. Commencez à l’entrée du labyrinthe
2. Naviguez à travers des chemins générés de manière procédurale
3. Atteignez votre maison à la sortie
4. Essayez de battre votre meilleur temps !

---

## 🎹 Controls

- **Flèches directionnelles**: Déplacer le véhicule
- **Espace**: Réinitialiser le niveau en cours
- **H**: Retourner au menu principal
- **ESC**: Quitter le jeu

---

## 🛠️ Technologies utilisées

- **C++**: Langage principal de programmation.
- **Raylib**: Bibliothèque légère pour le développement de jeux en 2D.
- **Principes de POO**: Pour une meilleure organisation du code et sa réutilisabilité.

---

## 🎨 Assets

- **Musique de fond**: Ambiance sonore immersive pour enrichir l'expérience de jeu.
- **Éléments d'interface utilisateur (UI)**: Boutons interactifs et visuellement attrayants.
- **Police personnalisée**: Utilisation de la police AfacadFlux pour une esthétique unique.
- **Graphiques divers**: Images de fond, icônes des voitures, maison et autres éléments visuels.

---

## 📂 Structure du projet

```
Road-to-Home-Game/
├── Graphics/                   # Contient les ressources graphiques du jeu
│   ├── Backgrounds/            # Images de fond pour les différents écrans du jeu
│   │   ├── menu_background.png
│   │   ├── game_background.png
│   │   └── ...                
│   ├── Cars/                   # Sprites des véhicules jouables
│   │   ├── YellowCar/
│   │   │   ├── yellow_car_up.png
│   │   │   ├── yellow_car_down.png
│   │   │   ├── yellow_car_left.png
│   │   │   └── yellow_car_right.png
│   │   ├── BlueCar/
│   │   │   ├── blue_car_up.png
│   │   │   └── ...
│   │   └── RedCar/
│   │       ├── red_car_up.png
│   │       └── ...
│   ├── Buttons/                # Images des boutons de l'interface utilisateur
│   │   ├── play_button.png
│   │   ├── settings_button.png
│   │   ├── exit_button.png
│   │   └── ...                 
│   ├── House/                  # Sprite de la maison, objectif du jeu
│   │   └── house.png
│   ├── Music/                  # Fichier audio pour la musique de fond
│   │   └── background_music.mp3
│   ├── VolumeIcons/            # Icônes pour le contrôle du volume
│   │   ├── volume_up.png
│   │   └── mute.png
│   └── Fonts/                  # Polices personnalisées utilisées dans le jeu
│       └── AfacadFlux.ttf
└── src/                        # Contient le code source du jeu
    ├── main.cpp                
    ├── Game.cpp                
    ├── Player.cpp             
    ├── Maze.cpp                
    ├── Button.cpp             
    ├── Timer.cpp               
    └── Utils.cpp               

```
---

## 📸 Quelques captures d'écran

### 1️⃣ **Page d'accueil**
<img src="https://github.com/user-attachments/assets/6e868416-3cbd-40a8-b8d9-29d485a02038" alt="Page d'acceuil" width="600">

> Aperçu de l'écran principal simple et intuitif, avec deux boutons : Start pour commencer une partie et Exit pour quitter l'application.

---

### 2️⃣ **Personnalisation des couleurs des véhicules**
<img src="https://github.com/user-attachments/assets/125afb04-bdd9-48a9-a95c-4334cc9ac529" alt="Personnalisation des véhicules" width="600">

> Sélectionnez la couleur de votre véhicule (jaune, bleu ou rouge) pour personnaliser votre expérience de jeu.

---

### 3️⃣ **Page du labyrinthe**
<img src="https://github.com/user-attachments/assets/0f12f022-9c9f-4095-8a8c-491e14680bab" alt="Page du labyrinthe" width="600">

> Naviguez à travers des labyrinthes générés procéduralement, avec une vue claire de votre véhicule et de l’objectif final.

---

## 🌟 Remerciements

- **Membres de l'équipe**:
    - Taki eddine El attari
    - Fahima El haddaoui
    - Fatima Ezzahra Chayeb
    - Rabab Ziti
- **Encadrante**: Ikram Ben Abdel Ouahab

