#include <cmath>
#include <iostream>
using std::cout;
using std::endl;

//Define Class

class Ellipse {
    private:
        double x[2];
        double y[2];
        
    public:
        void setCenter(double, double);
        void setAxis(double, double);
        void printFocalPoints();
        double getEccentricity();
        bool isCircle();
        bool isInside(double,double);
};

//Define Functions

void Ellipse::setCenter(double x0, double x1) {
    x[0] = x0; x[1] = x1;
}

void Ellipse::setAxis(double y0, double y1) {
    y[0] = y0; y[1] = y1;
}

double Ellipse::getEccentricity() {
    return ( sqrt(1-(fmin(y[0],y[1])/fmax(y[0],y[1]))*(fmin(y[0],y[1])/fmax(y[0],y[1]))));
}

bool Ellipse::isCircle(){
    
    if(y[0]==y[1]){
        return 1;
    }

    else {
        return 0;
    }
}

bool Ellipse::isInside(double x0, double y0){
    
    double z1;
    double z2;
    z1=(x0-x[0])*(x0-x[0])/(y[0]*y[0]);
    z2=(y0-x[1])*(y0-x[1])/(y[1]*y[1]);
    if(z1+z2<1){
        return 1;
    } else if(z1+z2==1){
        cout << "The point is in the boundary "<< endl;
        return 1;
    } else {
        
        return 0;
    }
}

void Ellipse::printFocalPoints() {
    double c;
    double c1;
    double c2;

    if(y[0]>y[1]){
        c=sqrt(y[0]*y[0]-y[1]*y[1]);
        c1=x[0]+c;
        c2=x[0]-c;
        cout << "The foci are: " << endl;
        cout << "(" << c1 << ","<< x[1] <<")"<< endl;
        cout << "(" << c2 << ","<< x[1] <<")"<< endl;
    } else if (y[0]<y[1]){
        c=sqrt(y[1]*y[1]-y[0]*y[0]);
        c1=x[1]+c;
        c2=x[1]-c;
        cout << "The foci are: " << endl;
        cout << "(" << c1 << ","<< x[0] <<")"<< endl;
        cout << "(" << c2 << ","<< x[0] <<")"<< endl;
    } else {
        cout << "The focus is: " << endl;
        cout << "(" << x[0] << ","<< x[1] <<")"<< endl;
        
    }
}