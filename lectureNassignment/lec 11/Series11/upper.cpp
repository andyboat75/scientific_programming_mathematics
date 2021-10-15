#include "upper.hpp"

// Constructor with parameter
Upper::Upper(int dim, int x) {
    n = dim;
    int N = dim * (dim + 1) / 2;
    coeff = (double *) malloc(N * sizeof(double));
    assert(coeff != (double *) 0);
    for (int j = 0; j < dim * (dim + 1) / 2; ++j) {
        coeff[j] = x;
    }
}

// std Constructor
Upper::Upper(int dim) {
    n = dim;
    int N = dim * (dim + 1) / 2;
    coeff = (double *) malloc(N * sizeof(double));
    assert(coeff != (double *) 0);
    for (int j = 0; j < dim * (dim + 1) / 2; ++j) {
        coeff[j] = 0;
    }
}

// Destructor
Upper::~Upper() {
    if (n > 0) {
        free(coeff);
    }
}

// Mutator methods
double Upper::getCoeff(int i) const { return coeff[i]; }

void Upper::setCoeff(int i, double x) { coeff[i] = x; }

int Upper::index(int row, int col) const {
    return col * (col - 1) / 2 + row - 1;
}

void Upper::setElement(int i, int j, double value) {
    assert(i <= n && j <= n && j * i > 0 && j >= i);
    coeff[index(i, j)] = value;
}

double Upper::getElement(int i, int j) const {
    assert(i <= n && j <= n && j * i > 0);
    if (i > j) {
        return 0;
    } else {
        return coeff[index(i, j)];
    }
}


int Upper::size() const { return n; }


//Assignment operator
Upper &Upper::operator=(const Upper &t) {
    if (this != &t) // No self assignments!
    {
        n = t.size();
        int dim = n;
        int N = dim * (dim + 1) / 2;
        coeff = (double *) malloc(N * sizeof(double));
        assert(coeff != (double *) 0);
        for (int j = 0; j < dim * (dim + 1) / 2; ++j) {
            coeff[j] = t.getCoeff(j);
        }
        return *this;
    }
}

Upper::Upper(const Upper &t) {
    n = t.size();
    int dim = n;
    int N = dim * (dim + 1) / 2;
    coeff = (double *) malloc(N * sizeof(double));
    assert(coeff != (double *) 0);
    for (int j = 0; j < dim * (dim + 1) / 2; ++j) {
        coeff[j] = t.getCoeff(j);
    }
}

const double Upper::operator()(int j, int k) const {
    assert(j >= 0 && j <= n);
    assert(k >= 0 && k <= n);
    if (j > k) {
        return 0;
    } else {
        return coeff[index(j, k)];
    }
}

double Upper::operator()(int j, int k) {
    assert(j >= 0 && j <= n);
    assert(k >= 0 && k <= n);
    if (j > k) {
        return 0;
    } else {
        return coeff[index(j, k)];
    }
}

// Exercise 11.3
std::ostream &operator<<(std::ostream &output, const Upper &f) {
    for (int i = 1; i < f.size() + 1; i++) {
        for (int j = 1; j < f.size() + 1; j++) {
            if (j >= i) {
                output << f.getElement(i, j) << " ";
            } else {
                output << "0" << " ";
            }
        }
        output << endl;
    }
    return output;
}

double Upper::columnSumNorm() {
    double c = 0;
    double sum;
    for (int j = 1; j < size() + 1; j++) {
        sum = 0;
        for (int i = 1; i < size() + 1; i++) {
            if (j >= i) {
                sum = sum + fabs(getElement(i, j));
            }
        }
        if (sum >= c) { c = sum; }
    }
    return c;
}

double Upper::rowSumNorm() {
    double c = 0;
    double sum;
    for (int i = 1; i < size() + 1; i++) {
        sum = 0;
        for (int j = 1; j < size() + 1; j++) {
            if (j >= i) {
                sum = sum + fabs(getElement(i, j));
            }
        }
        if (sum >= c) { c = sum; }
    }
    return c;
}

const Upper operator+(const Upper &x, const Upper &y) {
    assert(x.size() == y.size());
    Upper z(x.size());
    int dim = x.size();
    int N = dim * (dim + 1) / 2;
    for (int j = 0; j < N; ++j) {
        z.setCoeff(j, x.getCoeff(j) + y.getCoeff(j));
    }
    return z;
}

// Exercise 11.5
const Upper operator*(const Upper &x, const Upper &y) {

    assert(x.size() == y.size());

    Upper C(x.size());

    int dim = x.size();
    int sum;

    for (int i = 1; i < dim + 1; i++) {
        for (int j = 1; j < dim + 1; j++) {
            sum = 0;
            if (i <= j) {
                for (int k = 1; k < dim + 1; k++) {
                    sum = sum + x(i, k) * y(k, j);
                }
                C.setElement(i, j, sum);
            }
        }
    }
    return C;
}


// Exercise 11.6 ---- 11.7
// Methods for the vector class.

// Std Constructor for Vector.
Vector::Vector() {
    dim = 0;
    coeff = (double *) 0;
}

// Constructor with parameters.
Vector::Vector(int dim, double init) {
    assert(dim >= 0);
    this->dim = dim;
    if (dim != 0) {
        coeff = new double[dim];
        for (int j = 0; j < dim; ++j) {
            coeff[j] = init;
        }
    } else {
        coeff = (double *) 0;
    }
}

// Copy Constructor.
Vector::Vector(const Vector &rhs) {
    dim = rhs.dim;
    if (dim == 0) {
        coeff = (double *) 0;
    } else {
        coeff = new double[dim];
        for (int j = 0; j < dim; ++j) {
            coeff[j] = rhs[j];
        }
    }
}

// Destructor
Vector::~Vector() {
    if (dim > 0) {
        delete[] coeff;
    }
}

// Assignment operator
Vector &Vector::operator=(const Vector &rhs) {
    if (this != &rhs) {
        if (dim != rhs.dim) {
            if (dim > 0) {
                delete[] coeff;
            }
            dim = rhs.dim;
            if (dim > 0) {
                coeff = new double[dim];
            } else {
                coeff = (double *) 0;
            }
        }
        for (int j = 0; j < dim; ++j) {
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
const double &Vector::operator[](int k) const {
    assert (k >= 0 && k < dim);
    return coeff[k];
}

double &Vector::operator[](int k) {
    assert(k >= 0 && k < dim);
    return coeff[k];
}

// Norm method
double Vector::norm() const {
    double sum = 0;
    for (int j = 0; j < dim; ++j) {
        sum = sum + coeff[j] * coeff[j];
    }
    return sqrt(sum);
}

// addition of vectors
const Vector operator+(const Vector &rhs1, const Vector &rhs2) {
    assert(rhs1.size() == rhs2.size());
    Vector result(rhs1);
    for (int j = 0; j < result.size(); ++j) {
        result[j] += rhs2[j];
    }
    result;
}

// scalar multiplication
const Vector operator*(const double scalar, const Vector &input) {
    Vector result(input);
    for (int j = 0; j < result.size(); ++j) {
        result[j] *= scalar;
    }
    return result;
}

const Vector operator*(const Vector &input, const double scalar) {
    return scalar * input;
}

// scalar product
const double operator*(const Vector &rhs1, const Vector &rhs2) {
    double scalarproduct = 0;
    assert(rhs1.size() == rhs2.size());
    for (int j = 0; j < rhs1.size(); ++j) {
        scalarproduct += rhs1[j] * rhs2[j];
    }
    return scalarproduct;
}

// Exercise 11.6
const Vector operator*(const Upper &A, const Vector &x) {
    assert(A.size() == x.size());
    int dim = A.size();
    Vector b(dim);
    int sum;
    for (int i = 0; i < dim; ++i) {
        sum = 0;
        for (int j = 0; j < dim; j++) {
            sum = sum + A(i + 1, j + 1) * x[j];
        }
        b[i] = sum;
    }
    return b;
}

// Exercise 11.7
const Vector operator|(const Upper &A, const Vector &b) {
    assert(A.size() == b.size());
    int n = A.size();
    Vector x(n);
    x[n - 1] = b[n - 1] / A(n, n);
    for (int i = n - 1; i >= 0; --i) {
        double s = 0;
        for (int j = i + 1; j < n; ++j) {
            s = s + A(i + 1, j + 1) * x[j];
            x[i] = (b[i] - s) / A(i + 1, i + 1);
        }
    }
    return x;
}