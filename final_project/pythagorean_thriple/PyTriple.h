//
// Created by Andrews and Edward on 28.06.21.
//

#ifndef PYTHAGOREAN_THRIPLE_PYTRIPLE_H
#define PYTHAGOREAN_THRIPLE_PYTRIPLE_H

#include <iostream>
#include <cassert>
#include <cmath>
#include <utility>
#include <algorithm>

using std::cout;
using std::endl;
using std::cin;
using std::cerr;
using std::swap;
using std::sort;
using std::abs;


class PyTriple {
private:
    long a, b, c;

public:
    //standard constructor (0,0,0)
    PyTriple();
    // constructor (a,b) that accepts the short and long leg of the triple and calc the hypotenuse
    PyTriple(long, long);
    // constructor (a,b,c).
    PyTriple(long, long, long);

    //destructor
    ~PyTriple();

    //methods
    long get(char) const;

    void set(char, long);

    void pyTripleSort();

    void generate(long, long);

    bool isPyTriple();

    bool isPrimitive();

    void genPrimitive(long, long);


    //operators
    PyTriple &operator=(const PyTriple &);   // Assignment
    bool operator==(const PyTriple &) const;

    bool operator!=(const PyTriple &) const;

    bool operator<(const PyTriple &) const;

};

//output
std::ostream &operator<<(std::ostream &output, const PyTriple &f);


//gcd
//long gcd(long, long);


#endif //PYTHAGOREAN_THRIPLE_PYTRIPLE_H
