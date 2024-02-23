#pragma once
#include <stdio.h>
#include <omp.h>
#include <math.h>
#include <stdlib.h>

// Get a random float number from the given range
float randfrom(double min, double max);

// Allocate memory for 2D array with M rows and N columns
double** makeArray(int M, int N);

// Free memory taken by 2D array with M rows and N columns
void deleteArray(double** u, int N);