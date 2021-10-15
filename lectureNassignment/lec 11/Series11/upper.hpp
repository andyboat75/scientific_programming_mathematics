#ifndef _UPPER_
#define _UPPER_


#include<iostream>
#include<cmath>
#include<cassert>

using std::cout;
using std::endl;

class Upper{

    private:
        int n;
        double* coeff;

    public:
        //Exercise 11.1
        // Constructor
        Upper(int);
        // Constructor with parameters
        Upper(int, int);
        // Destructor
        ~Upper();
        // Assignment Operator
        Upper& operator=(const Upper&);
        // Copy Constructor
        Upper(const Upper& t);

        double getCoeff(int) const ;
        void setCoeff(int,double);
        double getElement(int, int) const;
        void setElement(int, int,double);
        int index(int, int) const;
        
        // Exercise 11.2
        int size() const;
        const double operator ()(int, int) const;
        double operator ()(int, int);
        
        // Exercise 11.3
        double columnSumNorm();
        double rowSumNorm();

};
// Exercise 11.3
std::ostream& operator<<(std::ostream& output, const Upper& f);

// Exercise 11.4
const Upper operator+(const Upper& x,const Upper& y);

const Upper operator*(const Upper& x,const Upper& y);


class Vector{
    private:
        int dim;
        double* coeff;
    public:
        // constructors, destructor, assignment
        Vector();
        Vector(int dim, double init=0);
        Vector(const Vector&);
        ~Vector();
        Vector& operator=(const Vector&);
        // return length of vector
        int size() const;
        // read and write entries
        const double& operator[](int) const;
        double& operator[](int);
        // compute Euclidean norm
        double norm() const;
};

// Exercise 11.6 ---- 11.7
// addition of vectors
const Vector operator+(const Vector&, const Vector&);
// scalar multiplication
const Vector operator*(const double, const Vector&);
const Vector operator*(const Vector&, const double);
// scalar product
const double operator*(const Vector&, const Vector&);
const Vector operator*(const Upper&, const Vector&);

// Exercise 11.7
const Vector operator|(const Upper&, const Vector&);

#endif