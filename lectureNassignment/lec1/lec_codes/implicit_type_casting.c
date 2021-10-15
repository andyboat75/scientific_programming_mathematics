#include <stdio.h>

int main() {
    double dbl1 = 2/3; /*int/int = int*/
    double dbl2 = 2/3.;/*int/double = double*/
    double dbl3 = 1E2; /*1 x 10^2*/
    int int1 = 2;
    int int2 = 3;

    printf("a) %f\n",dbl1);
    printf("b) %f\n",dbl2);

    printf("c) %f\n",dbl3 * int1/int2);
    printf("d) %f\n",dbl3 * (int1/int2));
}