#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "seidel.h"
#include "utils.h"

int main() {
    srand (time ( NULL));
    double eps = 0.1;
    int N = 100;
    double h = 1.0 / (N + 1);

    double **u = makeArray(N + 2,N + 2);
    double **f = makeArray(N + 2,N + 2);

    // Book's conditions
    for (int i = 0; i <= N + 1; i ++) {
        for (int j = 0; j <= N + 1; j++) {

            f[i][j] = 0;

            if (i == 0) {
                u[i][j] = 100 - 200 * j * h;
                if(j == N - 1){
                    continue;
                }
            } // u(0, j) = 100 - 200 * y where y = j * h
            if (i == 1) {
                u[i][j] = -100 + 200 * j * h;
            } // u(1, j) = 100 - 200 * y where y = j * h

            if (j == 0) {
                u[i][j] = 100 - 200  * i * h;
            } // u(i, 0) = 100 - 200 * x where x = i * h

            if (j == 1) {
                u[i][j] = -100 + 200 * i * h;
            } // u(i, 1) = 100 - 200 * x where x = i * h
            else {
            u[i][j] = randfrom(-100.0, 100.0);
            }
        }
    }

    clock_t begin = clock();
    printf("%d iterations\n", seidel2(u,f, eps, N));
    clock_t end = clock();
    float time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("time spent %f", time_spent);
}