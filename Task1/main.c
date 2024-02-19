#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

float randfrom(float min, float max) {
    float range = (max - min);
    float div = RAND_MAX / range;
    return min + (rand() / div);
}

void seidel(float** u, float eps, int N) {
    float h = 1/(N + 1);
    float dmax = 0.0;
    int counter = 0;
    do {
        counter += 1;
        float dmax = 0.0; // максимальное изменение значений u
        for (int i = 1; i < N - 1; i++ )
            for (int j = 1; j < N - 1; j++ ) {
                float temp = u[i][j];
                float f = (u[i - 1][j] + u[i + 1][j] + u[i][j - 1] + u[i][j + 1] - 4 * u[i][j])/ h*h;
                u[i][j] = 0.25 * (u[i - 1][j] + u[i + 1][j]+
                                  u[i][j - 1]+u[i][j + 1] - h * h * f);
                float dm = fabs(temp - u[i][j]);
                if ( dmax < dm ) {
                    dmax = dm;
                }
            }
    } while ( dmax > eps );
    printf("%d", counter);
}

int main() {
    srand (time ( NULL));
    float eps = 0.1;
    int N = 100;

    float **masA = malloc(N * sizeof(float*));
    for (int i = 0; i < N; i++) {
        masA[i] = malloc(N * sizeof(float));
        if (masA[i] == NULL) {
            printf("Memory allocation failed!");
            return -1;
        }
    }
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < N; j++) {
            masA[i][j] = randfrom(-100.0, 100.0);
        }
    }
    seidel(masA, eps, N);
}