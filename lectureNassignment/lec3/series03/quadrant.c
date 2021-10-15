#include <stdio.h>
/*----------------------------------------------------------------
there are I II III & IV quadrants in R^2. I --> (+,+), II--> (-,+), III --> (-,-), IV --> (+,-)

*/
void Quadrant(double x, double y){
    if (x>0 && y>0) {
        printf("The point (%lf,%lf) lies in the first quadrant\n", x, y);
    }
    else if (x>0 && y<0) {
        printf("The point (%lf,%lf) lies in the fourth quadrant\n", x, y);
    }
    else if (x<0 && y>0) {
        printf("The point (%lf,%lf) lies in the second quadrant\n", x, y);
    }
    else if (x<0 && y<0){
        printf("The point (%lf,%lf) lies in the third quadrant\n", x, y);
    }
    else if (x==0){
        printf("The point (%lf,%lf) lies on the y-axis\n", x, y);
    }
    else if (y==0){
        printf("The point (%lf,%lf) lies in the x-axis\n", x, y);
    }
    else if (x==0 && y==0) {
        printf("The point (%lf,%lf) is at the origin\n", x, y);
    }

}

void main() {
    double x, y;

    printf("Enter the x-value: ");
    scanf("%lf",&x);

    printf("Enter the y-value: ");
    scanf("%lf",&y);

    Quadrant(x,y);
}