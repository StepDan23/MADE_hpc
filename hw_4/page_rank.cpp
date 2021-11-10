#include <omp.h>

#include "matrix.h"

#define N_NODES 5
#define USE_RANDOM false
#define N_THREADS 10
#define N_ITER 20
#define DAMPING 0.85

//
// Created by Stepan Danilov on 10/16/21.
//
void page_rank(double *graph, double *result, int size, int n_iter) {
    // normalize
#pragma omp parallel for shared(graph)
    for (int i = 0; i < size; i++) {
        double sum = 0.0;
        for (int j = 0; j < size; j++) {
            sum += graph[j * size + i];
        }

        for (int j = 0; j < size; j++)
            graph[j * size + i] = (sum == 0.0) ? 0.0 : graph[j * size + i] / sum;
    }

    double *rank = new double[size];
#pragma omp parallel for shared(rank)
    for (int i = 0; i < size; i++) {
        rank[i] = 1.0 / size;
    }

    for (int i = 0; i < n_iter; i++) {
        matrix_vector_multiply(graph, rank, result, size);

#pragma omp parallel for shared(graph, rank, result)
        for (int j = 0; j < size; j++) {
            result[j] = (1.0 - DAMPING) + DAMPING * result[j];
            rank[j] = result[j];
        }
    }
    delete[]rank;
}


int main() {
    double *graph;
    double *result = new double[N_NODES];

    if (USE_RANDOM) {
        graph = init_adj_matrix(N_NODES, 0.1);
    } else {
        graph = new double[N_NODES * N_NODES];
        FILE *fd = fopen("graph.txt", "r");

        int num;
        int i = 0;
        while (fscanf(fd, "%d", &num) != EOF) {
            graph[i] = num;
            i++;
        }
        fclose(fd);
    }

    double start = omp_get_wtime();
    omp_set_num_threads(N_THREADS);
    page_rank(graph, result, N_NODES, N_ITER);
    printf("Time elapsed %lf\n", omp_get_wtime() - start);

    if (!USE_RANDOM) {
        print_matrix(graph, N_NODES);
        printf("page rank:\n");
        for (int i = 0; i < N_NODES; ++i) {
            printf("%d: %.3f ", i, result[i]);
        }
        printf("\n");
    }

    delete[]graph;
    delete[]result;
    return 0;
}