#ifndef MATRIX_H
#define MATRIX_H

#include <stdlib.h>

// Alloue et retourne un pointeur vers une nouvelle matrice
long *create_matrix(int rows, int cols);

// Remplit la matrice avec des valeurs initiales
void fill_matrix(long *matrix, int rows, int cols);

// Affiche le contenu de la matrice
void print_matrix(long *matrix, int rows, int cols);

#endif //MATRIX_H
