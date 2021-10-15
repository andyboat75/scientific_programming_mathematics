#include <stdio.h>
#include <stdlib.h>

void Fibonacci(int n) {
    int x0 = 0, x1 = 1, nextTerm = 0;
    
    // displays the first two terms which is always 0 and 1
    printf("Fibonacci Series: %d, %d, ", x0, x1);
    nextTerm = x0 + x1;

    while (nextTerm <= n) {
        printf("%d, ", nextTerm);
        x0 = x1;
        x1 = nextTerm;
        nextTerm = x0 + x1;
    }

}

 void main() {
    int n;
    printf("Enter a positive number: ");
    scanf("%d", &n);
    Fibonacci(n);
    
}



