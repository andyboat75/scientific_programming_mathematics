//
// Created by andrews on 11.06.21.
//

#ifndef SERIES11_VECTOR_H
#define SERIES11_VECTOR_H

#include<iostream>
#include<cmath>
#include<cassert>
#include "upper.hpp"

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



#endif //SERIES11_VECTOR_H
