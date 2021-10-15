#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//This functions calculates the cubic root of a number with a given precision
double cubeRoot(double x, double prec){

    //Here a give an initial estimate for the cubic root
    double y=1;
    double aux;
    
    //while the value of the root is less than the given precision it 
    //provides a new estimate by recursion
    while (abs(y*y*y-x)>(prec)){

        //We use Newthon's Method to estimate the cubic root.
        aux=(2*y+x/(y*y))/3;
        y=aux;
    }
    
    return y;


}

int main(){

    double x;
    double prec;
    
    //We asked the user for inputs, value to calculate root for and
    //desired precision
    printf("\nPlease enter value to calculate: ");
    scanf("%lf",&x);
    printf("\nPlease enter precision: ");
    scanf("%lf",&prec);

    //Call the cuberoot function
    double y=cubeRoot(x,prec);

    //Calculate error using built-in function
    double z;
    z=cbrt(x);

    //Calculate and print error
    double error=y-z;
    printf("\nThe result is %.3f the error is %.3f\n",y,error);
    return 0;

}