
#include "ellipse.hpp" 



int main() {
    Ellipse elli;
    elli.setCenter(0.5,0.5);
    elli.setAxis(1.0,2.0);
    cout << "Eccentricity = " << elli.getEccentricity() << endl;
    elli.printFocalPoints();
    bool b=elli.isCircle();
    if(b){
        cout << "This is a circle"<< endl;
    } else {
        cout << "This is NOT a circle"<< endl;
    }
    bool a=elli.isInside(0.0,3.0);
    if(a){
        cout << "Point is inside ellipse"<< endl;
    } else {
        cout << "Point is not in ellipse "<< endl;
    }

    return 0;
}