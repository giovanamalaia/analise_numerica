#include "vetor.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double* vet_cria (int n)
{
    double* v = (double*)malloc(n*sizeof(double));
    return v;
}

void vet_libera (double* v)
{
    free(v);
}

void vet_mults (int n, double* v, double s, double* w)
{
    for (int i=0; i<n; ++i)
        w[i] = v[i]*s;
}

void vet_imprime (int n, double* v)
{
    for (int i=0; i<n; ++i)
    printf("%.16g  ",v[i]);
    printf("\n");
}

double vet_escalar (int n, double* v, double* w){
    double valor = 0.0;
    for (int i=0; i<n; i++) {
        valor += v[i]*w[i];
    }
    return valor;
}

double vet_norma2 (int n, double* v){
    double valor = 0.0;
    double soma = 0.0;
    for (int i=0; i<n; i++){
        soma += pow(v[i], 2);
    }
    valor = sqrt(soma);
    return valor;
}

int vet_iguais (int n, double* v, double* w, double tol){
    for (int i=0; i<n; i++) {
        if (fabs(v[i]-w[i]) > tol){
            return 0;
        }
    }
    return 1;          
}

