//
// Created by randil on 2/23/18.
//

#include <iostream>

double **mat_create(int n) {
    auto **mat = new double *[n];

    for (int i = 0; i < n; i++) {
        mat[i] = new double[n];
    }

    return mat;
}

double *mat_create_flat(int n) {
    auto *mat = new double[n * n];
    return mat;
}

void mat_populate(int n, double **mat, int a) {
    srand((unsigned int) (a * time(nullptr)));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mat[i][j] = (rand() % 100) + 1;
        }
    }
}

void mat_transpose(int n, double **mat) {
    double temp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            temp = mat[j][i];
            mat[j][i] = mat[i][j];
            mat[i][j] = temp;
        }
    }
}

void mat_flat(int n, double *mat_flat, double **mat) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mat_flat[i * n + j] = mat[i][j];
        }
    }
}

void mat_free(int n, double **mat) {
    for (int i = 0; i < n; i++) {
        delete[] mat[i];
    }

    delete[] mat;
}

void mat_free_flat(const double *mat) {
    delete[] mat;
}