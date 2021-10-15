#include <stdio.h>
#include <stdlib.h> 

void selectionsort(double* x, int n){
    
    int i;
    int j;
    for (i=0;i<n;i++)
    {
        for (j=i+1; j < n ; j++)
        {
            double elem_1 = x[i];
            double elem_2 = x[j];
            
            if (elem_2 < elem_1)
            {
                x[i] = elem_2;
                x[j] = elem_1;
            }
        }
    }


}

int main()
{

    int n = 10;
    double* x;
    
    x = (double*)malloc(n*sizeof(double));
    x[0]=-2, x[1]=10, x[2]=8, x[3]=3, x[4]=5, x[5]=-1, x[6]=4, x[7]=0, x[8]=1, x[9]=15;

    printf("\n The array is [%.f %.f %.f %.f %.f %.f %.f %.f %.f %.f]",x[0], x[1], x[2], x[3], x[4], x[5], x[6], x[7], x[8], x[9]);

    selectionsort(x,n);

    printf("\n The sorted array is [%.f %.f %.f %.f %.f %.f %.f %.f %.f %.f]\n", x[0], x[1], x[2], x[3], x[4], x[5], x[6], x[7], x[8], x[9]);

    free(x);

}