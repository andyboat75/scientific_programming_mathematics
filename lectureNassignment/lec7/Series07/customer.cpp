#include "customer.hpp"

int main(){
    Customer person;
    person.setName("Maxwell Asamoah");
    person.setBalance(300000000);
    person.setPIN(2021);
    cout<<"Name: "<<person.getName()<<endl;
    cout<<"Balance: "<<person.getBalance()<<" EUR"<<endl;
    person.drawMoney(200000);
}