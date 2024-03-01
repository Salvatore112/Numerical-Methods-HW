#include "utils.h"

float randfrom(double min, double max) {
    double range = (max - min);
    double div = RAND_MAX / range;
    return min + (rand() / div);
}

int min(int oneValue, int anotherValue) {
    return oneValue < anotherValue ? oneValue : anotherValue;
}

double** makeArray(int M, int N){
    double **u = malloc(M * sizeof(double*));
    for (int i = 0; i < N; i++) {
        u[i] = calloc(N, sizeof(double));
        if (u[i] == NULL) {
            printf("Memory allocation failed!");
            for(int j = 0; j < i; j++) {
                free(u[j]);
            }
            free(u);
            return NULL;
        }
    }
    return u;
}

void deleteArray(double** u, int M) {
    for (int i = 0; i < M; i++) {
        free(u[i]);
    }
    free(u);
}