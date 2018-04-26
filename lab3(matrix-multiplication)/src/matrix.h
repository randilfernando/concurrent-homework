//
// Created by randil on 2/23/18.
//

#ifndef MATRIX_MULTIPLIER_MATRIX_H
#define MATRIX_MULTIPLIER_MATRIX_H

double **mat_create(int n);

double *mat_create_flat(int n);

void mat_populate(int n, double **mat, int a);

void mat_transpose(int n, double **mat);

void mat_flat(int n, double *mat_flat, double **mat);

void mat_free(int n, double **mat);

void mat_free_flat(const double *mat);

#endif //MATRIX_MULTIPLIER_MATRIX_H
