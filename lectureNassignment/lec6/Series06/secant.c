#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

// create a function
double f(double x){
    return -4*x*x + 12*x -9;
}

double secant(double (*f)(double), double x0, double x1, double tau) {

    double xPlusOne, tau2;
//    double y0  = x0;
//    double y1 = x1;

    int a = 0;  int b = 0;

    while (a == 0 && b==0) {
        //compute new value
        xPlusOne = x1 - f(x1)*((x0-x1)/(f(x0)-f(x1)));

        //swapping
        x0 = x1;
        x1 = xPlusOne;

        //check the stopping criteria set in the question
        if (fabs(f(x1) - f(x0)) <= tau) {
            a = 1;
        }

        if (fabs(x1) <= tau) {
            tau2 = tau;
        }
        else {
            tau2 = tau * fabs((x1));
        }
        if (fabs(f(x1)) <= tau && fabs(x1-x0) <= tau2){
            b = 1;
        }
        if (a) { printf("Result may be wrong\n");}
    }
    return x1;
}

int main() {
    //declare vars
    double x0, x1, tau, x, F;
    double (*func)(double);

    // Read variables form keyboard
    printf("Enter value of x0: ");
    scanf("%lf",&x0);

    printf("Enter value of x1: ");
    scanf("%lf",&x1);

    printf("Enter value of tau: ");
    scanf("%lf",&tau);

    //some necessary conditions
    assert(tau >0 && x0!=x1);

    func = &f;

    x = secant(func, x0, x1, tau);
    F = func(x);

    printf("x: %f and f(x): %f \n", x, F);
    return 0;
}