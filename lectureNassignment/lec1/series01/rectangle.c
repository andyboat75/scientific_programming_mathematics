#include <stdio.h>

int main() {
    /*Declare a & b as double data type */
    double a, b;
    printf("Enter length: ");
    /* Accepted input and assign it to a*/
    scanf("%lf",&a);
    printf("\nEnter width: ");
    scanf("%lf",&b);
    /*if - else statement*/
    if (!((a<0)|| (b<0))) /*not(a is less than 0 OR b is less than 0)*/
    {
        /* Declaration and initialisation*/
        double area = a * b;
        /* Printed output */
        printf("Length %f cm sq. \n",area);

        /* I have to find out how to use assert to make sure entered values are positive */

        return 0;
    }
    else {
        printf("Length can't be -ve. Enter +ve integer\n");
    }
}