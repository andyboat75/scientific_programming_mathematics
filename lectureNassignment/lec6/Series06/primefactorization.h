#ifndef primefactorization
#define primefactorization

struct _Factorization_ {

    int n; //Number of prime factors in the decomposition
    int* n_vector; //Vector with the prime factors
    int* n_vector_multiplicities; //Vector of multiplicities of prime factors

};

typedef struct _Factorization_ Factorization;

Factorization* newFactorization() 
{
        
        Factorization* X = NULL;

        X = malloc(sizeof(Factorization));
        assert(X != NULL);

        X->n = 0;
        
        X->n_vector = malloc(1*sizeof(int));
        X->n_vector_multiplicities = malloc(1*sizeof(int));
        
        return X;
}

Factorization* computePrimeFactorization(Factorization* fact_struct, int N)
{

    Eratosthenes* era_struct;
    int k;
    int c=0;
    int i;
    int d=0;
    int l;



    //use here eratosthenes to get the prime numbers
    //era_struct = newEratosthenes();
    era_struct = doEratosthenesSieve(era_struct,N);


    fact_struct -> n_vector_multiplicities = realloc(fact_struct->n_vector_multiplicities,N*sizeof(int));
    fact_struct -> n_vector = realloc(fact_struct -> n_vector, N*sizeof(int));

    for(i=0; i<(era_struct->n); i++){
       
        k=N;
     
        if(k%era_struct -> prime_numbers[i]==0)
        {
            fact_struct -> n_vector[c] = era_struct -> prime_numbers[i];
            c++;
           
        }      
              
         
    }

    fact_struct -> n = c;

    for (i = 0; i < c; i++)
    {
        d=0;
        l=N;
        k=fact_struct->n_vector[i];
        while (l%k==0)
        {
            d=d+1;
            l=l/k;
        }

        fact_struct->n_vector_multiplicities[i]=d;
    }

    return fact_struct;

}


int recomposeInteger(Factorization* factorization){

    int i;
    double mult=1;
    for(i=0; i<factorization->n; i++){

        mult *= pow(factorization->n_vector[i],factorization->n_vector_multiplicities[i]); 


    }

return mult;

}

#endif