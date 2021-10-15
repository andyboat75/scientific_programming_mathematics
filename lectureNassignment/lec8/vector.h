//
// Created by andrews on 14.05.21.
//

#ifndef LEC8_VECTOR_H
#define LEC8_VECTOR_H

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cassert>

using namespace std;
using std::cout;
using std::endl;


class Vector {
private:
    int dim;
    char type;  // row R or collumn C vector
    double * coeff;

public:
    // standard constructor
    Vector();
    // constructor
    Vector(int dim, char type, double init=0);
    // destructor
    ~Vector();
    // vector size
    int size();
    // get value at index k
    double get(int k);
    // write vector
    void set(int k, double value);
    // norm of a vector
    double norm();

};


#endif //LEC8_VECTOR_H
