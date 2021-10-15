#include "polynomial.hpp"
using std::ostream;

// Constructor
Polynomial::Polynomial(int Degree){
    assert(Degree >= 0);
    n = Degree;

    coeff = (double*) malloc((Degree+1)*sizeof(double));
    assert(coeff != (double*) 0);

    for (int j = 0; j < (Degree+1); ++j){
        coeff[j] = 0;
    }
}

// Destructor
Polynomial::~Polynomial(){
    if (n >= 0){
        free(coeff);
    }
}

// Copy Constructor
Polynomial::Polynomial(const Polynomial& t){
    assert(t.getDegree()>=0);
    n = t.getDegree();

    coeff = (double*) malloc((getDegree()+1)*sizeof(double));
    assert(coeff != (double*) 0);

    for (int j = 0; j < (getDegree()+1); ++j){
        coeff[j] = t.getCoeff(j);
    }
}

// Assignment Operator
Polynomial& Polynomial::operator=(const Polynomial& t){
    if (this != &t){
        n = t.getDegree();
        delete[] coeff;
        
        coeff = (double*) malloc((t.getDegree()+1)*sizeof(double));
        for (int i = 0; i < n+1; ++i){
            coeff[i] = t.getCoeff(i);
        }
    }
    return *this;
}

// Get degree of the polynomial.
int Polynomial::getDegree() const{
    return n;
}

// Get coefficient of the polynomial.
double Polynomial::getCoeff(int i) const{
    return coeff[i];
}

// Set coefficient of the polynomial
void Polynomial::setCoeff(int i, double x0){
    coeff[i] = x0;
}

// Print Operator
std::ostream& operator<<(std::ostream& output, const Polynomial& x){
    for (int i = x.getDegree(); i > -1; --i){
        if (i > 1 && i <x.getDegree()){
            output << x.getCoeff(i) << "x^" << i << " + ";
        }
        else if (i == 0){
            output << x.getCoeff(i);
        }
        else if (i == 1){
            output << x.getCoeff(i) << "x" << " + ";
        }
        else if (i == x.getDegree()){
            output << x.getCoeff(i) << "x^" << i << " + ";
        }

    }
    output << '\n';
    return output;
}

// Exercise 9.2
// Extension Ex 9.1 to access the coefficient of the polynomial using operator [].
const double& Polynomial::operator[](int j) const{
    assert(j > -1 && j <= n);
    return coeff[j];
}

double& Polynomial::operator[](int j){
    assert(j > -1 && j <= n);
    return coeff[j];
}

// Exercise 9.3
// Extension Ex 9.1 to add polynomials using operator +
const Polynomial operator+(const Polynomial& x,const Polynomial& y) {
        
        int n,m;
        if (x.getDegree()>y.getDegree()){
            n=x.getDegree();
            m=y.getDegree();
        }
        else{
            n=y.getDegree();
            m=x.getDegree();
        }

        Polynomial z(n);

        for (int i=0;i<m+1;i++){
            z[i] = x[i] + y[i];
        }

        if(n != m){

            for (int i = m + 1; i < n+1; i++){                
                if(x.getDegree()>y.getDegree()){
                    z[i]=x[i];
                }
                else{
                    z[i]=y[i];
                }
             }
        }
        return z;        
    }

// Addition of a constant(double) to a polynomial using +
const Polynomial operator+(const Polynomial& x,const double y) {
        
        int n=x.getDegree();
        
        Polynomial z(n);

        z[0]=x[0]+y;

        for (int i=1;i<n+1;i++){
            z[i]=x[i];
        }
       return z;        
}

// Addition of a constant(int) to a polynomial using +
const Polynomial operator+(const Polynomial& x, const int y) {
        
        int n=x.getDegree();
        
        Polynomial z(n);

        z[0]=x[0]+y;

        for (int i=1;i<n+1;i++){
            z[i]=x[i];
        }

       return z;        
}

// Exercise 9.4
// Multiplication of polynomials.
const Polynomial operator*(const Polynomial& x,const Polynomial& y) {
            
    int n=x.getDegree();
    int m=y.getDegree();

    Polynomial z(n+m);

    for (int i=0; i<x.getDegree()+1;i++){
        
        for (int j=0;j<y.getDegree()+1;j++){
            
            z[i+j] += x[i]*y[j];
        }
    }
        return z;        
}
        
const Polynomial operator*(const Polynomial& x,const double y) {
            
    int n=x.getDegree();
            
    Polynomial z(n);

    for (int i=0;i<n+1;i++){
        z[i]=x[i]*y;
    }

    return z;        
}

const Polynomial operator*(const double y, const Polynomial& x) {
            
    int n=x.getDegree();
            
    Polynomial z(n);
        
    for (int i=0;i<n+1;i++){
        z[i]=x[i]*y;
    }
    return z;        
}

// Exercise 9.5

bool operator==(const Polynomial &x, const Polynomial &y){
    if (x.getDegree()!=y.getDegree()){
        return 0;
    } 
    else
    {
        for (int i=0;i<x.getDegree()+1;i++){

            if(fabs(x[i]-y[i])>0.0000001){
                return 0;
            }
            
        }
    }
        
    return 1;
}

// Exercise 9.6
Polynomial Polynomial::operator()(int k){
        
    int s=getDegree()-k;

    if( k > n){
        s=0;
    }
            
    Polynomial z(s);

    z.setCoeff(0,0);
    
    if(k !=0 && k<=n){
                    
        double a=1;
            
        for (int i=0;i<s+1;i++){
            double a=1;
                
            for (int j=0;j<k;j++){
                a=a*(i+k-j);
            }
                       
            z.setCoeff(i,a*getCoeff(i+k));
        }
    }
        
    if(k==0){
                       
        for (int i=0;i<n+1;i++){
                
            z.setCoeff(i,getCoeff(i));
        }
           
    }

    return z;
        
}

double Polynomial::operator()(double x){
        
    double sum=0;
    for (int i=0;i<n+1;i++){            
        sum = sum + getCoeff(i)* pow(x,i);
    }
    return sum;        
}

double Polynomial::operator()(int k, double x){
    assert(k<=n+1);
    double sum=0;
    double a;
        
    for (int i=0;i<n+1;i++){
        a=1;
        if (i >= k){
            for (int j=0;j<k;j++){
                a=a*(i-j);    
            }    
            sum = sum + getCoeff(i) * pow(x,i-k) * a;
        }
    }
    return sum;        
}

// Exercise 9.7
double Polynomial::computeIntegral(double a, double b){
    assert(a < b);
    double sum = 0;
    for (int i = 0; i < n + 1; i++){
        sum = sum + coeff[i] * (pow(b, i + 1 ) - pow(a, i + 1))/(i+1);
    }

    return sum;

}

// Exercise 9.8
double Polynomial::computeZero(double x0, double tau){
    assert(tau>0);

    //This variable will store either tau or tau|Xn|
    double tau_2;

    //Logical variables to check when algorithm finishes
    int a = 0;
    int b = 0;

    //Stores points for iteration
    double y1;
        
    double y0=x0;
    
    double temp;

    
    
    
    
    while(a == 0 && b == 0) {

        //Calculates next approximation
        y1=y0-(computeDerivative(0,y0)/computeDerivative(1,y0));
                    
        //Checks first terminating condition
        if (fabs(computeDerivative(1,y1))<=tau){
            a = 1;
        }

        //Checks second terminating condition
        if (fabs(y1) <= tau){
            tau_2 = tau;
        }
        else{
            tau_2 = tau * fabs(y1);
        }
                
        if (fabs(computeDerivative(0,y1))<=tau && fabs(y1-y0)<=tau_2){
            b=1;
        }

        y0=y1;
    } 

    //If first condition is true prints warning message
    if (a){
        cout << " Result may possibly be wrong " << endl;
    }
    return y1;
}
  
double Polynomial::computeDerivative(int k, double x){
    double sum=0;
    double a;
    
    for (int i = 0; i < n + 1; i++){
        a = 1;
        if (i >= k){
            for (int j = 0; j < k; j++){
                a = a * (i-j);
                }
            sum = sum + getCoeff(i) * pow(x,i-k) * a;
        }
    }
    return sum;

}
