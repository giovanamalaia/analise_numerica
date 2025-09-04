//
//  main.c
//  lab2_analise
//
//  Created by Giovana Malaia on 04/09/25.
//

#include "raiz.h"
#include <math.h>
#include <stdio.h>

// contagem de avaliacoes da funcao (N=0 antes de chamar o metodo da bissecao)
int N;

static double f1 (double x)
{
  N++;
  return x*x*x + 2*x*x - 2;
}

static double f2 (double x)
{
  N++;
  return x*x*x*x + x + 1;
}

static double massa (double x)
{
    N++;
    const double g = 9.8;
    const double c = 15.0;
    const double t = 9.0;
    const double v = 35.0;
    
    if (x <= 0.0) return v;
    
    return v - (g * x / c) * (1.0 - exp(-(c*t)/x));
}

void testebissecao (double a, double b, double (*f)(double))
{
  N = 0;
  double x_r;
  int it = bissecao(a, b, f, &x_r);
  if (it < 0) {
    printf("Intervalo sem inversao, it: %d, av: %d\n", it, N);
  }
  else {
    printf("raiz: %.9f, it: %d, av: %d\n", x_r, it, N);
  }
}

int main (void)
{
  printf("Testes com bissecao: 'it': iteracoes, 'av': avaliacoes de f(x)\n");
  printf("Q1 de -3 a +3:\n");
  testebissecao(-3, 3, f1);
  printf("Q2 de -3 a +3:\n");
  testebissecao(-3, 3, f2);
  printf("Q1 de -5 a +5:\n");
  testebissecao(-5, 5, f1);
  printf("Q3 de 0 a 150:\n");
  testebissecao(0, 150, massa);
  printf("Q3 de 0 a 250:\n");
  testebissecao(0, 250, massa);
  printf("Q3 de 0 a  50:\n");
  testebissecao(0, 50, massa);
  return 0;
}

