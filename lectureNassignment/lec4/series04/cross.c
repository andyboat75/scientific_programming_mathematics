#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


void cross(int n){
    /*Honestly, this code is not efficient at all but all other means 
    are not fruitful. Try to better it later.*/
    
    //validate input parameter
    assert(0<n && n<10);
    

    //length of the array
    int length = 2*n-1;
    int i, j;
    // loop through rows
    for (i=1; i<n+1; i++){
        // loop through columns
        for (j=1; j<length+1; j++){
            if (j==i || j==length-i+1){
                printf(" %d ",i);
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }

    for (i=n+1; i<length+1; i++){
        for (j=1; j<length+1; j++){
            if (j==i || j==length-i+1){
                printf(" %d", length-i+1);
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
}



void main() {
    int n;
    printf("Enter a number between 0 and 9: ");
    scanf("%d",&n);
    cross(n);
}