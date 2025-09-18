//
//  interp.c
//  lab4_analise
//
//  Created by Giovana Malaia on 18/09/25.
//

#include "interp.h"
#include <math.h>
#define PI 3.141592653589793

static double cddn(int i, int j, double* xi, double (*f) (double));

void regular (int n, double a, double b, double* xi){
    if (n == 0 ) {
        return;
    }
    if (n == 1) {
        xi[0] = a;
        return;
    }
    double passo = (b-a)/(n-1);
    for (int i=0; i<n; i++){
        xi[i] = a + i * passo;
    }
}

void chebyshev (int n, double a, double b, double* xi){
    double escala = (b-a)/2.0;
    double deslocamento = (a+b)/2.0;
    for (int i=0; i<n; i++){
        double beta = 2.0 * i + 1.0;
        double angulo = (beta * PI) / (2.0*n);
        xi[i] = escala * cos(angulo) + deslocamento;
    }
}

void coeficientes (int n, double* xi, double (*f) (double), double* bi){
    for (int k=0; k<n; k++){
        bi[k] = cddn(0, k, xi, f);
    }
}

static double cddn(int i, int j, double* xi, double (*f) (double)) {
    if (i == j){
        return f(xi[i]);
    }
    return (cddn(i + 1, j, xi, f) - cddn(i, j - 1, xi, f)) / (xi[j] - xi[i]);
}

double avalia (int n, double* xi, double* bi, double x) {
    double resultado = bi[n-1];
    for (int k = n - 2; k >= 0; k--) {
        resultado = bi[k] + resultado * (x - xi[k]);
    }
    return resultado;
}
