#include "taylor.h"
#include <stdlib.h>

double avalia_taylor (int n, double *c, double x0, double x) {
    if (n <= 0 || c == NULL) return 0.0;
    
    double t = x - x0;
    double potencia = 1.0;
    double fat = 1.0;
    double soma = 0.0;
    
    for (int i = 0; i < n; ++i) {
        soma += (c[i] * potencia) / fat;
        potencia *= t;
        fat *= (i + 1);
    }
    return soma;
}

double avalia_seno (int n, double x) {
    if (n <= 0) return 0.0;
    
    double *c = malloc(n * sizeof *c);
    if (!c) return 0.0;
    
    for (int i=0; i<n; i++ ){
        int resto = i % 4;
        if (resto == 1) {
            c[i] =  1.0;
        } else if (resto == 3) {
            c[i] = -1.0;
        } else {
            c[i] =  0.0;
        }
    }
    
    double resultado_seno = avalia_taylor(n, c, 0.0, x);
    free(c);
    return resultado_seno;
}
