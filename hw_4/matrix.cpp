#include "matrix.h"


//
// Created by Stepan Danilov on 10/16/21.
//
double *init_adj_matrix(int size, double conn_prob) {
    double *matrix = new double[size * size];
    unsigned int seed = 127;

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++) {
            if (i == j)
                matrix[i * size + j] = 0;
            else
                matrix[i * size + j] = (double) (rand_r(&seed) % 100 <= (conn_prob * 100));
        }

    return matrix;
}


void print_matrix(double *matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%.1f ", matrix[i * size + j]);
        }
        printf("\n");
    }
}


void matrix_multiply(double *mat_1, double *mat_2, double *result, int size) {
    double *ans = new double[size * size];

//#pragma omp parallel for shared(mat_1, mat_2, result)
    for (int j = 0; j < size; j++)
        for (int i = 0; i < size; i++) {
            ans[i * size + j] = 0;

            for (int k = 0; k < size; k++)
                ans[i * size + j] += mat_1[i * size + k] * mat_2[k * size + j];
        }

//#pragma omp parallel for shared(ans, result)
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            result[i * size + j] = ans[i * size + j];
    delete[]ans;
}


void matrix_vector_multiply(double *matrix, double *vector, double *result, int size) {
//#pragma omp parallel for shared(matrix, vector, result)
    for (int i = 0; i < size; i++) {
        result[i] = 0.0;

        for (int j = 0; j < size; j++)
            result[i] += vector[j] * matrix[i * size + j];
    }
}


void matrix_power(double *matrix, double *result, int pow, int size) {
    if (pow == 0) {
//    #pragma omp parallel for shared(matrix, result)
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++) {
                // eye matrix
                result[i * size + j] = (j == i) ? 1 : 0;
            }
        return;
    }
    matrix_power(matrix, result, pow / 2, size);
    matrix_multiply(result, result, result, size);
    if (pow % 2 != 0)
        matrix_multiply(result, matrix, result, size);
}
