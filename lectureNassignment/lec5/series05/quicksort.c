#include<stdlib.h>
#include<stdio.h>

void quicksort (double *x, int n) {
    if (n < 2)
        return;
    double p = x[n / 2];
    double *l = x;
    double *r = x + n - 1;
    
    while (l <= r) 
    {
        if (*l < p)
        {
            l++;
        }
        else if (*r > p) {
            r--;
        }
        else 
        {
           double t = *l;
            *l = *r;
            *r = t;
            l++;
            r--;
        }
    }
    
    quicksort(x, r - x + 1);
    quicksort(l, x + n - l);
}

int main () 
{
    int i;
    int n;

    printf("Enter length n: ");
    scanf("%d",&n);

    double  x[n];
    printf("Enter vector\n");

    for (i=0; i<n ;i++)
    {
        printf("%d: ",i);
        scanf("%lf",&x[i]);
    }

    quicksort(x, n);
   
    printf("After quicksort\n");
    for(i=0;i<n;i++)
    {
        printf("%d: %.lf \n",i,x[i]);
    }
}
