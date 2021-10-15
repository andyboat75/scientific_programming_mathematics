#include <stdio.h>
// A PROGRAM THAT CREATES A NEW SEQUENCE FROM A GIVEN SEQUENCE WITH A SPECIFIED BOUND n

// a void function with a dynamic vector of length s.
void cut(int x[], int n, int s){
    int j = 0;
    int count = 0; //
    for (j=0; j<s; j++){
        if (x[j] < n){
                printf("%d \n",x[j]);
        }
        else {
            count+=1;
        }
    }
    if (count == s) printf("Empty \n");
}

int main() {
    int n;
    int s;
    int j;
    printf("Enter the bound, n: \n");
    scanf("%d", &n);
    printf("Enter the size of the vector: \n");
    scanf("%d", &s);
    int x[s];
    printf("Enter the elements of the vector, press enter after each element: \n");
    for (j=0; j<s; j+=1) {
            scanf("%d", &x[j]);
    }
    printf("New sequence y: \n");
    cut(x,n,s);

    }
