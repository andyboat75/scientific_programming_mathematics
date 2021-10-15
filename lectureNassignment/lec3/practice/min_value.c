#include <stdio.h>
#define DIM 5

void scanVector(double input[], int dim) {
    int j = 0;
    for (j=0; j<dim; j++) {
        input[j] =0;
        printf("%d: ",j);
        scanf("%lf",&input[j]);
    }
}

double min(double input[], int dim) {
    int j = 0;
    double minval = input[0];
    for (j=0; j<dim; j++) {
        if (input[j] < minval){
            minval = input[j];
        }
    }
    return minval;
}




void main() {
    double x[DIM];
    scanVector(x, DIM);
    printf("Minimum of the vector: %f \n", min(x,DIM));
}