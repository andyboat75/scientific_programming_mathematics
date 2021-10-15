//
// Created by andrews on 14.05.21.
//

#include "vector.h"


Vector::Vector() {
    this -> dim = 0;
    this -> type = 'R';
    this -> coeff = new double [dim] = {};
    if (this -> coeff == nullptr) {
        cout <<"Error memory could not be allocated"<<endl;
        return ;
    }
    cout << "initialised an empty vector"<<endl;
}

Vector::Vector(int dim, char type, double init) {
    assert(dim > 0);
    this -> dim = dim;
    this -> type = type;
    // check if init value is any number other than zero(0).
    if (init != 0) {
        // allocate memory
        this -> coeff = new (nothrow) double [dim];
        // check if memory allocation was not successful
        if (this -> coeff == nullptr){
            cout << "Error memory could not be allocated"< endl;
            return;
        }
        // if it successful do the following
        else {
            for (int i = 0; i<dim, ++i) {
                coeff[i] = init;
            }
        }
    }
    // I don't there is a need for this since the vec is initialised with zero entries
    // in the standard constructor but just leave it here for now.
    else {
        this -> coeff = new double [dim] = {};
    }
    cout << "allocate vector, length "<< dim <<endl;
}

Vector::~Vector() {
    if (this -> dim > 0) {
        delete[] this -> coeff;
    }
}


double Vector::get(int k) {
    assert(k >= 0 && k < this->dim);
    return this -> coeff[k];
}

void Vector::set(int k, double value) {
    assert(k >= 0 && k < this->dim)
    this -> coeff[k] = value;
}

double Vector::norm() {
    double norm = 0;
    for (int i = 0; i < this->dim; ++i) {
        norm = norm + this->coeff[i] * this->coeff[i];
    }
    return sqrt(norm);
}