#include <stdio.h>

double absolute(double x) {
    if (x<0){
        x = -x;
    }
    return x;
}

double minabs(double x, double y) {
    // x = absolute(x);
    // y = absolute(y);
    printf("%f\n",x);
    printf("%f\n",y);
    if (absolute(x)<absolute(y)) {
        return x;
    }
    else {
        return y;
    }
}

int main() {
    double x, y;
    printf("Enter x = ");
    scanf("%lf", &x);
    printf("Enter y = ");
    scanf("%lf", &y);
    printf("The absolute minimum of %f and %f is %f\n", x,y,minabs(x,y));
}