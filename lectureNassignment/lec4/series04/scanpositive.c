#include <stdio.h>

double scanpositive(void){
    
    //We create a false condition
    double t=0;

    //While conditions its false, it asks user for valid input
    
    while(t<=0){

        printf("Please enter a positive number: ");
        scanf("%lf",&t);
        
    }

    return t;
    

}

int main(){

    double  r;
    r=scanpositive();
    printf("Your positive number is %.f\n",r);
    return 0;
}