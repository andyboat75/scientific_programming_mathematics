#include <iostream>
#include <string>
#include <cstdio>
#include <cassert>
using std::cout;
using std::string;
using std::cin;
using std::endl;

//Define Class

class Customer {
    private:
        string name;
        double balance;
        int PIN;
        
    public:
        void setName(string);
        void setPIN(int);
        void setBalance(int);
        string getName();
        int getPIN();
        int getBalance();
        void printBalance();
        bool checkPIN();
        void drawMoney(double);


};

void Customer::setName(string Name) {
    name=Name;
}

void Customer::setPIN(int pin) {
   PIN=pin;
}

void Customer::setBalance(int Balance) {
   balance=Balance;
}

string Customer::getName(){
    return name;
}

int Customer::getPIN(){
    return PIN;
}

int Customer::getBalance(){
    return balance;
}

void Customer::printBalance(){
    cout<<"Balance: "<<getBalance()<<endl;
}

bool Customer::checkPIN(){
    int x;
    cout<<"Please enter PIN code: "<<endl;
    cin>>x;
    if (x==PIN){
        return 1;
    } else {
        return 0;
    }
}

void Customer::drawMoney(double x){
    assert(getBalance()>=x);
    bool a=checkPIN();
    if (a){
        cout<<"PIN is correct"<<endl;
        setBalance(getBalance()-x);
        cout<<"Withdraw succesful: -"<<x<<" EUR"<<endl;
        printBalance();
    } else {
        cout<<"PIN is NOT correct"<<endl;
    }
    
    if (getBalance()<10){
        cout<<"Warning:balance is less than 10 EUR"<<endl;
    }
}