#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<math.h>


int* dec2bin(int N, int* n)
{
    int j;
    int* array = NULL;
    int length;

    for (j=0; pow(2, j) < N; j++)
    {
        length = 0 + j;
        n = &length;
    }
    
    assert(*n  > 0);
    array = malloc((*n)*sizeof(int));
    assert(array != NULL);
    
    for (j = 0; j < *n+1; j++)
    {
        
        if (N<2)
        {
            array[j] = 1;
            
        }
        else if (N%2 != 0) 
        {
            array[j] = 1;
            
        }
        else 
        {
            array[j] = 0;
            
        }
        
        N = N/2;
    }

    for (j = *n; -1 < j ; --j)
    {
        printf("%d", array[j]);
    }
    printf("\n");
    
}

int main()
{
    int N;
    printf("Enter a number N: ");
    scanf("%d", &N);
    
    *dec2bin(N, &N);    
}