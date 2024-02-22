#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>
#include "seidel.h"

float randfrom(double min, double max) {
    double range = (max - min);
    double div = RAND_MAX / range;
    return min + (rand() / div);
}

int main() {
    srand (time ( NULL));
    double eps = 0.1;
    int N = 100;

    double **u = malloc(N * sizeof(double*));
    for (int i = 0; i < N; i++) {
        u[i] = malloc(N * sizeof(double));
        if (u[i] == NULL) {
            printf("Memory allocation failed!");
            return -1;
        }
    }

    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < N; j++) {
            u[i][j] = randfrom(-100.0, 100.0);
        }
    }
    printf("%d iterations", seidel2(u, eps, N));
}