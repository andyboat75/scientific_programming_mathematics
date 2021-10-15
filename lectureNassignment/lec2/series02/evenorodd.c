#include <stdio.h>
#include <stdlib.h>

int EvenOrOdd(int n){

    // Check even
    if (n%2==0)
    {
        return 1;
    }
    // odd
    else {
        return 0;
    }
    
}




void main() {
    //declare
    int n;

    // Accept input
    printf("Enter an integer, n: ");
    scanf("%d", &n);

    //call EvenOrOdd function
    int even_or_odd = EvenOrOdd(n);

    // print output
    if (even_or_odd){
        printf("%d is an even number\n", n);
    }
    else {
        printf("%d is an odd number\n", n);
    }

}

