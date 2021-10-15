#include <stdio.h>
#include <stdlib.h>

// A POWER OF A NUMBER

double powN(double x, int n){

    if (n==0 && x != 0 ){
       return 1;
    }
    else if (n>0 && x==0){
        return 0;
    }
    else if (n==1) {
        return x;
    }
    else if (n>0 && x != 0){
            return x*powN(x,n-1);
    }
    else if (n<0 && x!=0){
            return 1.0/(x*powN(x,abs(n)-1));
    }
    else {
            return 0.0/0.0;
    }
}
// main program
int main() {
    int n;
    double x;
    printf("Enter the base: x = \n");
    scanf("%lf", &x);
    printf("Enter the power: n = \n");
    scanf("%d", &n);
    printf("%f^%d = %f", x,n,powN(x,n));
}
