//
// Created by Andrews and Edward on 28.06.21.
//

#include "PyTriple.h"
#include "gcd.h"

// constructor
PyTriple::PyTriple() {
    this->a = this->b = this->c = 0;
}

// constructor with argument
PyTriple::PyTriple(long a, long b) {
    assert(a >= 0 && b >= 0);
    if (a < b) {
        this->a = a;
        this->b = b;
    } else {
        this->b = a;
        this->a = b;
    }
    this->c = sqrt(a * a + b * b);


}

// constructor with three argument
PyTriple::PyTriple(long x, long y, long z) {
    assert(x >= 0 && y >= 0 && z >= 0);
    a = x, b = y, c = z;
    this->pyTripleSort();
    if (this->isPyTriple()) {
        return;
    } else {
        cout << *this << " is not a pythagorean triple" << endl;
    }
}

//Destructor
PyTriple::~PyTriple() {
}


// methods
long PyTriple::get(char v) const {
    if (v == 'a') {
        return this->a;
    } else if (v == 'b') {
        return this->b;
    } else {
        return this->c;
    }
}


void PyTriple::pyTripleSort() {

    if (a > c) {
        swap(a, c);
    }
    if (a > b) {
        swap(a, b);
    }
    if (b > c) swap(b, c);
}

void PyTriple::set(char v, long i) {
    if (v == 'a') a = i;
    else if (v == 'b') b = i;
    else c = i;
}

void PyTriple::generate(long m, long n) {
//    if (m<n){swap(m,n);}
    this->a = abs(m * m - n * n);
    this->b = abs(2 * m * n);
    this->c = m * m + n * n;
    pyTripleSort();
}

void PyTriple::genPrimitive(long m, long n) {
    generate(m, n);
    //make sure a,b,c are rel prime.
    long d = gcd(a, b);
    a /= d;
    b /= d;
    c /= d;
}

bool PyTriple::isPyTriple() {
    if (c * c == a * a + b * b) return true;
    return false;
}


bool PyTriple::isPrimitive() {
    long d = gcd(this->a, this->b);
    if (d == 1 && (a == a / d) && (b == b / d) && (c == c / d)) {
        return true;
    }
    return false;
}


PyTriple &PyTriple::operator=(const PyTriple &rhs) {
    this->a = rhs.a;
    this->b = rhs.b;
    this->c = rhs.c;
    return *this;
}

bool PyTriple::operator==(const PyTriple &rhs) const {
    return ((a == rhs.a) && (b == rhs.b) && (c == rhs.c));
}

bool PyTriple::operator!=(const PyTriple &rhs) const {
    return !((*this) == rhs);
}

bool PyTriple::operator<(const PyTriple &rhs) const {
    if (this->c < rhs.c) { return true; }
    if (this->c > rhs.c) { return false; }
    if (this->b < rhs.b) { return true; }
    return false;

}


// output to screen
std::ostream &operator<<(std::ostream &output, const PyTriple &f) {
    output << "(" << f.get('a') << "," << f.get('b') << "," << f.get('c') << ")";
    return output;
}



