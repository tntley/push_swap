*Projet réalisé par tanrandr et aleandri dans le cadre du cursus 42.*
# Push_swap - L'Art du Tri Optimisé
## Description
Push_swap est un projet de d'algorithmie pur qui demande de trier une pile de nombres entiers en utilisant une pile intermédiaire et un ensemble d'instructions limitées. L'enjeu n'est pas seulement de trier, mais de le faire avec le minimum de coups possible.Ce projet nous a permis de manipuler des structures de données complexes (listes doublement chaînées circulaires) et de mettre en œuvre une logique de sélection d'algorithmes selon la nature des données (approche Adaptive).

### Architecture du Projet
## 1. Gestion des Données (Parsing & Indexation)
Avant de trier, le programme sécurise et simplifie la donnée.

- parsinginput.c : Vérifie la validité des entrées (chiffres uniquement, pas de doublons, gestion des overflows INT_MIN/MAX).

- stackbuilding.c : Construit la liste circulaire et génère les index. L'indexation remplace les valeurs brutes par leur rang (de 0 à N-1), ce qui est indispensable pour l'algorithme Radix.

## 2. Le Moteur de Tri (Adaptive Sort)

Le programme analyse le "score de désordre" de la pile pour choisir la stratégie la plus économe. Ce dernier a également été structuré de sorte à prendre en considération la taille de la pile dans le choix de la stratégie optimale. Le programme utilise le moteur de tri par défaut. Un flag `--adaptive` peut également être inclus pour signifier au programme de recourir au sélecteur.

### Simple Sort (simplesort.c) (Complexité $O(n²)$) :

Utilisé pour les très petites piles ou les listes presque triées (score de désordre inférieur à 0.2). Il s'agit d'un tri par sélection optimisé. L'utilisateur peut également forcé l'utilisation de cette stratégie en incluant le flag `--simple`.

### Medium Sort (mediumsort.c) (Complexité $O(n \sqrt n)$):

Utilise la méthode des Chunks (blocs). On divise la pile en sous-groupes basés sur la racine carrée de la taille totale de celle-ci pour limiter les rotations inutiles. Le programme va automatiquement choisir cette stratégie pour une pile avec un score de désordre compris entre 0.2 et 0.5. Celle-ci sera également sélectionné pour une pile contenant entre 10 à 100 nombres à trier, ou en cas de présence du flag `--medium` dans la ligne de commande.

### Complex Sort (complexsort.c) (Complexité $O(n \log n)$) :
Un tri par base (Radix Sort) travaillant sur les bits binaires. C'est l'assurance d'un score stable et performant sur 500 nombres à trier. Cette méthode compare les index des nombres contenus dans la pile "bit par bit", poussant les nombres dont le bit actuel est 0 vers la pile B. Cette stratégie sera automatiquement sélectionné pour les piles contenant 500 nombres ou dont le score de désordre dépasse 0.5. L'ajout du flag `--complex` permet également de forcer le programme à l'utiliser, indépendamment de la taille ou du désordre de la pile.

## 3 Les Instructions de Manipulation

Le programme utilise exclusivement les opérations suivantes pour manipuler les piles A et B :

- sa / sb : Échange les deux premiers éléments au sommet de la pile.

- ss : sa et sb en même temps.Push

- pa : Prend le premier élément de B et le met sur A.

- pb : Prend le premier élément de A et le met sur B.

- ra / rb : Le premier élément devient le dernier.

- rr : ra et rb en même temps.Reverse Rotate (Rotation vers le bas)

- rra / rrb : Le dernier élément devient le premier.

- rrr : rra et rrb en même temps.
### Mode Bench
on a intégré un module de métriques (bench.c) pour analyser l'efficacité de notre code. En activant ce mode, le programme affiche :

- Le taux de désordre initial.

- L'algorithme choisi par le sélecteur adaptatif ou imposé par le flag saisi par l'utilisateur, ainsi que la complexité algorithmique.

- Le décompte précis de chaque instruction utilisée.

- Le total des opérations final.

### Installation et UtilisationCompilation

Le projet se compile avec le Makefile fourni :
```
make        # Génère l'exécutable push_swap
```
```
make clean  # Supprime les fichiers objets
```
```
make fclean # Supprime les objets et l'exécutable
```
### Exécution Pour trier une liste de nombres :
```
./push_swap 2 1 3 6 5 8
```
### Pour vérifier le nombre de lignes avec le testeur officiel (si disponible) :
```
ARG="4 67 3 1 23"; ./push_swap $ARG | wc -l
```
# Ressources et Remerciements
*Ce projet a été une étape clé pour comprendre la complexité algorithmique ($O(n^2)$, $O(n \log n)$, $O(n \sqrt n)$).*

### Outils et inspirations :
### Visualisateurs :
Essentiels pour comprendre le mouvement des piles en temps réel.

### videos youtube :
Les retours de la communauté sur les algorithmes de type "Chunks" et "Radix".

### IA & Debugging :
Utilisation de l'IA pour Valgrind afin de traquer chaque fuite de mémoire sur les structures circulaires et comprendre les erreurs.
