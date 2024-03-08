#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "seidel.h"
#include "utils.h"

double bookF(double x, double y) { return 0; }

double bookU(double x, double y) { return (1 - 2 * y) * (1 - 2 * x) * 100; }

double f_ackermann (double x, double y) {
    return -20 * exp(-0.2 * sqrt(0.5 * (pow(x, 2) + pow(y, 2)))) - exp(0.5 * (cos(2 * 3.14 * x) + cos(2 * 3.14 * y))) + 2.71 + 20;
}

double sinx (double x, double y) {
    return sin(x);
}

double cosx (double x, double y) {
    return -sin(x) - cos(x);
}


int main() {
    srand (time ( NULL));

    function u = bookU;
    function f = bookF;
    net* net = initialize_net(200,64, f, u );

    omp_set_num_threads(8);

    clock_t begin = clock();
    printf("%d iterations\n", seidel(net, 0.1));
    clock_t end = clock();
    float time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("time spent %f", time_spent);
    delete_net(net);
}