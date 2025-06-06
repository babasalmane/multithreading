#include <stdio.h>
#include "matrix.h"

long *create_matrix(int rows, int cols) {
    long *matrix = malloc(rows * cols * sizeof(long));
    if (matrix == NULL) {
        perror("Failed to allocate memory for the matrix");
        exit(EXIT_FAILURE);
    }
    return matrix;
}

void fill_matrix(long *matrix, int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            matrix[i * cols + j] = i + cols * j;
        }
    }
}

void print_matrix(long *matrix, int rows, int cols) {
    int i, j;
    printf("Your matrix is as follows:\n");
    for (i = 0; i < rows; i++) {
        printf("[");
        for (j = 0; j < cols; j++) {
            printf("%ld:", matrix[i * cols + j]);
        }
        printf("]\n");
    }
}
