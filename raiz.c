//
//  raiz.c
//  lab2_analise
//
//  Created by Giovana Malaia on 04/09/25.
//

#include "raiz.h"
#include <math.h>

int bissecao (double a, double b, double (*f) (double x), double* r){
    int iteracoes = 0;
    double fa = f(a);
    double fb = f(b);
    
    if (fa * fb > 0) return -1;
    
    double c, fc;
    
    while ((b-a)/2.0 > 0.5e-8){
        iteracoes++;
        c = (a+b)/2.0;
        fc = f(c);
        
        if (fabs(fc)<1e-12) break;
        if (fa * fc < 0) {
            b = c;
            fb = fc;
        } else {
            a = c;
            fa = fc;
        }
    }
    
    *r = (a+b)/2.0;
    return iteracoes;
}
