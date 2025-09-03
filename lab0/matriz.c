#include "matriz.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double** mat_cria (int m, int n)
{
    double** A = (double**) malloc(m*sizeof(double*));
    for (int i=0; i<m; ++i)
        A[i] = (double*) malloc(n*sizeof(double));
    return A;
}

void mat_libera (int m, double** A)
{
    for (int i=0; i<m; ++i)
        free(A[i]);
    free(A);
}

void mat_imprime (int m, int n, double** A)
{
    for (int i=0; i<m; ++i) {
        for (int j=0; j<n; ++j) {
            printf("%.16g  ", A[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}

void mat_transposta (int m, int n, double **A, double** T){
    for (int i=0; i<m; ++i) {
        for (int j=0; j<n; ++j) {
            T[j][i] = A[i][j];
        }
    }
    mat_imprime (n, m, T);
}

void mat_multv (int m, int n, double** A, double* v, double* w){
    for (int i=0; i<m; ++i) {
        double soma = 0.0;
        for (int j=0; j<n; ++j) {
            soma += A[i][j] * v[j];
        }
        w[i] = soma;
    }
}

void mat_multm(int m, int n, int q, double** A, double** B, double** C) {
    for (int i = 0; i < m; i++) {
        for (int k = 0; k < q; k++) {
            double soma = 0.0;
            for (int j = 0; j < n; j++) {
                soma += A[i][j] * B[j][k];
            }
            C[i][k] = soma;
        }
    }
}

