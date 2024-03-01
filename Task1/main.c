#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include "seidel.h"
#include "utils.h"

int bookFunction(int N, int NB) {
    omp_set_num_threads(8);
    double eps = 0.1;
    double h = 1.0 / (N + 1);

    double **u = makeArray(N + 2,N + 2);
    double **f = makeArray(N + 2,N + 2);

    // Book's conditions
    for (int i = 0; i <= N + 1; i ++) {
        for (int j = 0; j <= N + 1; j++) {

            f[i][j] = 0;

            if (i == 0) {
                u[i][j] = 100 - 200 * j * h;
            } // f(0, j) = 100 - 200 * y where y = j * h
            if (i == 1) {
                u[i][j] = -100 + 200 * j * h;
            } // f(1, j) = 100 - 200 * y where y = j * h

            if (j == 0) {
                u[i][j] = 100 - 200  * i * h;
            } // f(i, 0) = 100 - 200 * x where x = i * h

            if (j == 1) {
                u[i][j] = -100 + 200 * i * h;
            } // f(i, 1) = 100 - 200 * x where x = i * h
            else {
                u[i][j] = randfrom(-100.0, 100.0);
            }
        }
    }
    return seidel6(u,f,eps,N,NB);
}

// Book function with small boundaries function
int largeBoundaries(int N, int NB) {
    omp_set_num_threads(8);
    double eps = 0.1;
    double h = 1.0 / (N + 1);

    double **u = makeArray(N + 2,N + 2);
    double **f = makeArray(N + 2,N + 2);

    for (int i = 0; i <= N + 1; i ++) {
        for (int j = 0; j <= N + 1; j++) {

            f[i][j] = 0;

            if (i == 0) {
                u[i][j] = INT_MAX;
            } // f(0, j) = 100 - 200 * y where y = j * h
            if (i == N - 1) {
                u[i][j] = INT_MAX;
            } // f(1, j) = 100 - 200 * y where y = j * h

            if (j == 0) {
                u[i][j] = INT_MAX;
            } // f(i, 0) = 100 - 200 * x where x = i * h

            if (j == N - 1) {
                u[i][j] = INT_MAX;
            } // f(i, 1) = 100 - 200 * x where x = i * h
            else {
                u[i][j] = randfrom(-100.0, 100.0);
            }
        }
    }
    return seidel6(u,f,eps,N,NB);
}

// Function that is always 0
int zeroFunction(int N, int NB) {
    omp_set_num_threads(8);
    double eps = 0.1;
    double h = 1.0 / (N + 1);

    double **u = makeArray(N + 2,N + 2);
    double **f = makeArray(N + 2,N + 2);

    for (int i = 0; i <= N + 1; i ++) {
        for (int j = 0; j <= N + 1; j++) {

            f[i][j] = 0;

            u[i][j] = 0;
        }
    }
    return seidel6(u,f,eps,N,NB);
}


// Book function with small boundaries function
int smallBoundries(int N, int NB) {
    omp_set_num_threads(8);
    double eps = 0.1;
    double h = 1.0 / (N + 1);

    double **u = makeArray(N + 2,N + 2);
    double **f = makeArray(N + 2,N + 2);

    for (int i = 0; i <= N + 1; i ++) {
        for (int j = 0; j <= N + 1; j++) {

            f[i][j] = 0;

            if (i == 0) {
                u[i][j] = INT_MIN;
            } // f(0, j) = 100 - 200 * y where y = j * h
            if (i == N - 1) {
                u[i][j] = INT_MIN;
            } // f(1, j) = 100 - 200 * y where y = j * h

            if (j == 0) {
                u[i][j] = INT_MIN;
            } // f(i, 0) = 100 - 200 * x where x = i * h

            if (j == N - 1) {
                u[i][j] = INT_MIN;
            } // f(i, 1) = 100 - 200 * x where x = i * h
            else {
                u[i][j] = randfrom(-100.0, 100.0);
            }
        }
    }
    return seidel6(u,f,eps,N,NB);
}

// function with exponents
int exponents(int N, int NB) {
    omp_set_num_threads(8);
    double eps = 0.1;
    double h = 1.0 / (N + 1);

    double **u = makeArray(N + 2,N + 2);
    double **f = makeArray(N + 2,N + 2);

    for (int i = 0; i <= N + 1; i ++) {
        for (int j = 0; j <= N + 1; j++) {

            f[i][j] = pow((i * h), (j * h));

            if (i == 0) {
                u[i][j] = 100 - 200 * j * h;
            } // f(0, j) = 100 - 200 * y where y = j * h
            if (i == N - 1) {
                u[i][j] = 100 - 200 * j * h;
            } // f(1, j) = 100 - 200 * y where y = j * h

            if (j == 0) {
                u[i][j] = 100 - 200 * i * h;
            } // f(i, 0) = 100 - 200 * x where x = i * h

            if (j == N - 1) {
                u[i][j] = 100 - 200 * i * h;
            } // f(i, 1) = 100 - 200 * x where x = i * h
            else {
                u[i][j] = randfrom(-100.0, 100.0);
            }
        }
    }
    return seidel6(u,f,eps,N,NB);
}

int main() {
    omp_set_num_threads(8);
    srand (time ( NULL));


    clock_t begin = clock();
    printf("%d iterations\n", exponents(1000, 30));
    clock_t end = clock();
    float time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("time spent %f", time_spent);
}