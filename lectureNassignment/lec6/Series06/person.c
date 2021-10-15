#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "datum.h"
#include "person.h"

int main(){

 Person* Eric;
 Person* Maxwell;
 Person* older;

 Eric=newPerson();
 Maxwell=newPerson();


 //For Daniel

    setPersonFirstname(Eric,"Eric");
    setPersonLastname(Eric, "Asamoah");
    setAddressCity(Eric->address,"Wein");
    setAddressStreet(Eric->address,"Erdbergstrass");
    setAddressNumber(Eric->address,"401B");
    setAddressZip(Eric->address,"1110");
    setDateYear(Eric->birthday,1995);
    setDateMonth(Eric->birthday,02);
    setDateDay(Eric->birthday,07);

    printf("\nName: %s\n",Eric->firstname);
    printf("\nLast Name: %s\n",Eric->lastname);
    printf("\nBirthday: %d/%d/%d\n",Eric->birthday->day,Eric->birthday->month,Eric->birthday->year);
    printf("\nCity: %s\n",Eric->address->city);
    printf("\nZip: %s\n",Eric->address->zip);
    printf("\nStreet: %s\n",Eric->address->street);
    printf("\nNumber: %s\n",Eric->address->number);

    printf("\n\n\n\n\n");

//For Daniela

    setPersonFirstname(Maxwell,"Maxwell");
    setPersonLastname(Maxwell, "Asamoah");
    setAddressCity(Maxwell->address,"Accra");
    setAddressStreet(Maxwell->address,"Madina");
    setAddressNumber(Maxwell->address,"M35");
    setAddressZip(Maxwell->address," ");
    setDateYear(Maxwell->birthday,1986);
    setDateMonth(Maxwell->birthday,05);
    setDateDay(Maxwell->birthday,22);

    printf("\nName: %s\n",Maxwell->firstname);
    printf("\nLast Name: %s\n",Maxwell->lastname);
    printf("\nBirthday: %d/%d/%d\n",Maxwell->birthday->day,Maxwell->birthday->month,Maxwell->birthday->year);
    printf("\nCity: %s\n",Maxwell->address->city);
    printf("\nZip: %s\n",Maxwell->address->zip);
    printf("\nStreet: %s\n",Maxwell->address->street);
    printf("\nNumber: %s\n",Maxwell->address->number);

older=whoisoldeer(Eric,Maxwell);

if (older!=NULL){
printf("\nThe older person is: %s\n",older->firstname);}
else{printf("Both have the same age");}



}