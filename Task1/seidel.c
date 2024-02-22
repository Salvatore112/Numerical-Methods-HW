
#include "seidel.h"

// Implementation of 11.1 algorithm version
int seidel1(double** u, double eps, int N) {
    double h = 1.0 / (N + 1);
    int i, j = 0;
    double dmax, dm, temp = 0.0;
    int counter = 0;
    do {
        dmax = 0.0; // maximum u's values change
        counter += 1;
        for (i = 1; i < N - 1; i++) {
            for (j = 1; j < N - 1; j++) {
                temp = u[i][j];
                double f = (u[i - 1][j] + u[i + 1][j] + u[i][j - 1] + u[i][j + 1] - 4 * u[i][j]) / h * h;
                u[i][j] = 0.25 * (u[i - 1][j] + u[i + 1][j] +
                                  u[i][j - 1] + u[i][j + 1] - h * h * f);
                dm = fabs(temp - u[i][j]);
                if (dmax < dm) {
                    dmax = dm;
                }
            }
        }
    } while (dmax > eps);
    return counter;
}

// Implementation of 11.2 algorithm version
int seidel2(double** u, double eps, int N) {
    double h = 1.0 / (N + 1);
    int i, j = 0;
    double temp, d, dmax = 0;
    int counter = 0;
    omp_lock_t dmax_lock;
    omp_init_lock (&dmax_lock);
    do {
        dmax = 0.0; // maximum u's values change
        counter += 1;
    #pragma omp parallel for shared(u, dmax) \
                             private(i, j, temp, d)
        for (i = 1; i < N - 1; i++) {
    #pragma omp parallel for shared(u, dmax) \
                             private(j, temp, d)
            for (j = 1; j < N - 1; j++) {
                temp = u[i][j];
                double f = (u[i - 1][j] + u[i + 1][j] + u[i][j - 1] + u[i][j + 1] - 4 * u[i][j]) / h * h;
                u[i][j] = 0.25 * (u[i - 1][j] + u[i + 1][j] +
                                  u[i][j - 1] + u[i][j + 1] - h * h * f);
                d = fabs(temp - u[i][j]);
                omp_set_lock(&dmax_lock);
                if (dmax < d) {
                    dmax = d;
                }
                omp_unset_lock(&dmax_lock);
            }
        }
    } while (dmax > eps);
    return counter;
}