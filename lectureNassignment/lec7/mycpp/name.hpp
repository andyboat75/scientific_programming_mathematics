#include <iostream>
#include <string>
#include <cstdio>
using std::cout;
using std::string;
using std::cin;
using std::endl;

class Name {
    private:
        string first_name;
        string surname;
                
    public:
        void setFullName(string);
        void printName();

};

void Name::setFullName(string str){
    int i=str.length();

    //We extract the surname, starting from behind and 
    //stoping in the first space
    int a=0;
    while(str.at(i-1)!=' '){
        a++;
        i--;
    }
    surname=str.substr (i,a);

    //We extract the first name,stoping in the first space
    int j=0;
    while(str.at(j)!=' '){
        j++;
        
    }
    first_name=str.substr (0,j);

    //We check if character is space
    //Substract said space, add next letter and "."
    int k;
    for (k=j;k<i-1;k++){
        if (str.at(k)==' '){
            first_name=first_name+str.substr(k,2)+".";
        }
    }
}


void Name::printName(){
    cout<<"Name: "<<first_name+" "+surname<<endl;
}