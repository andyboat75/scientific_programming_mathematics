#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "datum.h"

int main(){

    Date* date;
    int c=0;
    int d=0;
    int y=0;
    int m=0;

    //Here we test function to create date with incorrect data
    date=newDate(d,m,y);

    //Here we test the set mutator functions by asking user to input data
    while (c==0){

        printf("\nPlease enter day: ");
        scanf("%d",&d);
        printf("\nPlease enter month: ");
        scanf("%d",&m);
        printf("\nPlease enter year: ");
        scanf("%d",&y);

        setDateDay(date,d);
        setDateMonth(date,m);
        setDateYear(date,y);

        c=isMeaningful(date);

        if (c==0){
            printf("\n Date is not admissible.\n Please enter an admissible date.\n");
            //return 0;
        }
        if (c!=0){
            printf("\n Date is admissible.\n");
        }

    }
    
    //Here we test the get mutator functions by printing

    printf("\nThe date is %d/%d/%d\n",getDateDay(date),getDateMonth(date),getDateYear(date));


    //Here we test the deallocating function

    date=delDate(date);

    if (date==NULL){
        printf("\ndate was deleted\n");
    }
       
}