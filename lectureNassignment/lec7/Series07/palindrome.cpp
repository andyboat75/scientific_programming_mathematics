#include <iostream>
#include <string>
#include <cstdio>
using std::cout;
using std::string;
using std::cin;
using std::endl;
bool isPalindrome(string str){
    int i=str.length();
    int j;
    for (j=0;j<i;j++){
        if (str.at(j)!=str.at(i-j-1)){
            return 0;
        }
    }

    return 1;

};

int main(){
    string str;
    cout<<"Please enter word: ";
    cin>>str;
    cout<<"Your word is: "<<str<<endl;
    bool a=isPalindrome(str);
    if(a){
        cout<<"Your word is a palindrome "<<endl;
    } else {
        cout<<"Your word is NOT a palindrome "<<endl;
    }
    
    return 0;
}