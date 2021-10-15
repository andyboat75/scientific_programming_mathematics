#include "upper.hpp"
//#include "vector.hpp"

int main(){

    //Exercise 11.1 ---- 11.7
    cout<<"Constructor"<<endl<<"A(3,1)="<<endl;
    Upper A(3,1);
    cout<<A<<endl;

    Upper B(2,2);
    cout<<"Constructor"<<endl<<"B(2,2)="<<endl;
    cout<<B<<endl;

    cout<<"Assignment operator"<<endl<<"B=A="<<endl;
    B=A;

    cout<<B<<endl;

    cout<<"Constructor"<<endl<<"C(3,2)="<<endl;
    Upper C(3,2);
    cout<<C<<endl;

    cout<<"Copy.constructor"<<endl<<"c(C)="<<endl;
    Upper c(C);
    cout<<c<<endl;

    cout<<"rowsum norm A: "<<A.rowSumNorm()<<endl;
    cout<<"columnsum norm A: "<<A.columnSumNorm()<<endl;

    cout<<"Sum operator"<<endl<<"c=A+A="<<endl;
    c=A+A;
    cout<<c<<endl;
   
    cout<<"Matrix Multiplication"<<endl<<"c=A*C="<<endl;
    c=A*C;
    cout<<c<<endl;

    Vector b(3,2);

    for(int i=0;i<3;i++){
        cout<<endl<<"b["<<i<<"]="<<b[i]<<endl;
    }

    Vector cc(3);
    cc=c*b;
    
    cout<<endl;
    cout<<endl<<"cc=A*C*b"<<endl;
    for(int i=0;i<3;i++){
        cout<<endl<<"cc["<<i<<"]="<<cc[i]<<endl;
    }
    cout<<endl;
    cout<<endl;
    b=c|cc;
    
    cout<<endl<<"b=A*C|cc="<<endl;
    for(int i=0;i<3;i++){
        cout<<endl<<"b["<<i<<"]="<<b[i]<<endl;
    }
    return 0;
}
