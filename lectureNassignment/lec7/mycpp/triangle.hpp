#include <cmath>

//Define Class
class Triangle {
    private:
        double x[2];
        double y[2];
        double z[2];
    public:
        void setX(double, double);
        void setY(double, double);
        void setZ(double, double);
        double getArea();
        double getPerimeter();
        bool isEquilateral();
};

//Define functions
void Triangle::setX(double x0, double x1) {
    x[0] = x0; x[1] = x1;
}

void Triangle::setY(double y0, double y1) {
    y[0] = y0; y[1] = y1;
}

void Triangle::setZ(double z0, double z1) {
    z[0] = z0; z[1] = z1;
}

double Triangle::getArea() {
    return 0.5*fabs( (y[0]-x[0])*(z[1]-x[1])-(z[0]-x[0])*(y[1]-x[1]) );
}

double Triangle::getPerimeter() {
    double a=sqrt((y[0]-x[0])*(y[0]-x[0])+(y[1]-x[1])*(y[1]-x[1]));
    double b=sqrt((y[0]-z[0])*(y[0]-z[0])+(y[1]-z[1])*(y[1]-z[1]));
    double c=sqrt((x[0]-z[0])*(x[0]-z[0])+(x[1]-z[1])*(x[1]-z[1]));
    return a+b+c;
}

bool Triangle::isEquilateral(){
    double a=sqrt((y[0]-x[0])*(y[0]-x[0])+(y[1]-x[1])*(y[1]-x[1]));
    double b=sqrt((y[0]-z[0])*(y[0]-z[0])+(y[1]-z[1])*(y[1]-z[1]));
    double c=sqrt((x[0]-z[0])*(x[0]-z[0])+(x[1]-z[1])*(x[1]-z[1]));

    if(a==b && b==c){
        return 1;
    }

    else {
        return 0;
    }
}