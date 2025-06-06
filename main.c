#include <stdio.h>
#include <stdlib.h>
#include "config.h"
#include "matrix.h"
#include "calculator.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <numThreads>\n", argv[0]);
        return 1;
    }

    int n_threads;
    sscanf(argv[1], "%d", &n_threads);

    if (n_threads <= 0 || n_threads > MAX_THREADS) {
        printf("Error: Number of threads must be between 1 and %d.\n", MAX_THREADS);
        return 1;
    }

    // 1. Allouer les matrices
    long *weights_matrix = create_matrix(ROWS, COLS);       // Matrice n x n
    long *temperatures_matrix = create_matrix(ROWS, 1);    // Matrice (vecteur) n x 1
    long *result_matrix = create_matrix(ROWS, 1);          // Matrice résultat n x 1

    // 2. Remplir les matrices avec des valeurs
    // fill_matrix est conçu pour une matrice 2D, nous l'adaptons un peu ici
    fill_matrix(weights_matrix, ROWS, COLS); // Remplit la matrice de poids
    
    // Remplir manuellement le vecteur de températures
    printf("Temperature Matrix (vector):\n[");
    for (int i = 0; i < ROWS; i++) {
        temperatures_matrix[i] = i + 1;
        printf("%ld:", temperatures_matrix[i]);
    }
    printf("]\n\n");
    
    printf("Weights Matrix:\n");
    print_matrix(weights_matrix, ROWS, COLS);

    printf("\nPress Enter to start calculation...");
    getchar();

    // 3. Lancer le calcul du produit matriciel
    perform_matrix_product(weights_matrix, temperatures_matrix, result_matrix, n_threads);

    // 4. Afficher le résultat
    printf("\nResulting Matrix (Poids x Températures):\n");
    print_matrix(result_matrix, ROWS, 1);

    // 5. Libérer la mémoire
    free(weights_matrix);
    free(temperatures_matrix);
    free(result_matrix);

    return 0;
}
