//
// Created by Stepan Danilov on 10/16/21.
//
#include <iostream>
#include <time.h>

#include "matrix.h"

using namespace std;

int main(int argc, char *argv[]) {
    if (argc == 2) {
        int size = atoi(argv[1]);
        double *matrix = init_matrix(size, size);
        double *vector = init_matrix(size, 1);
        double time_start, time_end;


        time_start = clock();
        matrix_multiply(matrix, matrix, size);
        vector_multiply(matrix, vector, size);
        time_end = clock();

        cout << "Matrix size=" << size << " Time elapsed: " << (time_end - time_start) / CLOCKS_PER_SEC << " " << endl;
    } else {
        cout << "usage: mat_mul <matrix_size>" << endl;
    }
    return 0;
}