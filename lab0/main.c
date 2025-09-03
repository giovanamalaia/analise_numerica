#include "vetor.h"
#include "matriz.h"
#include <stdio.h>

int main (void)
{
    /* Exemplo de construção de vetor dinâmico */
    double* v = vet_cria(2);
    v[0] = 1.0;
    v[1] = 2.0;
    
    /* Exemplo de construção de vetor estático */
    double w[] = {1.0,2.0f};
    
    /* Imprime vetores (são iguais em conteúdo) */
    vet_imprime(2,v);
    vet_imprime(2,w);
    double resultado_escalar = vet_escalar (2, v, w);
    printf("Produto escalar: %f\n", resultado_escalar);
    
    double resultado_norma2 = vet_norma2 (2, v);
    printf("Norma: %f\n", resultado_norma2);
    
    int saoIguais = vet_iguais ( 2, v, w, 0.2);
    if (saoIguais) {
        printf("Os vetores são iguais.\n");
    } else{
        printf("Os vetores são diferentes.\n");
    }
    
    /* Exemplo de construção de matriz dinâmica */
    double** A = mat_cria(3,2);
    A[0][0] = 1.0;
    A[0][1] = 2.0;
    A[1][0] = 3.0;
    A[1][1] = 4.0;
    A[2][0] = 5.0;
    A[2][1] = 6.0;
    
    /* Exemplo de construção de matriz estática no formato ponteiro para ponteiro */
    double linha1[] = {1.0,2.0};
    double linha2[] = {3.0,4.0};
    double linha3[] = {5.0,6.0};
    double* B[] = {linha1,linha2,linha3};
    
    /* Imprime matrizes (são iguais em conteúdo) */
    mat_imprime(3,2,A);
    double** T = mat_cria(2,3);
    mat_transposta (3, 2, A, T);
    
    mat_imprime(3,2,B);
    double v2[] = {1.0,2.0};
    double z[] = {0,0,0};
    mat_multv (3, 2, B, v2, z);
    vet_imprime(3,z);
    printf("\n");
    
    double** C = mat_cria(2,2);
    C[0][0] = 1.0;
    C[0][1] = 2.0;
    C[1][0] = 3.0;
    C[1][1] = 4.0;
    
    double** D = mat_cria(2,2);
    D[0][0] = 1.0;
    D[0][1] = 2.0;
    D[1][0] = 3.0;
    D[1][1] = 4.0;
    
    double** E = mat_cria(2,2);
    mat_multm(2, 2, 2, C, D, E);
    mat_imprime(2,2,E);
    
    /* Apenas objetos dinâmicos podem ser liberados */
    vet_libera(v);
    mat_libera(3,A);
    
    return 0;
}
