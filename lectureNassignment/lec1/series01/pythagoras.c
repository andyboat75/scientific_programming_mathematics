#include<stdio.h>

int main(){
    int a, b, c; /*natural numbers*/
    
    printf("Enter length a: ");
    scanf("%d",&a);

    printf("Enter length b: ");
    scanf("%d",&b);

    printf("Enter length c: ");
    scanf("%d",&c);

    if ( a>0 && b>0 && c>0){
        if (a*a + b*b == c*c || a*a + c*c == b*b || b*b + c*c == a*a){
            printf("The three numbers are Pythagorean triple. \n");
        }
        else {
            printf("The three numbers are not Pythagorean triple. \n");
            }
    }else{
        printf("The length must be a positive natural number. \n");
        }
    return 0;
    
}