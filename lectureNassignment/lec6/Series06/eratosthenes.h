#ifndef eratosthenes
#define eratosthenes


//Define structure Eratosthens
    struct _Eratosthenes_ {

        int nmax;
        int n;
        int* prime_numbers;

    };
    typedef struct _Eratosthenes_ Eratosthenes;

//Define allocation functions

    Eratosthenes* newEratosthenes() {
        
        Eratosthenes* X = NULL;

        

        X = malloc(sizeof(Eratosthenes));
        assert(X != NULL);

        X->nmax = 0;
        X->n = 0;
        
        X->prime_numbers = malloc(1*sizeof(double));
        
        
        return X;
    }

    
    



Eratosthenes* doEratosthenesSieve(Eratosthenes* Era,int nmax){
    
    int num;
    int i,j;
    int n=0;
   
    Era->nmax = nmax;

    int prime[nmax+1];
    for (i=0;i<=nmax;i++){
        prime[i]=1;
    }

        for (num=2; num<=nmax; num++) { 
            // If prime[p] is not changed, then it is a prime 
            
            if (prime[num] == 1){  
                //We mark as false all multiples of p
                for (i=num+num; i<=nmax; i = i + num){
                    prime[i] = 0; 
                } 
            }
        }    

        
    Era->prime_numbers = realloc(Era->prime_numbers,(nmax)*sizeof(int));
    for(i=0;i<nmax;i++){
        Era->prime_numbers[i]=0;
    }


    for (i=2;i<nmax;i++){
       
        if (prime[i]==1){
            
            Era->prime_numbers[n]=i;
            n++;
        }
    }
    Era->n = n;

    return Era;
}

#endif