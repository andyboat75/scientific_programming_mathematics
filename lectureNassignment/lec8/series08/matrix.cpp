#include "matrix.hpp"
#include <cassert>

using std::cout;
using std::cin;
using std::endl;

// Exercise 8.1
Matrix::Matrix() {
    n = 1;
    type='F';
    coeff = (double*) 0;
//    createMatrix(n,0,'F');
}

Matrix::Matrix(int n, char type) {
    this ->createMatrix(n,0,type);
}

Matrix::Matrix(int n, double init, char Type) {
    this ->createMatrix(n, init, type);
}


int Matrix::index(int row, int col) {
    int c = 0;
    int z = 1;
    if (type == 'U') {
        return col * (col - 1) / 2 + row - 1;
    } else if (type == 'L') {
        return (col - 1) * (2 * n - col + 2) / 2 + row - col;
    } else {
        return n * (col - 1) + row - 1;
    }
    return c - 1;
}

double Matrix::getCoeff(int i) { return coeff[i]; }

int Matrix::getLength() {
    if (type == 'F') {
        return n * n;
    } else {
        return n * (n + 1) / 2;
    }
}

void Matrix::nullMatrix() {
    n = 0;
    coeff = (double *) 0;
    type = 'F';
    cout << " allocate empty matrix " << "\n";
}

void Matrix::createMatrix(int dim, double init, char Type) {

    assert(dim > 0);
    n = dim;

    assert(Type == 'F' || Type == 'U' || Type == 'L');
    type = Type;

    if (type == 'F') {

        coeff = (double *) malloc(dim * dim * sizeof(double));
        assert(coeff != (double *) 0);
        for (int j = 0; j < dim * dim; ++j) {
            coeff[j] = init;
        }

    } else {
        coeff = (double *) malloc(dim * (dim + 1) * sizeof(double) / 2);
        assert(coeff != (double *) 0);
        for (int j = 0; j < dim * (dim + 1) / 2; ++j) {
            coeff[j] = init;
        }
    }
}

void Matrix::zeroMatrix(int dim, char Type) {
    createMatrix(dim, 0, Type);
}

int Matrix::getDimension() { return this -> n; }

char Matrix::getType() { return this->type; }

void Matrix::setElement(int i, int j, double value) {
    if (getType() == 'F') {
        assert(i <= n && j <= n && j * i > 0);
        coeff[index(i, j)] = value;
    } else if (getType() == 'U') {
        assert(i <= n && j <= n && j * i > 0 && j >= i);
        coeff[index(i, j)] = value;
    } else {
        assert(i <= n && j <= n && j * i > 0 && j <= i);
        coeff[index(i, j)] = value;
    }
}

double Matrix::getElement(int i, int j) {

    if (getType() == 'F') {
        assert(i <= n && j <= n && j * i > 0);
        return coeff[index(i, j)];
    } else if (getType() == 'U') {
        assert(i <= n && j <= n && j * i > 0 && j >= i);
        return coeff[index(i, j)];
    } else {
        assert(i <= n && j <= n && j * i > 0 && j <= i);
        return coeff[index(i, j)];
    }
}

Matrix::~Matrix() {
    if (n > 0) {
        free(coeff);
    }
}

// Exercise 8.2
void Matrix::printMatrix() {

    if (getType() == 'F') {

        for (int i = 1; i < getDimension() + 1; i++) {

            for (int j = 1; j < getDimension() + 1; j++) {
                cout << getElement(i, j) << " ";
            }
            cout << endl;
        }
    } else if (getType() == 'U') {

        for (int i = 1; i < getDimension() + 1; i++) {

            for (int j = 1; j < getDimension() + 1; j++) {

                if (j >= i) {
                    cout << getElement(i, j) << " ";
                } else {
                    cout << " 0 " << " ";
                }
            }
            cout << endl;
        }
    } else {

        for (int i = 1; i < n + 1; i++) {

            for (int j = 1; j < getDimension() + 1; j++) {

                if (j <= i) {
                    cout << getElement(i, j) << " ";
                } else {
                    cout << "0" << " ";
                }
            }
            cout << endl;
        }
    }
}

void Matrix::scanMatrix() {
    cout << "Enter the dimension of the matrix: "<<endl;
    cin >> this -> n;
    cout << "Enter the type of the matrix: "<<endl;
    cin >> this -> type;
    Matrix(n,type);
    double c;
    if (getType() == 'F') {
        for (int i = 1; i < getDimension() + 1; ++i) {
            for (int j = 1; getDimension() + 1; ++j) {
                cin >> c;
                setElement(i, j, c);
            }
        }
    } else if (getType() == 'U') {
        for (int i = 1; i < getDimension() + 1; ++i) {
            for (int j = 1; j < getDimension() + 1; ++j) {
                if (j >= i) {
                    cout << "Input element " << " row " << i << " " << " col " << j << " ";
                    cin >> c;
                    setElement(i, j, c);
                }
            }
            cout << endl;
        }
    } else {
        for (int i = 1; i < n + 1; ++i) {
            for (int j = 1; j < getDimension() + 1; ++j) {
                cin >> c;
                setElement(i, j, c);
            }
        }
        cout << endl;
    }
}

// Exercise 8.3
double Matrix::columnSumNorm() {
    double c = 0;
    double sum;
    if (getType() == 'F') {


        for (int j = 1; j < getDimension() + 1; j++) {
            sum = 0;
            for (int i = 1; i < getDimension() + 1; i++) {
                sum = sum + fabs(getElement(i, j));
            }

            if (sum >= c) { c = sum; }
        }

    } else if (getType() == 'U') {

        for (int j = 1; j < getDimension() + 1; j++) {
            sum = 0;
            for (int i = 1; i < getDimension() + 1; i++) {

                if (j >= i) {
                    sum = sum + fabs(getElement(i, j));
                }
            }
            if (sum >= c) { c = sum; }
        }

    } else {

        for (int j = 1; j < getDimension() + 1; j++) {
            sum = 0;
            for (int i; i < getDimension() + 1; i++) {

                if (j <= i) {
                    sum = sum + fabs(getElement(i, j));
                }
            }

            if (sum > c) { c = sum; }

        }

    }

    return c;
}

double Matrix::rowSumNorm() {
    double c = 0;
    double sum;
    if (getType() == 'F') {


        for (int i = 1; i < getDimension() + 1; i++) {
            sum = 0;
            for (int j = 1; j < getDimension() + 1; j++) {
                sum = sum + fabs(getElement(i, j));
            }
            if (sum >= c) { c = sum; }
        }
    } else if (getType() == 'U') {

        for (int i = 1; i < getDimension() + 1; i++) {
            sum = 0;
            for (int j = 1; j < getDimension() + 1; j++) {

                if (j >= i) {

                    sum = sum + fabs(getElement(i, j));

                }
            }

            if (sum >= c) { c = sum; }
        }

    } else {

        for (int i = 1; i < getDimension() + 1; i++) {
            sum = 0;
            for (int j; j < getDimension() + 1; j++) {

                if (j <= i) {
                    sum = sum + fabs(getElement(i, j));
                }
            }
            if (sum > c) { c = sum; }
        }
    }
    return c;
}

double Matrix::frobeniusNorm() {
    double sum = 0;

    if (getType() == 'F') {


        for (int i = 1; i < getDimension() + 1; i++) {

            for (int j = 1; j < getDimension() + 1; j++) {
                sum = sum + fabs(getElement(i, j)) * fabs(getElement(i, j));
            }
        }


    } else if (getType() == 'U') {

        for (int i = 1; i < getDimension() + 1; i++) {

            for (int j = 1; j < getDimension() + 1; j++) {

                if (j >= i) {

                    sum = sum + fabs(getElement(i, j)) * fabs(getElement(i, j));
                }
            }

        }

    } else {

        for (int i = 1; i < getDimension() + 1; i++) {

            for (int j; j < getDimension() + 1; j++) {

                if (j <= i) {
                    sum = sum + fabs(getElement(i, j)) * fabs(getElement(i, j));
                }
            }

        }

    }
    return sqrt(sum);
}

// Exercise 8.4
double Matrix::trace() {
    double sum = 0;
    for (int i = 1; i < getDimension() + 1; i++) {
        for (int j = 1; j < getDimension() + 1; j++) {
            if (i == j) {
                sum = sum + getElement(i, j);
            }
        }
    }
    return sum;
}

bool Matrix::isDiagonal() {

    if (type = 'U') {
        for (int i = 1; i < getDimension() + 1; i++) {
            for (int j = 1; j < getDimension() + 1; j++) {
                if (j > i) {
                    if (getElement(i, j) != 0) {
                        return 0;
                    }

                }
            }


        }
        return 1;

    } else if (type = 'L') {
        for (int i = 1; i < getDimension() + 1; i++) {
            for (int j = 1; j < getDimension() + 1; j++) {
                if (j < i) {
                    if (getElement(i, j) != 0) {
                        return 0;
                    }

                }
            }
        }
        return 1;

    } else {
        for (int i = 1; i < getDimension() + 1; i++) {
            for (int j = 1; j < getDimension() + 1; j++) {
                if (j < i || j > i) {
                    if (getElement(i, j) != 0) {
                        return 0;
                    }

                }
            }
        }
        return 1;

    }
}

bool Matrix::isSymmetric() {
    if (type = 'U') {
        for (int i = 1; i < getDimension() + 1; i++) {
            for (int j = 1; j < getDimension() + 1; j++) {
                if (j > i) {
                    if (getElement(i, j) != 0) {
                        return 0;
                    }

                }
            }


        }
        return 1;

    } else if (type = 'L') {
        for (int i = 1; i < getDimension() + 1; i++) {
            for (int j = 1; j < getDimension() + 1; j++) {
                if (j < i) {
                    if (getElement(i, j) != 0) {
                        return 0;
                    }

                }
            }
        }
        return 1;

    } else {
        for (int i = 1; i < getDimension() + 1; i++) {
            for (int j = 1; j < getDimension() + 1; j++) {
                if (j < i || j > i) {
                    if (getElement(i, j) != getElement(j, i)) {
                        return 0;
                    }

                }
            }
        }
        return 1;

    }
}

bool Matrix::isSkewSymmetric() {
    if (type = 'U') {
        for (int i = 1; i < getDimension() + 1; i++) {
            for (int j = 1; j < getDimension() + 1; j++) {
                if (j > i) {
                    if (getElement(i, j) != 0) {
                        return 0;
                    }

                }
            }


        }
        return 1;

    } else if (type = 'L') {
        for (int i = 1; i < getDimension() + 1; i++) {
            for (int j = 1; j < getDimension() + 1; j++) {
                if (j < i) {
                    if (getElement(i, j) != 0) {
                        return 0;
                    }

                }
            }
        }
        return 1;

    } else {
        for (int i = 1; i < getDimension() + 1; i++) {
            for (int j = 1; j < getDimension() + 1; j++) {
                if (j < i || j > i) {
                    if (getElement(i, j) != (-1) * getElement(j, i)) {
                        return 0;
                    }

                }
            }
        }
        return 1;

    }
}

// Exercise 8.5
void Matrix::Random(int dim, char Type, double lower, double upper) {

    double c;

    Matrix(dim, Type);

    if (getType() == 'F') {


        for (int i = 1; i < getDimension() + 1; i++) {

            for (int j = 1; j < getDimension() + 1; j++) {
                srand(time(0));
                c = (double) rand() / (double) RAND_MAX * (upper - lower) + lower;
                setElement(i, j, c);
            }


        }


    } else if (getType() == 'U') {

        for (int i = 1; i < getDimension() + 1; i++) {

            for (int j = 1; j < getDimension() + 1; j++) {

                if (j >= i) {
                    srand(time(0));
                    c = (double) rand() / (double) RAND_MAX * (upper - lower) + lower;
                    setElement(i, j, c);

                }
            }

        }


    } else {

        for (int i = 1; i < getDimension() + 1; i++) {

            for (int j; j < getDimension() + 1; j++) {

                if (j <= i) {
                    srand(time(NULL));
                    c = (double) rand() / (double) RAND_MAX * (upper - lower) + lower;
                    setElement(i, j, c);
                }
            }

        }

    }

}