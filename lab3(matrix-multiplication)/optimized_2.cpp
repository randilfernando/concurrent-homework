//
// Created by malaka on 2/20/18.
//

#define BLOCK_SIZE 8
#define N 2000

#include <iostream>
#include "util.h"

using namespace std;

void calculate_values(int n, int size);

void mat_populate(int n);

void mat_transpose(int n);

double run_optimized(int n);

void print_values(int size, double *values, const string &technique);

double mat1_flat[N * N];
double mat2_flat[N * N];
double mat_res_flat[N * N];

int main() {
    int size, n, opt;

    cout << "1 - To run one test" << endl;
    cout << "2 - To run the bulk test" << endl;
    cout << "Enter your choice: ";
    cin >> opt;

    if (opt == 1) {
        cout << "Enter sample size: ";
        cin >> size;
        cout << "Enter matrix length: ";
        cin >> n;
        calculate_values(n, size);
    } else {
        cout << "Enter sample size: ";
        cin >> size;
        for (int i = 1; i < 11; ++i) {
            calculate_values(i * 200, size);
        }
    }
}

void calculate_values(int n, int size) {
    double values_opt[size];

    cout << "matrix size: " << n << endl;

    for (int i = 0; i < size; i++) {
        mat_populate(n);
        mat_transpose(n);
        values_opt[i] = run_optimized(n);
    }

    print_values(size, values_opt, "optimized");
}

void mat_populate(int n) {
    srand((unsigned int) (time(nullptr))); // if time equals generate different values
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mat1_flat[i * n + j] = (rand() % 100) + 1;
            mat2_flat[i * n + j] = (rand() % 100) + 1;
        }
    }
}

void mat_transpose(int n) {
    double temp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            temp = mat2_flat[i * n + j];
            mat2_flat[i * n + j] = mat2_flat[j * n + i];
            mat2_flat[j * n + i] = temp;
        }
    }
}

void print_values(int size, double *values, const string &technique) {
    double result[3];

    calc_sample(size, values, result);

    cout << technique << ": "
         << "[ average: " << result[0] << " s | "
         << "standard deviation: " << result[1] << " | "
         << "sample size needed: " << result[2] << " ]"
         << endl;
}

double run_optimized(int n) {
    int i_n, j_n;
    double sum;

    timer_start();
    // run program in multi cores omp will choose optimal number of thread (number of cores available)
    // optimised loop using caching and processor architecture
#pragma omp parallel for shared(mat1_flat, mat2_flat, mat_res_flat) private(i_n, j_n, sum)
    for (int i = 0; i < n; ++i) {
        i_n = i * n; // calculate once
        for (int j = 0; j < n; ++j) {
            j_n = j * n; // calculate once
            sum = 0; // use local variable to store sum, save a lot of unwanted memory transfers
            for (int k = 0; k < n; k += BLOCK_SIZE) {
                sum += mat1_flat[i_n + k] * mat2_flat[j_n + k] +
                       mat1_flat[i_n + k + 1] * mat2_flat[j_n + k + 1] +
                       mat1_flat[i_n + k + 2] * mat2_flat[j_n + k + 2] +
                       mat1_flat[i_n + k + 3] * mat2_flat[j_n + k + 3] +
                       mat1_flat[i_n + k + 4] * mat2_flat[j_n + k + 4] +
                       mat1_flat[i_n + k + 5] * mat2_flat[j_n + k + 5] +
                       mat1_flat[i_n + k + 6] * mat2_flat[j_n + k + 6] +
                       mat1_flat[i_n + k + 7] * mat2_flat[j_n + k + 7];
            }
            mat_res_flat[i_n + j] = sum; // access mat_res only once
        }
    }
    timer_stop();

    return get_elapsed_time();
}
