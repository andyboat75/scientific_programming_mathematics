#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include "eratosthenes.h"
#include "primefactorization.h"


int gcd(int a, int b)
{
    int result=1;
    int i;
    int j;
    int k=1;



    Factorization* A;
    A = newFactorization();
    A = computePrimeFactorization(A,a);
    //printf("%d", A);

    Factorization* B;
    B = newFactorization();
    B = computePrimeFactorization(B,b);
    //printf("%d", B);

    for (i = 0; i < A -> n; i++)
    {
        for (j = 0 ; j < B -> n; j++)
        {
            if(A -> n_vector[i] == B -> n_vector[j])
            {
                if(A -> n_vector_multiplicities[i] > B -> n_vector_multiplicities[j])
                {
                    k=k*pow(B->n_vector[i],B->n_vector_multiplicities[i]);   
                } 
                else 
                {    
                    k = k*pow(A->n_vector[j],A->n_vector_multiplicities[j]);
                }

            }


        }
    }

    return k;
}

int lcm(int a, int b)
{
    assert(a%1==0);
    assert(b%1==0);
    int result;
    int k = gcd(a,b);

    result = (a*b)/k;
     return result;

}

int main()
{

    int a,b,r;
    
    printf("\n Please enter first positive number: ");
    scanf("%d",&a);
    
    printf("\n Please enter second positive number: ");
    scanf("%d",&b);
    
    r=lcm(a,b);

    printf("\n The least common multiple is %d\n ",r);

    
    printf("\n Please enter first positive number: ");
    scanf("%d",&a);
    
    printf("\n Please enter second positive number: ");
    scanf("%d",&b);
    
    r=gcd(a,b);

    printf("\nThe greatest common divisor is %d\n ",r);

    return 0;
}