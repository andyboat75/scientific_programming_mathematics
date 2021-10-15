#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<math.h>

// Create function to be used for the secant method.
double f(double x)
{
    return x*x-1;
}

// Create derivative of function to use newton method.
double fprime(double x)
{
    double h = 0.00001;

    return (f(x+h)-f(x))/(h);
}

double newton(double (*f)(double), double (*fprime)(double), double x0, double tau)
{
    // Declare the root to be found.
    double y1, tau2, x;
    int a = 0; int b = 0;
    double y0 = x0;

    while (a == 0 && b == 0)
    {
        // Compute the secant method.
        y1 = y0 - f(y0)/fprime(y0);

        //Checks first terminating condition
        if (fabs(fprime(y1))<=tau)
        {
            a=1;
        }

        if (fabs(y1)<=tau)
        {
            tau2=tau;
        }
        else
        {
            tau2=tau*fabs(y1);
        }

        if (fabs(f(y1))<=tau && fabs(y1-y0)<=tau2)
        {
            b=1;
        }
        y0 = y1;
    }

    if (a)
    {
        printf("\n Result may be wrong \n");
    }
    return y1;
}


int main()
{
    // Declare variables
    double x0, x1, tau, x, F, Fprime;
    double (*fun)(double);
    double (*funprime)(double);

    // Initialize and read variables from keyboard.
    printf("Value for x0: ");
    scanf("%lf",&x0);

    printf("Value for tau: ");
    scanf("%lf",&tau);
    // Check if tau value satisfy the condition.
    assert(tau > 0);

    fun = &f;
    funprime = &fprime;

    x = newton(fun, funprime, x0, tau);
    F = fun(x);

    printf("x : %f and f(x) : %f \n", x, F);
}