#include <stdio.h>
#include <math.h>
#define DIM 5 // set the vector dimension in the main program to 5

// GEOMETRIC MEAN CALCULATOR

 void geometricmean(double x[], int n){
    int j = 0;
    double prod = 1;
    double gm;
    int count = 0;

    for (j=0; j<n; j++){
         if (x[j]<0) {
                count+=1;
         }
         else{
                prod*=x[j];
         }
    }
    if (count > 0) {
            printf("Only nonnegative real numbers are allowed!");
    }
    else {
            gm = pow(prod, 1.0/n);
            printf("Geometric Mean: %f",gm);
    }

}

int main() {
    int j;
    double x[DIM];
    printf("Enter the elements of the vector, press enter after each element: \n");
    for (j=0; j<DIM; j+=1) {
            scanf("%lf", &x[j]);
    }
    geometricmean(x,DIM);
}
