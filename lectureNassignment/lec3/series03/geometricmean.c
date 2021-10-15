#include <stdio.h>
#include <math.h>
#define DIM 6 // set the vector dimension in the main program to 5

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
            printf("Enter only nonnegative numbers");
    }
    else {
            gm = pow(prod, 1.0/n);
            printf("Geometric Mean: %f\n",gm);
    }

}



void scanVector(double input[], int dim) {
    int j = 0;
    printf("Enter the vector\n");
    for (j=0; j<dim; j++) {
        input[j] =0;
        printf("%d: ",j+1);
        scanf("%lf",&input[j]);
    }
    printf("\n");
}


int main() {
    int j;
    double x[DIM];
    scanVector(x, DIM);
    geometricmean(x,DIM);
}
