#include <stdio.h>
#include <stdlib.h> 

void insertionsort(double* x, int n)
{

    int i;

    double* y;

    y=(double*)malloc(1*sizeof(double)); //sorted vector

    y[0]=x[0];

    int m;

    
    for(i=1;i<n;i++)
    {
        
        m=i+1;
        y=(double*)realloc(y,m*sizeof(double));

        int j=i-1;

        while (x[i]<y[j] && j>=0)
        {
            y[j+1]=y[j];

            j=j-1;   
        }
        y[j+1]=x[i];   
    }

    for (i=0;i<n;i++)
    {
        x[i]=y[i];
    }

    free(y);
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
    for (i=0;i<n;i++)
    {
        printf("%.f ",x[i]);
    }
    printf("]\n");

    insertionsort(x,n);

    printf("\n The sorted array is: \n");

    printf("[ ");
    for (i=0;i<n;i++)
    {
        printf("%.f ",x[i]);
    }
    printf("]\n");

    free(x);
}