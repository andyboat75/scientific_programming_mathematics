#include "fraction.hpp"

// Std Constructor
Fraction::Fraction() {
    this->num = 0;
    this->den = 1;
}

// Constructor with parameters
Fraction::Fraction(int p, int q) {
    assert(q != 0);
    if (q < 0) {
        this->num = -p;
        this->den = abs(q);
    } else {
        this->num = p;
        this->den = q;
    }
}

// Destructor
Fraction::~Fraction() {
    // cout << "Destructor is executed." << endl;
}

int Fraction::getNum() const {
    return this->num;
}

int Fraction::getDen() const {
    return this->den;
}

void Fraction::setNum(int p) {
    this->num = p;
}

void Fraction::setDen(int q) {
    this->den = q;
}

Fraction::Fraction(const Fraction &f) {
    this->num = f.getNum();
    this->den = f.getDen();
}

Fraction &Fraction::operator=(const Fraction &f) {
    this->num = f.getNum();
    this->den = f.getDen();
    return *this;
}

std::ostream &operator<<(std::ostream &output, const Fraction &f) {
    output << f.getNum() << " / " << f.getDen() << endl;
    return output;
}

// Exercise 10.2
// Reduce method
void Fraction::reduce() {
    int a;
    a = gcd(this->num, this->den);
    this->num = this->num / a;
    this->den = this->den / a;
}

// Euclidean Algorithm.
int Fraction::gcd(int p, int q) {
//    int m = p;
//    int n = q;
    // Euclidean Algorithm for gcd.
    while (q != 0) {
        int t = q;
        q = p % q;
        p = t;
    }
    return p;
}

// Exercise 10.3

Fraction::operator double() {
    double ans;
    ans = (double) this->num / this->den;
    return ans;
}

Fraction::Fraction(double t) {
    int k;

    if (t < 0) {
        k = 1e9;
    } else if (t >= 0 && t < 10) {
        k = 1e8;
    } else if (t >= 10 && t < 100) {
        k = 1e7;
    } else if (t >= 100 && t < 1000) {
        k = 1e6;
    } else if (t >= 1000 && t < 10000) {
        k = 1e5;
    } else if (t >= 10000 && t < 100000) {
        k = 1e4;
    } else if (t >= 100000 && t < 1000000) {
        k = 1e3;
    } else if (t >= 1000000 && t < 10000000) {
        k = 100;
    } else if (t >= 10000000 && t < 100000000) {
        k = 100;
    } else if (t >= 100000000 && t < 1000000000) {
        k = 10;
    } else { k = 1; }

    int a = t * k;
    this->num = a;
    this->den = k;
    reduce();
}

// Exercise 10.4
// Operator -
const Fraction operator-(const Fraction &x, const Fraction &y) {

    int a = x.getNum() * y.getDen() - y.getNum() * x.getDen();
    int b = x.getDen() * y.getDen();

    Fraction z(a, b);
    z.reduce();
    return z;
}

// Operator *
const Fraction operator*(const Fraction &x, const Fraction &y) {

    int a = x.getNum() * y.getNum();
    int b = x.getDen() * y.getDen();

    Fraction z(a, b);
    z.reduce();
    return z;
}

// Operator /
const Fraction operator/(const Fraction &x, const Fraction &y) {

    assert(x.getDen() != 0 || y.getDen() != 0);

    int a = x.getNum() * y.getDen();
    int b = x.getDen() * y.getNum();

    Fraction z(a, b);
    z.reduce();
    return z;
}

// Operator +
const Fraction operator+(const Fraction &x, const Fraction &y) {

    int a = x.getNum() * y.getDen() + y.getNum() * x.getDen();
    int b = x.getDen() * y.getDen();
    Fraction z(a, b);
    z.reduce();
    return z;
}

// Exercise 10.5
// Overload operator -
const Fraction Fraction::operator-() const {
    return Fraction(-this->num, this->den);
}

// Exercise 10.6
bool operator==(const Fraction &x, const Fraction &y) {

    int a = x.getNum() * y.getDen();
    int b = y.getNum() * x.getDen();

//    if (a == b) { return 1; }
//    else {
//        return 0;
//    }
    return a==b;
}

bool operator!=(const Fraction &x, const Fraction &y) {

//    if (x == y) {
//        return 0;
//    } else {
//        return 1;
//    }
    return !(x==y);
}

bool operator>(const Fraction &x, const Fraction &y) {

    int a = x.getNum() * y.getDen();
    int b = y.getNum() * x.getDen();

//    if (a > b) {
//        return 1;
//    } else {
//        return 0;
//    }
    return a>b;
}

bool operator<(const Fraction &x, const Fraction &y) {

//    if (x > y) {
//        return 0;
//    } else {
//        return 1;
//    }
    return !(x>y);
}

bool operator<=(const Fraction &x, const Fraction &y) {

//    if (x < y || x == y) {
//        return 1;
//    } else {
//        return 0;
//    }
    return x < y || x ==y;
}

bool operator>=(const Fraction &x, const Fraction &y) {

//    if (x > y || x == y) {
//        return 1;
//    } else {
//        return 0;
//    }
    return x > y || x==y;
}

// Exercise 10.7
// Constructor for FractionVector
FractionVector::FractionVector(int dim) {

    assert(dim >= 0);
    n = dim;
    vector = (Fraction *) malloc((dim + 1) * sizeof(Fraction));
    assert(vector != (Fraction *) 0);
    for (int j = 0; j < (dim + 1); ++j) { vector[j] = Fraction(); }

}

// Destructor for FractionVector
FractionVector::~FractionVector() {
    free(vector);
    //cout<<"FractionVector Destructor"<<endl;
}

// Get elements of the vector
const Fraction &FractionVector::operator[](int j) const {
    assert(j > -1 && j <= n);
    return vector[j];
}

Fraction &FractionVector::operator[](int j) {
    assert(j > -1 && j <= n);
    return vector[j];
}

void FractionVector::setElement(int i, int nu, int de) {
    Fraction z(nu, de);
    vector[i] = z;
}


Fraction FractionVector::getElement(int i) {
    return vector[i];
}

int FractionVector::getSize() {
    return n;
}

//<< Output operator
std::ostream &operator<<(std::ostream &output, FractionVector &f) {

    output << "{ ";
    for (int i = 0; i < f.getSize() - 1; i++) {
        output << "[" << f[i].getNum() << "/" << f[i].getDen() << "] , ";
    }
    output << "[" << f[f.getSize() - 1].getNum() << "/" << f[f.getSize() - 1].getDen() << "]";
    output << " }" << endl;
    return output;
}

FractionVector::FractionVector(FractionVector &f) {
    n = f.getSize();
    vector = (Fraction *) malloc((f.getSize()) * sizeof(Fraction));
    for (int i = 0; i < n; i++) {
        setElement(i, f[i].getNum(), f[i].getDen());
    }
}

FractionVector &FractionVector::operator=(FractionVector &f) {
    n = f.getSize();
    free(vector);
    vector = (Fraction *) malloc((f.getSize()) * sizeof(Fraction));
    for (int i = 0; i < n; i++) {
        setElement(i, f[i].getNum(), f[i].getDen());
    }
    return *this;
}

//Exercise 10.8
void FractionVector::sort() {
    // Using bubble sort.
    for (int a = 0; a < getSize(); a = a + 1) {
        for (int b = a + 1; b < getSize(); b = b + 1) {
            Fraction aux_1 = getElement(a);
            Fraction aux_2 = getElement(b);
            if (aux_2 < aux_1) {
                setElement(a, aux_2.getNum(), aux_2.getDen());
                setElement(b, aux_1.getNum(), aux_1.getDen());
            }
        }
    }
}

// Complexity of O(n^2)
// Runtime 
// 10^2 = 0.5sec
// 10^3 = 50sec