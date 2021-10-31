#include <omp.h>
#include <iostream>
using namespace std;

#define SQUARE_SIZE 2.0
#define N_THREADS 10
#define N_POINTS 1e8


//
// Created by Stepan Danilov on 10/31/21.
//
size_t is_inside_circle(double x, double y) {
    if (x * x + y * y < SQUARE_SIZE * SQUARE_SIZE)
        return 1;
    return 0;
}


double calculate_pi(size_t n_points) {
    unsigned int i, tid;
    size_t inside_circle = 0;


#pragma omp parallel private(i,tid)
    {
        tid = omp_get_thread_num();
    #pragma omp for reduction(+:inside_circle)
        for (i = 0; i < n_points; ++i) {
            unsigned int seed = tid + 12537 * i;
            double x = SQUARE_SIZE * rand_r(&seed) / RAND_MAX;
            double y = SQUARE_SIZE * rand_r(&seed) / RAND_MAX;

            inside_circle += is_inside_circle(x, y);
        }
    }
    return 4.0 * inside_circle / n_points;
}


int main(int argc, char** argv) {
    double start;
    omp_set_num_threads(N_THREADS);

    start = omp_get_wtime();
    double pi = calculate_pi(N_POINTS);
    printf("Time is %lf\n", omp_get_wtime() - start);
    printf("monte carlo result: pi=%.7f\n", pi);
    return 0;
}