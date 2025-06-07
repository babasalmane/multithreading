#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "config.h"

// structure pour passer les arguments aux threads
struct ThreadArgs {
    int startRow;       // ligne de depart pour ce thread
    int numRows;        // nombre de lignes à calculer par ce thread
    long *weightsMatrix;
    long *tempMatrix;
    long *resultMatrix;
};

// fonction principale pour lancer le produit matriciel parallele
void perform_matrix_product(long *weights, long *temperatures, long *result, int n_threads);

#endif
