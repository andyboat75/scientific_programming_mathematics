#include <stdio.h>
#include <math.h>


double partialSumRecursive(int n) {
    if (n == 0){return 4;}
    else {
        return (double) (4*pow(-1,n))/(double)(2*n + 1) + partialSumRecursive(n-1);
    }
}

double partialSumLoop(int n) {
    double sn=0;
    int k = 0;
    for (k=0; k<=n; k++) {
        sn += (4*pow(-1,k))/(double)((2*k) + 1);
    }
    return sn;

}

void main() {
    int n=0;
    printf("Enter n: ");
    scanf("%d",&n);
    //validation of input
    if (n<0) {
        printf("please enter a non-negative number");
    }
    else {
    printf("The recursive partial sum result is %f\n",partialSumRecursive(n));
    printf("The loop partial sum is %f\n",partialSumLoop(n));
    }
}