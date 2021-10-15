#include <stdio.h>

void scanVector(double input[], int dim) {
    int j = 0;
    for (j=0; j<dim; j++) {
        input[j] =0;
        printf("%d: ",j);
        scanf("%lf",&input[j]);
    }
}

void printVector(double output[], int dim) {
    int j = 0;
    for (j=0; j<dim; j++) {
        printf("%f ",output[j]);
    }
    printf("\n");
}




void main() {
    double x[5];
    scanVector(x, 5);
    printVector(x, 5);
}