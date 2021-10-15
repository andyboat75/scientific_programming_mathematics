#ifndef _FRACTION_
#define _FRACTION_

#include <iostream>
#include <cmath>
#include <cassert>

using std::cout;
using std::endl;

class Fraction {
private:
    int num; // Numerator
    int den; // Denominator
public:
    // Exercise 10.1

    // Standard Constructor
    Fraction();

    // Constructor with parameters
    Fraction(int, int);

    // Destructor
    ~Fraction();

    // Copy Constructor
    Fraction(const Fraction &);

    // Assignment operator
    Fraction &operator=(const Fraction &);

    // Get method
    int getNum() const;

    int getDen() const;

    // Set method
    void setNum(int);

    void setDen(int);

    // Exercise 10.2
    void reduce();

    int gcd(int, int);

    // Exercise 10.3
    operator double();

    Fraction(double);

    // Exercise 10.5
    const Fraction operator-() const;

};

// Exercise 10.1
std::ostream &operator<<(std::ostream &output, const Fraction &f);

// Exercise 10.4
const Fraction operator-(const Fraction &x, const Fraction &y);

const Fraction operator*(const Fraction &x, const Fraction &y);

const Fraction operator/(const Fraction &x, const Fraction &y);

const Fraction operator+(const Fraction &x, const Fraction &y);

// Exercise 10.6
bool operator==(const Fraction &x, const Fraction &y);

bool operator!=(const Fraction &x, const Fraction &y);

bool operator>(const Fraction &x, const Fraction &y);

bool operator<(const Fraction &x, const Fraction &y);

bool operator>=(const Fraction &x, const Fraction &y);

bool operator<=(const Fraction &x, const Fraction &y);

// Exercise 10.7
class FractionVector {

private:
    int n;
    Fraction *vector;

public:
    // Constructor
    FractionVector(int);

    // Copy Operator
    FractionVector(FractionVector &);

    // Assignment Operator
    FractionVector &operator=(FractionVector &);

    // Destructor
    ~FractionVector();

    // Operator [] to get element of vector.
    const Fraction &operator[](int) const;

    Fraction &operator[](int);

    // Set Mutator
    void setElement(int, int, int);

    // Get Mutator
    Fraction getElement(int);

    // Get dimension
    int getSize();

    // Exercise 10.8
    // Sort method
    void sort();
};

std::ostream &operator<<(std::ostream &output, FractionVector &f);

#endif