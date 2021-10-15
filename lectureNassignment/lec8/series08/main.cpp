
#include "matrix.hpp"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
int main() {
//    int dim;
//    char type;
//    double init;
    cout <<"EX 8.1 \n Initialise a Matrix A"<<endl;

    Matrix A;
    cout <<"Print A:" << endl;
//    A.printMatrix();
//    cout << "Let us first enter a matrix"<< endl;
//    cout << "What is the dimension "<<endl;
//    cin >> dim;
//    cout << "what is the type(F,L,U) "<<endl;
//    cin >>type;
    A.scanMatrix();

    return 0;
}