#include "seidel.h"

// Implementation of 11.1 algorithm version
int seidel1(double** u, double eps, int N) {
    double h = 1.0 / (N + 1);
    double dmax = 0.0;
    int counter = 0;
    do {
        dmax = 0.0;
        counter += 1; // maximum u's values change
        for (int i = 1; i < N - 1; i++) {
            for (int j = 1; j < N - 1; j++) {
                double temp = u[i][j];
                double f = (u[i - 1][j] + u[i + 1][j] + u[i][j - 1] + u[i][j + 1] - 4 * u[i][j]) / h * h;
                u[i][j] = 0.25 * (u[i - 1][j] + u[i + 1][j] +
                                  u[i][j - 1] + u[i][j + 1] - h * h * f);
                double dm = fabs(temp - u[i][j]);
                if (dmax < dm) {
                    dmax = dm;
                }
            }
        }
    } while (dmax > eps);
    return counter;
}