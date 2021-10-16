//
// Created by Stepan Danilov on 10/16/21.
//

#include <stdlib.h>
#include <cstring>


double *init_matrix(int col, int row) {
    double *matrix = new double[col * row];

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            matrix[i * col + j] = rand();

    return matrix;
}


double *matrix_multiply(double *mat_1, double *mat_2, int size) {
    double *ans = new double[size * size];

    std::memset(ans, 0, size * size * sizeof(double));
    for (int j = 0; j < size; j++)
        for (int i = 0; i < size; i++)
            for (int k = 0; k < size; k++)
                ans[i * size + j] += mat_1[i * size + k] * mat_2[k * size + j];

    return ans;
}


double *vector_multiply(double *matrix, double *vector, int size) {
    double *ans = new double[size];

    std::memset(ans, 0, size * sizeof(double));
    for (int j = 0; j < size; j++)
        for (int i = 0; i < size; i++)
            ans[i] += matrix[i * size + j] * vector[j];

    return ans;
}
