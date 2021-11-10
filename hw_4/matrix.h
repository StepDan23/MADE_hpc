#include <cstdlib>
#include <cstring>
#include <cstdio>


//
// Created by Stepan Danilov on 10/16/21.
//
double *init_adj_matrix(int size, double conn_prob);

void print_matrix(double *matrix, int size);

void matrix_multiply(double *mat_1, double *mat_2, double *result, int size);

void matrix_vector_multiply(double *matrix, double *vector, double *result, int size);

void matrix_power(double *matrix, double *result, int pow, int size);
