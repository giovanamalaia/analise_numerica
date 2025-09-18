//
//  sistlinear.c
//  lab3_analise
//
//  Created by Giovana Malaia on 15/09/25.
//

#include <stdio.h>
#include "sistlinear.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void gauss (int n, double** A, double* b, double* x) {
    for (int j = 0; j < n-1; j++) {
        int p = j;
        for (int i = j+1; i < n; i++) {
            if (fabs(A[i][j]) > fabs(A[p][j])) {
                p = i;
            }
        }
        if (p != j) {
            if (p != j) {
                for (int k = 0; k < n; k++) {
                    double temp = A[j][k];
                    A[j][k] = A[p][k];
                    A[p][k] = temp;
                }
                double tempb = b[j];
                b[j] = b[p];
                b[p] = tempb;
            }
        }
        for (int i = j+1; i < n; i++) {
            double f = A[i][j] / A[j][j];
            for (int k = j; k < n; k++) {
                A[i][k] -= f * A[j][k];
            }
            b[i] -= f * b[j];
        }
    }
    for (int i = n-1; i >= 0; i--) {
        double soma = 0.0;
        for (int k = i+1; k < n; k++) {
            soma += A[i][k] * x[k];
        }
        x[i] = (b[i] - soma) / A[i][i];
    }
}
