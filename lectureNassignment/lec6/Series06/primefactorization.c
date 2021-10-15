#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include "eratosthenes.h"
#include "primefactorization.h"

int main()
{
    int N;
    int i;
    int mult;

    printf("Enter the number: ");
    scanf("%d", &N);

    Factorization* vector;
    vector = newFactorization();
    vector = computePrimeFactorization(vector,N);

    printf("\n N = %d",N);
    printf("\n n = %d",vector->n);

    for (i = 0; i < vector -> n; i++)
    {
        printf("\n Prime: %d with mult.: %d", vector -> n_vector[i], vector -> n_vector_multiplicities[i]);
    } 

    mult = recomposeInteger(vector);

    printf("\n The recomposed number is %d \n", mult);

}