#pragma once
#include <stdio.h>
#include <omp.h>
#include <math.h>
#include <stdlib.h>
#include "utils.h"

// Net containing value of u and f as well as their size, block size, and h
struct net {
    double h;
    int N;
    int block_size;

    double** u;
    double** f;
} typedef net;

// Function taking 2 doubles and returning a double
typedef double (*function) (double, double);

// Implementation of the algorithm
int seidel(net* nt, double eps);

// Fill in f and u matrices with the value of f and u functions
net* initialize_net(int N, int block_size, function f, function u);

// Free up memory taken by net
void delete_net(net* net);
