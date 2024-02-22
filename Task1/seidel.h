#pragma once
#include <stdio.h>
#include <omp.h>
#include <math.h>

// Implementation of 11.1 algorithm version
int seidel1(double** u, double eps, int N);

// Implementation of 11.2 algorithm version
int seidel2(double** u, double eps, int N);