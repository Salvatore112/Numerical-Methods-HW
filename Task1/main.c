#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "seidel.h"
#include "utils.h"

int main() {
    srand (time ( NULL));
    double eps = 0.1;
    int N = 100;

    double **u = makeArray(N,N);

    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < N; j++) {
            u[i][j] = randfrom(-100.0, 100.0);
        }
    }

    clock_t begin = clock();
    printf("%d iterations\n", seidel4(u, eps, N));
    clock_t end = clock();
    float time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("time spent %f", time_spent);
}