#include <stdio.h>

int fibonacci(int k);

void main() {
    int k =0;
    printf("Enter k: ");
    scanf("%d", &k);
    int xk = fibonacci(k);
    if (xk < 0 ) { 
        printf("Please enter a non negative number\n");
    }
    else {
        printf("x%d = %d\n", k, xk);
    }
}

int fibonacci(int k) {
    // Validation
    if (k < 0){
        // printf("Please enter a non-negative number\n");
        return -1;
    }
    else if (k == 0 || k == 1){
        // printf("x%d = %d\n",k,k);
        return k;
    }

    // main calculation
    int x0 = 0, x1 = 1;
    int nextTerm;
    for (int i = 2; i<=k; i++) {
        nextTerm = x0 + x1;
        x0 = x1;
        x1 = nextTerm;
    }
    return nextTerm;

}