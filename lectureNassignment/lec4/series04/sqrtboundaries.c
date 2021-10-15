#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


double Root(double x){

    double y=x/2;
    double aux;
    

    while (abs(y*y-x)>0.01){
        aux=(y+x/(y))/2;
        y=aux;
    }
    
    return y;


}

int sqrtBoundaries(double x){

    assert(x>=0);

    double y=Root(x);
    
    int k=-1;

    while(k>y || y>=k+1){
        k=k+1;
    }

    return k;

}

int main(){

    double x;
    printf("\nPlease enter a positive number: \n");
    scanf("%lf",&x);

    int r;
    r=sqrtBoundaries(x);

    printf("The Unique N is : %d\n",r);
}