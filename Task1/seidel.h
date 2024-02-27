#pragma once
#include <stdio.h>
#include <omp.h>
#include <math.h>
#include <stdlib.h>
#include "utils.h"

// Implementation of 11.1 algorithm
int seidel1(double** u, double** f, double eps, int N);

// Implementation of 11.2 algorithm
int seidel2(double** u, double** f, double eps, int N);

// Implementation of 11.3 algorithm
int seidel3(double** u, double** f, double eps, int N);

// Implementation of 11.4 algorithm (Gauss-Jacobi)
int seidel4(double** u, double** f, double eps, int N);

// Implementation of 11.6 algorithm (Block approach to the wave data processing method)
int seidel6(double** u, double** f, double eps, int N);