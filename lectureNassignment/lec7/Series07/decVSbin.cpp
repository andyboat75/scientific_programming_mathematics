#include <iostream>
#include <string>
#include <cstdio>
using std::cout;
using std::string;
using std::cin;
using std::endl;

string dec2bin(int n){
    
    //Create empty string
    string str = "";
    int k = n;
    int c;

    while(k!=0){

        //Divide number by 2 and take the residue.
        c = k % 2;

        //If residue is 0, add 0 in front of string, else 
        //add 1 in front
        if (c == 0){
            str = '0' + str;
        } else {
            str = '1' + str;
        }

        //Substract residue and divide by 2
        k = (k-c)/2;
    }

    return str;

}

int bin2dec(string str){
    int i = str.length();
    int j;
    int c = 0;
    int k;
    int sum;
    int result = 0;
    for (j = 0 ;j < i; j++){
        
        //We take the element of the string backwards
        if (str.at(i-j-1) == '1' ){
            
            //This is the exponent of the power of 2
            k = c;


            //We create our power function, since pow is of type double
            if(k == 0){
                sum = 1;
            } else {
                sum = 1;
                for(k = 1; k < c+1 ; k++){
                    sum = sum * 2;
                }
            }

            
        } else {
            sum=0;
        }
        result=result+sum;

        //c updates the exponent of the power function
        c++;
    }

    return result;
}

int main(){
    int n;
    cout << "Please enter value: ";
    cin >> n;    
    string str=dec2bin(n);
    int k = bin2dec(str);
    cout << "Binary representation: " << str << endl;
    cout << "Decimal representation: "<< k << endl;
    
    return 0;
}