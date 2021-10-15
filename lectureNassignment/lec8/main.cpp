//
// Created by andrews on 14.05.21.
//

#include "vector.h"
#include <iostream>

using std::cout;

int main() {
    Vector v1;
    cout << "v1 norm = "<<v1.norm()<<endl;
    Vector v2(3, 'R');
    cout << "v2 norm = "<< v2.norm()<<endl;
    Vector v3(3, 'R', 2);
    cout << "v3 norm = " << v3.norm() << endl;
}