#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "seidel.h"
#include "utils.h"

double bookF(double x, double y) { return 0; }
double bookU(double x, double y) { return (1 - 2 * y) * (1 - 2 * x) * 100; }

double sin100x_cos100y(double x, double y) { return sin(100*x) * cos(100*y); }
double d_sin100x_cos100y(double x, double y) { return -100 * sin(10 * x) * cos(10*y) -100 * sin(10*x)* cos(10* y); }

double x2_y(double x, double y) {return pow(x,2) + y;}
double d_x_y(double x, double y) {return 2;}

double sqrt_of_x2_and_y2(double x, double y) {return sqrt(pow(x,2) + pow(y,2));}
double d_sqrt_of_x2_and_y2(double x, double y) {return pow(pow(y,2)/(pow(x,2) + pow(y,2)),(3.0/2)) + pow(pow(x,2)/(pow(x,2) + pow(y,2)),(3.0/2));}

double e_x_e_y (double x, double y) { return pow(2.71, x) + pow(2.71, y);}
double d_e_x_e_y (double x, double y) { return pow(2.71, x) + pow(2.71, y);}

double exp100x2y2 (double x, double y) {return pow(2.71, -100 * (pow(x,2) + pow(y,2))) ;}
double d_exp100x2y2(double x, double y) { return  200 * (200 * pow(y,2) - 1) * pow(2.71, -100 * (pow(x,2) + pow(y,2))) + 200 * (200 * pow(x,2) - 1) * pow(2.71, -100 * (pow(x,2) + pow(y,2))); }

void experiment(function f, function u, int N) {
    net* net = initialize_net(N,64, f, u );
    clock_t begin = clock();
    printf("net size %d, %d iterations\n",N, seidel(net, 0.01));
    clock_t end = clock();
    float time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("%f\n", time_spent);
    delete_net(net);
}

int main() {
    srand (time ( NULL));
    function u = exp100x2y2;
    function f = d_exp100x2y2;
    omp_set_num_threads(8);

    for (int i = 100; i <= 1000; i += 100) {
        experiment(u,f,i);
    }
}