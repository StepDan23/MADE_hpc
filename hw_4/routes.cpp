//#include <omp.h>

#include "matrix.h"

#define N_NODES 10
#define N_THREADS 10
#define ROUTE_LEN 5


//
// Created by Stepan Danilov on 11/7/21.
//
int main() {
    double *result = new double[N_NODES * N_NODES];
    std::memset(result, 0, N_NODES * N_NODES * sizeof(double));
//    double start = omp_get_wtime();

//    omp_set_num_threads(N_THREADS);
    double *graph = init_adj_matrix(N_NODES, 0.4);
    printf("matrix adjustment:\n");
    print_matrix(graph, N_NODES);

    matrix_power(graph, result, ROUTE_LEN, N_NODES);

    printf("result:\n");
    print_matrix(result, N_NODES);
//    printf("Time elapsed %lf\n", omp_get_wtime() - start);

    return 0;
}