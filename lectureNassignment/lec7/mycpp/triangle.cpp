#include <iostream>
#include "triangle.hpp" 
using std::cout;
using std::endl;

int main() {
    Triangle tri;
    tri.setX(0.0,0.0);
    tri.setY(2.0,0.0);
    tri.setZ(0.0,2.0);
    cout << "Area = " << tri.getArea() << endl;
    cout << "Perimeter = " << tri.getPerimeter() << endl;
    bool a=tri.isEquilateral();
    if(a){
        cout << "The triangle is equilateral "<< endl;
    } else {
        cout << "The triangle is NOT equilateral "<< endl;
    }

    return 0;
}