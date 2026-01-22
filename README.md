# So_long – École 42

<p align="center">
   <img width="746" height="349" alt="image" src="https://github.com/user-attachments/assets/2a14458a-a70f-4642-8bb1-e9b7d5cc4fac" />
</p>

## Description
So_long est un projet de l'École 42 consistant à créer un jeu 2D simple en C avec la bibliothèque **MiniLibX**. Le joueur doit collecter des objets sur une carte pour débloquer la sortie.

---

## Fonctionnalités
- Mouvement du personnage avec `WASD`.
- Collecte d'objets pour débloquer la sortie.
- Gestion des collisions avec les murs.
- Affichage du nombre de mouvements.
- Fermeture propre avec `ESC` ou la croix de la fenêtre.

### Bonus
- Animations pour le personnage et les objets.
- Ennemis.

---

## Prérequis
- Système **Linux**.
- `gcc` et `make` installés.
- MiniLibX (fournie).

---

## Compilation et exécution
1. Cloner le dépôt :
   ```bash
   git clone <url-du-depot> so_long
   cd so_long
   ```
2. Compiler:
    ```bash
    make          # Version de base
    make bonus     # Version avec bonus
    ```
3. Lancer le jeu:
    ```bash
    ./so_long maps/map.ber
    ./so_long_bonus maps/map.ber
    ```
---

## Commandes Makefile
- `make` : Compile la version de base.
- `make bonus` : Compile la version avec bonus.
- `make clean` : Nettoie les fichiers objets.
- `make fclean` : Nettoie tout.
- `make re` : Recompile tout.



