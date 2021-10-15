#include<stdio.h>

void pythagoras(int n)
{
    int i, j;
    int k = 1;
    while (k <= n)
    {

        for(i = 0; i<k; i++)
            for(j=1; j<k; j++)
            {
                if (i*i +j*j == k*k && i<j)
                {
                    printf("The Pythagoras triple (%d, %d, %d)\n", i, j, k);
                }
                else continue;
        }
        k = k + 1;
    }
}

int main()
{
    int n;
    printf("Enter the natural number n: ");
    scanf("%d", &n);
    pythagoras(n);
}