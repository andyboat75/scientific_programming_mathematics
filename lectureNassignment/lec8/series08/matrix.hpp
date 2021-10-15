#ifndef _MATRIX_
#define _MATRIX_

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <ctime>

class Matrix {
    // Exercise 8.1
private:
    int n;
    double *coeff;
    char type;
public:
    // standard constructor
    Matrix();

    Matrix(int n, char type);

    Matrix(int n, double init, char type);

    void nullMatrix();

    void createMatrix(int dim, double init, char type);

    void zeroMatrix(int, char);

    int getDimension();

    int getLength();

    char getType();

    void setElement(int, int, double);

    double getCoeff(int);

    double getElement(int, int);

    int index(int, int);

    ~Matrix();

    // Exercise 8.2
    void printMatrix();

    void scanMatrix();

    // Exercise 8.3
    double columnSumNorm();

    double rowSumNorm();

    double frobeniusNorm();

    // Exercise 8.4
    double trace();

    bool isDiagonal();

    bool isSymmetric();

    bool isSkewSymmetric();

    // Exercise 8.5
    void Random(int, char, double, double);
};

#endif