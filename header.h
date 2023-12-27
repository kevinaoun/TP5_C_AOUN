#include <stdio.h>
#include <stdlib.h>

typedef struct image_ {
    char format[2];     // Format de l'image
    int row;            // Hauteur de la matrice (nombre de lignes)
    int col;            // Largeur de la matrice (nombre de colonnes)
    int **tab;          // Matrice (tableau 2D) row*col
    int max;            // Valeur maximale
}image;

// Retourne le minimum entre a et b
int min(int a, int b);
// Retourne le maximum entre a et b
int max(int a, int b);

// Alloue la mémoire pour un tableau 2D row*col (une matrice)
void newmat(image* mat);

// Ouvre un fichier pgm et remplie dans une variable "image" ses informations
void loadImage(const char* pgm, image *ima);

// Enregistre une image au format pgm dans un nouveau fichier pgm
void recordImage(const char* pgm, image *ima);

// Modifie l'image "ima" en niveau de gris selon le "seuil"
void binarisation(int seuil, image *ima);

// Inverse les couleurs de l'image "ima" précédemment binarisée
void inverse(image *ima);

// Modifie chaque pixel courant en la valeur du plus petit pixel autour
void erosion(image *ima);

// Modifie chaque pixel courant en la valeur du plus grand pixel autour
void dilatation(image *ima);

// Libère la mémoire allouée par newmat pour le tableau 2D row*col
void freemat(image *mat);