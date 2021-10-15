#ifndef _POLYNOMIAL_
#define _POLYNOMIAL_

#include <iostream>
#include <cmath>
#include <cassert>
using std::cout;
using std::endl;

class Polynomial{
    private:
        int n;
        double* coeff;
    public:
        // Exercise 9.1

        // Constructor
        Polynomial(int Degree);
        // Destructor
        ~Polynomial();
        // Copy Constructor
        Polynomial(const Polynomial&);
        // Assignment Operator
        Polynomial& operator=(const Polynomial&);
        // Get degree
        int getDegree() const;
        // Get Coefficient
        double getCoeff(int) const;
        // Set Coefficient(Mutator)
        void setCoeff(int, double);

        // Exercise 9.2
        const double& operator [](int j) const;
        double& operator [](int j);

        // Exercise 9.6
        Polynomial operator()(int);
        double operator()(double);
        double operator()(int, double);

        // Exercise 9.7
        double computeIntegral(double, double);

        // Exercise 9.8
        double computeZero(double, double);
        double computeDerivative(int, double);

};
// Exercise 9.1
std::ostream& operator<<(std::ostream& output, const Polynomial& x);
// Exercise 9.3
const Polynomial operator+(const Polynomial& x, const Polynomial& y);
const Polynomial operator+(const Polynomial& x, const double y);
const Polynomial operator+(const Polynomial& x, const int y);
// Exercise 9.4
const Polynomial operator*(const Polynomial& x, const Polynomial& y);
const Polynomial operator*(const Polynomial& x, const double y);
const Polynomial operator*(const double y, const Polynomial& x);
// Exercise 9.5
bool operator==(const Polynomial &x, const Polynomial &y);
// Exercise 9.6


#endif