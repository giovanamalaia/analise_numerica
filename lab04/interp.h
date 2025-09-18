//
//  interp.h
//  lab4_analise
//
//  Created by Giovana Malaia on 18/09/25.
//

#ifndef INTERPOLATION_H
#define INTERPOLATION_H

void regular (int n, double a, double b, double* xi);
void chebyshev (int n, double a, double b, double* xi);
void coeficientes (int n, double* xi, double (*f) (double), double* bi);
double avalia (int n, double* xi, double* bi, double x);

#endif
