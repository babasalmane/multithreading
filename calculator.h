#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "config.h"

// Structure pour passer les arguments aux threads
struct ThreadArgs {
    int startRow;       // Ligne de départ pour ce thread
    int numRows;        // Nombre de lignes à calculer par ce thread
    long *weightsMatrix;
    long *tempMatrix;
    long *resultMatrix;
};

// Fonction principale pour lancer le produit matriciel parallèle
void perform_matrix_product(long *weights, long *temperatures, long *result, int n_threads);

#endif //CALCULATOR_H
