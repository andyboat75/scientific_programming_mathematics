#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "eratosthenes.h"

int main()
{
    int i, N;
    Eratosthenes* era;

    printf("Please enter value N: ");
    scanf("%d",&N);

    era=newEratosthenes();
    era=doEratosthenesSieve(era,N);
    
    printf("\n nmax = %d, n = %d \n",era->nmax,era->n);
    printf("\n primes= \n");

    for (i=0;i<=era->n-1;i++)
    {
        printf("\n %d \n",era->prime_numbers[i]);
    }
}
