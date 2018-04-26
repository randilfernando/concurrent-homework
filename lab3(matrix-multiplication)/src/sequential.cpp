//
// Created by randil on 2/23/18.
//

#include <iostream>
#include "matrix.h"
#include "util.h"

using namespace std;

void print_values(int size, double *values, const string &technique);

void calculate_values(int n, int size);

double run_sequential(int n, double **mat1, double **mat2, double **mat_res);

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
    double **mat1 = mat_create(n);
    double **mat2 = mat_create(n);
    double **mat_res = mat_create(n);

    double values_seq[size];

    cout << "matrix size: " << n << endl;

    for (int i = 0; i < size; i++) {
        mat_populate(n, mat1, 3);
        mat_populate(n, mat2, 100);
        values_seq[i] = run_sequential(n, mat1, mat2, mat_res);
    }

    print_values(size, values_seq, "sequential");

    mat_free(n, mat1);
    mat_free(n, mat2);
    mat_free(n, mat_res);
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

double run_sequential(int n, double **mat1, double **mat2, double **mat_res) {
    timer_start();
    // multiply two matrices (mat1 and mat2) and store the result in mat_res
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            mat_res[i][j] = 0;
            for (int k = 0; k < n; ++k) {
                mat_res[i][j] += mat1[i][k] * mat2[k][i];
            }
        }
    }
    timer_stop();
    return get_elapsed_time();
}
