#include <stdio.h>

int main() {
    int a=2, b=3;
    /*int/int = int*/
    double dbl1 = a/b;
    /*double (int/int=int)*/
    double dbl2 = (double) (a/b);
    /*double/int = double*/
    double dbl3 = (double) a/b;
    /*int/double = double*/
    double dbl4 = a/(double) b;
    int int1 = 2;
    int int2 = 3;

    printf("a) %f\n",dbl1);
    printf("b) %f\n",dbl2);

    printf("c) %f\n",dbl3);
    printf("d) %f\n",dbl4);
}