#include <stdio.h>
#include <stdlib.h>

// A POWER OF A NUMBER

double powN(double x, int n){
    double prod = 1;
    int j=0;
    if (n==0 && x != 0 ){
       return 1;
    }
    else if (x==0 && n>0){
        return 0;
    }
    else if (n>0 && x != 0){
            for (j=1; j<=n; j+=1){
                prod*=x;
            }
            return prod;
    }
    else if (n<0 && x!=0){
            for (j=1; j<=abs(n); j+=1){
                prod*=1./x;
            }
            return prod;
    }
    else {
            return 0.0/0.0;
    }
}

int main() {
    int n;
    double x;
    printf("Enter the base: x = ");
    scanf("%lf", &x);
    printf("Enter the power: n = ");
    scanf("%d", &n);
    printf("%f^%d = %f\n", x,n,powN(x,n));
}
