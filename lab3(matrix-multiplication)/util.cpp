//
// Created by randil on 2/22/18.
//
#define Z 1.960
#define R 5

#include <cmath>
#include <omp.h>

double start_time, end_time;

void timer_start() {
    start_time = omp_get_wtime();
}

void timer_stop() {
    end_time = omp_get_wtime();
}

double get_elapsed_time() {
    return end_time - start_time;
}

void calc_sample(int size, double *values, double *result) {
    double sum = 0;
    double s_sum = 0;

    for (int i = 0; i < size; i++) {
        sum += values[i];
        s_sum += pow(values[i], 2);
    }

    double ave = sum / size;
    double sd = sqrt(s_sum / size - pow(ave, 2));
    double s_size = ceil(pow((100 * Z * sd) / (R * ave), 2));

    result[0] = ave;
    result[1] = sd;
    result[2] = s_size;
}
