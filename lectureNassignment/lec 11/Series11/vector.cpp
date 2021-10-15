//
// Created by andrews on 11.06.21.
//

#include "vector.h"

// Exercise 11.6 ---- 11.7
// Methods for the vector class.

// Std Constructor for Vector.
Vector::Vector(){
    dim = 0;
    coeff = (double*) 0;
}

// Constructor with parameters.
Vector::Vector(int dim, double init){
    assert(dim >= 0);
    this->dim = dim;
    if (dim != 0){
        coeff = new double[dim];
        for (int j =0 ; j < dim; ++j){
            coeff[j] = init;
        }
    }
    else{
        coeff = (double*) 0;
    }
}

// Copy Constructor.
Vector::Vector(const Vector& rhs){
    dim = rhs.dim;
    if (dim == 0){
        coeff = (double*) 0;
    }
    else{
        coeff = new double[dim];
        for (int j = 0; j < dim; ++j){
            coeff[j] = rhs[j];
        }
    }
}

// Destructor
Vector::~Vector(){
    if (dim > 0){
        delete[] coeff;
    }
}

// Assignment operator
Vector& Vector::operator=(const Vector& rhs){
    if (this != &rhs){
        if (dim != rhs.dim){
            if (dim > 0){
                delete[] coeff;
            }
            dim = rhs.dim;
            if (dim > 0){
                coeff = new double[dim];
            }
            else{
                coeff = (double*) 0;
            }
        }
        for (int j = 0; j < dim; ++j){
            coeff[j] = rhs[j];
        }
    }
    return *this;
}

// Size of the vector.
int Vector::size() const {
    return dim;
}

// Get element
const double& Vector::operator[](int k) const {
    assert (k >= 0 && k < dim);
    return coeff[k];
}

double& Vector::operator[](int k){
    assert(k >= 0 && k < dim);
    return coeff[k];
}

// Norm method
double Vector::norm() const {
    double sum = 0;
    for (int j = 0; j<dim; ++j){
        sum = sum + coeff[j]*coeff[j];
    }
    return sqrt(sum);
}

// addition of vectors
const Vector operator+(const Vector& rhs1, const Vector& rhs2){
    assert(rhs1.size() == rhs2.size());
    Vector result(rhs1);
    for (int j = 0; j < result.size(); ++j){
        result[j] += rhs2[j];
    }
    result;
}
// scalar multiplication
const Vector operator*(const double scalar, const Vector& input){
    Vector result(input);
    for (int j = 0; j < result.size(); ++j){
        result[j] *= scalar;
    }
    return result;
}

const Vector operator*(const Vector& input, const double scalar){
    return scalar*input;
}

// scalar product
const double operator*(const Vector& rhs1, const Vector& rhs2){
    double scalarproduct = 0;
    assert(rhs1.size() == rhs2.size());
    for (int j = 0; j < rhs1.size(); ++j){
        scalarproduct += rhs1[j]*rhs2[j];
    }
    return scalarproduct;
}

// Exercise 11.6
const Vector operator*(const Upper& A, const Vector& x){
    assert(A.size() == x.size());
    int dim = A.size();
    Vector b(dim);
    int sum;
    for (int i = 0; i < dim; ++i){
        sum = 0;
        for (int j = 0; j < dim; j++){
            sum =sum + A(i+1, j+1)*x[j];
        }
        b[i] = sum;
    }
    return b;
}

// Exercise 11.7
const Vector operator|(const Upper& A, const Vector& b){
    assert(A.size() == b.size());
    int n = A.size();
    Vector x(n);
    x[n-1] = b[n-1]/A(n,n);
    for (int i = n-1; i >= 0; --i){
        double s = 0;
        for (int j = i + 1; j < n; ++j){
            s = s + A(i+1,j+1)*x[j];
            x[i] = (b[i]-s)/A(i+1, i+1);
        }
    }
    return x;
}