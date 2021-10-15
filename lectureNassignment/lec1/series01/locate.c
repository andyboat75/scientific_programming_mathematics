#include <stdio.h>

int main() {
    double l,x,y;

    printf("Enter the length of the square: ");
    scanf("%lf", &l);
    if (l>0)
    {
        printf("Enter the x coord: ");
        scanf("%lf", &x);
        
        printf("Enter the y coord: ");
        scanf("%lf", &y);

        /*Condition of within square*/
        if ((0<x && x<l)&& (0<y && y<l))
        {
            printf("The point is strictly inside the square\n");
        }
        /*condition for pts on boundary */

        else if ((x == 0 || x==l) || (y == 0 || y==l))
        {
            printf("The point is on the boundary of the square\n");
        }
        else {
            printf("The point is outside the square\n");
        }
        
        
    }
    else {
        printf("Enter a +ve length\n");
    }
    
    return 0;
}