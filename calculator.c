#include <pthread.h>
#include <stdio.h>
#include "calculator.h"

// la routine du thread calcule une partie des lignes de la matrice resultat
static void *thread_product_routine(void *arg) {
    struct ThreadArgs *currArg = (struct ThreadArgs *) arg;
    int i, j;

    // pour chaque ligne assigne a ce thread
    for (i = currArg->startRow; i < currArg->startRow + currArg->numRows; i++) {
        long sum = 0;
        // calcule le produit scalaire de la ligne i des poids et du vecteur temperatures
        for (j = 0; j < COLS; j++) {
            sum += currArg->weightsMatrix[i * COLS + j] * currArg->tempMatrix[j];
        }
        currArg->resultMatrix[i] = sum;
    }
    return NULL;
}

void perform_matrix_product(long *weights, long *temperatures, long *result, int n_threads) {
    pthread_t threads[MAX_THREADS];
    struct ThreadArgs threadArgs[MAX_THREADS];
    int i;

    int rows_per_thread = ROWS / n_threads;
    int remaining_rows = ROWS % n_threads;
    int current_row = 0;

    for (i = 0; i < n_threads; i++) {
        threadArgs[i].numRows = rows_per_thread;
        // distribue les lignes restantes une par une aux premiers threads
        if (remaining_rows > 0) {
            threadArgs[i].numRows++;
            remaining_rows--;
        }
        
        threadArgs[i].startRow = current_row;
        threadArgs[i].weightsMatrix = weights;
        threadArgs[i].tempMatrix = temperatures;
        threadArgs[i].resultMatrix = result;
        
        current_row += threadArgs[i].numRows;

        pthread_create(&threads[i], NULL, thread_product_routine, &threadArgs[i]);
    }

    // attendre la fin de tous les threads
    for (i = 0; i < n_threads; i++) {
        pthread_join(threads[i], NULL);
        printf("Thread %d has finished its calculation.\n", i);
    }
}
