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
            } // the end of nested parallel region
        } // the end of outer parallel region
    } while (dmax > eps);
    return counter;
}

// Implementation of 11.3 algorithm version
int seidel3(double** u, double eps, int N) {
    double h = 1.0 / (N + 1);
    int i, j = 0;
    double temp, d, dmax, dm = 0;
    int iterations = 0;
    omp_lock_t dmax_lock;
    omp_init_lock (&dmax_lock);
    do {
        dmax = 0.0; // maximum u's values change
        iterations += 1;
    #pragma omp parallel for shared(u,dmax)\
                             private(i,j,temp,d,dm)
        for (i = 1; i < N - 1; i++) {
            dm = 0;
            for (j = 1; j < N - 1; j++) {
                temp = u[i][j];
                double f = (u[i - 1][j] + u[i + 1][j] + u[i][j - 1] + u[i][j + 1] - 4 * u[i][j]) / h * h;
                u[i][j] = 0.25 * (u[i - 1][j] + u[i + 1][j] +
                                  u[i][j - 1] + u[i][j + 1] - h * h * f);
                d = fabs(temp - u[i][j]);
                if (dm < d) {
                    dm = d;
                }
            }
            omp_set_lock(&dmax_lock);
            if ( dmax < dm ) dmax = dm;
            omp_unset_lock(&dmax_lock);
        } // the end parallel region
    } while (dmax > eps);
    return iterations;
}

// Implementation of 11.4 algorithm version
int seidel4(double** u, double eps, int N) {
    double **un = makeArray(N,N);
    double h = 1.0 / (N + 1);
    int i, j = 0;
    double temp, d, dmax, dm = 0;
    int counter = 0;
    omp_lock_t dmax_lock;
    omp_init_lock (&dmax_lock);
    do {
        dmax = 0.0; // maximum u's values change
        counter += 1;
    #pragma omp parallel for shared(u,dmax)\
                             private(i,j,temp,d,dm)
        for (i = 1; i < N - 1; i++) {
            dm = 0;
            for (j = 1; j < N - 1; j++) {
                temp = u[i][j];
                double f = (u[i - 1][j] + u[i + 1][j] + u[i][j - 1] + u[i][j + 1] - 4 * u[i][j]) / h * h;
                un[i][j] = 0.25 * (u[i - 1][j] + u[i + 1][j] +
                                  u[i][j - 1] + u[i][j + 1] - h * h * f);
                d = fabs(temp - un[i][j]);
                if (dm < d) {
                    dm = d;
                }
            }
            omp_set_lock(&dmax_lock);
            if ( dmax < dm ) dmax = dm;
            omp_unset_lock(&dmax_lock);
        } // the end of outer parallel region
        for ( i = 1; i < N - 1; i++ ) // data update
            for ( j = 1; j < N - 1; j++ )
                u[i][j] = un[i][j];
    } while (dmax > eps);
    deleteArray(un, N);
    return counter;
}

int seidel6(double** u, double eps, int N) {
    double h = 1.0 / (N + 1);
    int i, j, nx = 0;
    int NB = 2;
    double temp, d, dmax, dm = 0;
    int counter = 0;
    omp_lock_t dmax_lock;
    omp_init_lock (&dmax_lock);
    do {
        counter += 1;
        dmax = 0.0;
        // wave growth (wave size is nx+1)
        for ( nx=0; nx<NB; nx++ ) {
#pragma omp parallel for shared(nx) private(i,j)
            for ( i=0; i<nx+1; i++ ) {
                j = nx - i;
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
            } // the end parallel region
        }
        // wave attenuation
        for ( nx=NB-2; nx>-1; nx-- ) {
#pragma omp parallel for shared(nx) private(i,j)
            for ( i=0; i<nx+1; i++ ) {
                j = 2*(NB-1) - nx - i;
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
            } // the end parallel region
        }
    } while ( dmax > eps );
    return counter;
}

