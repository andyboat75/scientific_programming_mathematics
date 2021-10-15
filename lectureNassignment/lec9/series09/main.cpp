#include <iostream>
#include "polynomial.hpp"

int main() {
    Polynomial p(3);
    p[3] = 1; p[2]=3; p[1] = 5; p[0]=6;
    Polynomial q(3);
    q[1] = 2; q[2]=1;q[3]=3; q[0]=7;


//    cout <<p<<endl;
    cout <<p.operator()(1) <<endl;
    cout <<p.operator()(2) <<endl;
    cout << p(2, 1)<<endl;
    cout <<p(2.3)<<endl;

//    cout << p.operator()(1).computeIntegral(0,1)<<endl;
    return 0;
}
