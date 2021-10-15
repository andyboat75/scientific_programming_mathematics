#include <stdio.h>

double findMax(double x[], int n){

    int i;
    double max = x[0];

    for(i=0; i<n; i++){

        if(max<x[i])
            max = x[i];

    }

    return max;


}
double maxCompare(double a[], double b[], int n){

    int i, n_repeats=0;
    double max_a, max_b, max;

    //First, find 
    max_a = findMax(a,n);
    max_b = findMax(b,n);

    //If they don't have the same maximum, function returns 0
    if(max_a != max_b)
        return 0;

    //Otherwise, take one of them and call it max
    max = max_a;

    for(i=0; i<n; i++){

        if(a[i]==max && b[i] == max)

            //Number of repeats such that their indices and maximums are the same
            n_repeats += 1;

    }

    return n_repeats;
}

int main(){
    const int n=8;
    int max_in_same_ij, i;
    double a[n], b[n];    

    printf("Enter values for a:\n");
    for (i=0; i<n; i++){
        scanf("%lf",&a[i]);
    }

    printf("Enter values for b:\n");
    for (i=0; i<n; i++){
        scanf("%lf",&b[i]);
    }

    max_in_same_ij = maxCompare(a,b,n);

    //If they don't share the same maximum, the function returns 0
    if(max_in_same_ij == 0){
        printf("Nope");
        return 0;
    }

    printf("Result = %d\n", max_in_same_ij);

    return 0;       



}