#include <stdio.h>

int main() {
    double x;
    double y;
    int n;

    printf("Enter the x amount of won: ");
    scanf("%lf",&x);

    
    printf("\nEnter the n number of friends: ");
    scanf("%d",&n);
    n += 1; /*yourself is included*/
    
    if ((x > 0) && (n>0)) {
        y = x/n;

        printf("Each friend and I had: %f\n",y);
        return 0;
    }
    else{
        printf("Enter a +ve amount\n");
    }
}