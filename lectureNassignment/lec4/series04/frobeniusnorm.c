#include <stdio.h>
#include <math.h>

double frobenius(double A[], int m,int n){

    int mn=m*n;

    //This variable sum will store the sum of all squared elements
    double sum=0;
    int i;

    //Take all elements of array, squared them, sum them recursively 
    for (i=0;i<mn;i++){
        sum=sum+A[i]*A[i];
    }

    //Take sqrt of sum
    double r =sqrt(sum);
    return r;

}

int main(){

    //Here we ask the user for the dimensions of the matrix array
    int m;
    int n;
    printf("\nPlease enter number of rows of matrix: ");
    scanf("%d",&m);
    printf("\nPlease enter number of columns of matrix: ");
    scanf("%d",&n);

    double A[n*m];

    int i;
    int row=1;
    int col=1;

    //We ask the user to enter elements of array but store it in a 
    //column vector of size m*n

    for (i=0;i<m*n;i++){

        //We ennter inputs columnwise, every time it counts m rows it
        //moves the column
        if(row==m+1){
            row=1;
            col=col+1;
        }

        printf("\nPlease enter column %d row %d of matrix: ",col,row);
        scanf("%lf",&A[i]);
        row=row+1;
    }

    double result=frobenius(A,m,n);
    printf("\nThe frobenius norms is : %f\n",result);
}