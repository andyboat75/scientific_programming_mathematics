#include <stdio.h>


void main()
{
    int r, coeffValue = 1, space, i, j;
 
    printf("Enter a number, n: ");
    scanf("%d",&r);
 
    for(i=0; i<r; i++)            // outer loop for displaying row
    {
        for(space=1; space <= r-i; space++)  // space for every row starting
            printf("  ");
 
        for(j=0; j <= i; j++)     // inner loop for displaying the pascal triangle of numbers
        {
            if (j==0 || i==0)     // either outer loop value or inner-loop value is "0 " it prints 1
                coeffValue = 1;
            else
                coeffValue = coeffValue*(i-j+1)/j;  //calculate the coefficient
 
            printf("%4d", coeffValue);
        }
        printf("\n");
    }
}