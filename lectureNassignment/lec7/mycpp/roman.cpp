#include <iostream>
#include <string>
#include <cstdio>
#include <cassert>
using std::cout;
using std::string;
using std::cin;
using std::endl;

//Here I define the Character corresponding to those roman numbers with unique symbol
string getRoman(int n){
    if (n==0){
        return "";
    }
    if (n==1){
        return "I";
    }

    if (n==4){
        return "IV";
    }

    if (n==5){
        return "V";
    }

    if (n==9){
        return "IX";
    }

    if (n==10){
        return "X";
    }

    if (n==40){
        return "XL";
    }

    if (n==50){
        return "L";
    }

    if (n==90){
        return "XC";
    }

    if (n==100){
        return "C";
    }

    if (n==400){
        return "CD";
    }

    if (n==500){
        return "D";
    }

    if (n==900){
        return "CM";
    }

    if (n==1000){
        return "M";
    }
}

//Here I create strings to represent units, tens, hundreds and thousands of given numbers
//It takes a number between 1 and 9 and a factor between 1 and 1000 to create any string
//Example, 87 has 7 units and 8 tens
//Function will take 7 and 1 as factor for units, and return VII
//For 80, function will take 8 tens and factor 10 and return LXXX
string constructor(int n,int f){
    int i;
    string str="";
    if(n==0){
        str="";
    }

    if(n==1){
        
        str=getRoman(n*f);
    }

    if(n==2){
        
        str=getRoman((n-1)*f)+getRoman((n-1)*f);
    }

    if(n==3){
        
        str=getRoman((n-2)*f)+getRoman((n-2)*f)+getRoman((n-2)*f);
    }


    if(n==4||n==5||n==9){
        
        str=getRoman(n*f);
    }

    if(n==6){
        
        str=getRoman((5)*f)+getRoman((n-5)*f);
    }

    if(n==7){
        
        str=getRoman((5)*f)+getRoman((n-1-5)*f)+getRoman((n-1-5)*f);
    }

    if(n==8){
        
        str=getRoman((5)*f)+getRoman((n-2-5)*f)+getRoman((n-2-5)*f)+getRoman((n-2-5)*f);
    }

    return str;


}

string int2roman(int n){

    int th,h,t,u;  // Thousands,hundreds,tens,units
	
	 u=n%10;
     t=(n/10)%10;
	 h=(n/100)%10;
	 th=n/1000;
     

     //For units

     return constructor(th,1000)+constructor(h,100)+constructor(t,10)+constructor(u,1);
}

// This function returns value of a Roman symbol 
int getInt(char r) 
{ 
    if (r == 'I') 
        return 1; 
    if (r == 'V') 
        return 5; 
    if (r == 'X') 
        return 10; 
    if (r == 'L') 
        return 50; 
    if (r == 'C') 
        return 100; 
    if (r == 'D') 
        return 500; 
    if (r == 'M') 
        return 1000; 
  
     
} 


int roman2int(string str) 
{ 
    // Stores resulr
    int res = 0; 
  
    // Traverse given input 
    for (int i=0; i<str.length(); i++) 
    { 
        // Getting value of symbol at ith position
        int s1 = getInt(str.at(i)); 
  
        if (i+1 < str.length()) 
        { 
            // Getting value of symbol at i+1 th position
            int s2 = getInt(str.at(i+1)); 
  
            // Comparing both values 
            if (s1 >= s2) 
            { 
                // Value of current symbol is greater 
                // or equal to the next symbol 
                res = res + s1; 
            } 
            else
            { 
                res = res + s2 - s1; 
                i++; // Value of current symbol is 
                     // less than the next symbol 
            } 
        } 
        else
        { 
            res = res + s1; 
            i++; 
        } 
    } 
    return res; 
}

int main(){
    int n;
    cout << "Please enter the number: ";
    cin >> n;

    string str=int2roman(n);
    
    cout<<"Roman: "<<str<<endl;
    cout<<"Number: "<<roman2int(str)<<endl;
    return 0;
}