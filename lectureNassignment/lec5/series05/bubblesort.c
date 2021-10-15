#include <stdio.h>
#include <stdlib.h>

void bubblesort(double* x, int n)
{
    int i;
    int j;

    double aux;

    for(i=0;i<n-1;i++)
    {
     
        for (j=0;j<n-i-1;j++)
        {    
            if ( x[j] > x[j+1]){
                aux = x[j];
                x[j] = x[j+1];
                x[j+1] = aux;
            }
        }
       
    }    

}




int main()
{

    int n;
    n=10;

    double* x;

    x=(double*)malloc(n*sizeof(double));
    
    x[0]=-2, x[1]=10, x[2]=8, x[3]=3, x[4]=5, x[5]=-1, x[6]=4, x[7]=0, x[8]=1, x[9]=15;

    printf("\n The array is: \n");
    
    int i;

    printf("[ ");
    for (i = 0; i < n; i++)
    {
        printf("%.f ",x[i]);
    }
    printf("]\n");

    bubblesort(x,n);

    printf("\n The sorted array is: \n");

    printf("[ ");
    for (i=0;i<n;i++)
    {
        printf("%.f ",x[i]);
    }
    printf("]\n");

    free(x);
}

// time complixity n^2.