#include <stdio.h>

int main() {
    double x,y,z;
    
    printf("Enter x: ");
    scanf("%lf",&x);
    
    printf("Enter y: ");
    scanf("%lf",&y);

    printf("Enter z: ");
    scanf("%lf",&z);

    if (x>y) {
        if (y>z)
        {
            printf("The order is %f, %f, %f\n",x,y,z);
        }
        else{
            if (z>x)
            {
                printf("The order is %f, %f, %f\n",z,x,y);
            }
            else {
                printf("The order is %f, %f, %f\n",x,z,y);
            }
            
        }
        
    }
    else if (y > x)
    {
        if (x>z)
        {
            printf("The order is %f, %f, %f\n",y,x,z);
        }
        else {
            if (z>y)
            {
                printf("The order is %f, %f, %f\n",z,y,x);
            }
            else {
                printf("The order is %f, %f, %f\n",y,z,x);
            }
            
        }
        
    }
    else {/*equality*/
        printf("The order is %f, %f, %f\n",x,y,z);
    }
    


    return 0;
}