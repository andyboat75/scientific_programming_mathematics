#include <stdio.h>

int main() {
    double r=0, pi=3.14159265;

    printf("Enter the radius of the circle: ");
    scanf("%lf",&r);

    if (r>0)
    {
        printf("The area of the circle with radius %f is %f \nAnd\n", r, pi*(r*r));
        printf("The perimeter is %f\n",2*pi*r);
    }

    else
    {
        printf("Enter a positive radius\n");
    }
    


    return 0;
}