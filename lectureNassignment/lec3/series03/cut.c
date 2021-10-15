#include <stdio.h>
int dim = 0;



//===========cut(x,n) function
void cut(int x[], int n){
    int i = 0;
    int c = 0; //
    while(i < dim){
        if (x[i] >= n){
            c++;
        }
        else {
            printf("%d ", x[i]);
        }
        i++;
    }
    if (c == 0){
        printf("The sequence does not change.");
    }
    else if (c == dim){
        printf("The shortened sequence is empty.");
    }
    printf("\n");
}


//===================Scan the vector entered ===========
void scanVector(int input[], int dim) {
    int j = 0;
    for (j=0; j<dim; j++) {
        input[j] =0;
        printf("%d: ",j+1);
        scanf("%d",&input[j]);
    }
    printf("\n");
}


//=========main function===========================
int main() {
    int n;
    //bound
    printf("Enter the bound, n: \n");
    scanf("%d", &n);
    //dimension of vector(sequence)
    printf("Enter the dimension of the vector: \n");
    scanf("%d", &dim);
    //initialize vector
    int x[dim];
    //scan vector
    scanVector(x,dim);
    // call cut function
    cut(x, n);
}
