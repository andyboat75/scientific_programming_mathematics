#include "PyTriple.h"
#include <set>

int main() {
//    std::cout << "standard constructor"<<endl;
//    Pytriple A;
//    cout << A << endl;

    std::cout << "standard constructor with argument"<<endl;
    PyTriple A(4,5,3);
    cout << A << endl;

    PyTriple B;
    B.generate(3,4);
    cout << B << endl;

//    PyTriple C;
//    C = B;
//    cout << C;
    PyTriple C(9,12,15);

    if (C.isPrimitive()){ printf("True");}
    else printf("False");

    if (C.isPyTriple()){ printf("True");}
    else printf("False");



    return 0;
}



//int main() {
//    PyTriple* table;
//    long N;
//
//    //input
//    cout <<"Enter N(upper bound of the pythagorean triples) -->";
//    cin >> N;
//    if (N<=0){
//        printf("N must be non-zero positive integer");
//        return 0;
//    }
//    // Allocate space for the table
//    table = new PyTriple[N];
//
//    // populate the table with all possible pythagorean triples
//    long index = 0;
//    long rootN = long(sqrt(double(N)));
//
//    for (long m=1; m<=rootN; m++){
//        for (long n=1; n<=rootN; n++){
//            PyTriple P = PyTriple();
//            P.generate(m,n);
//            if (P.get('c') <= N && P.isPrimitive()){
//                table[index] = P;
//                index++;
//            }
//        }
//    }
//
//    //sort the table
//    sort(table, table+index);
//
//    //print out non duplicate elements of the table
//    int count = 0;
//    cout << table[0] << endl;
//    for(int k=1; k<index; k++) {
//        if (table[k] != table[k-1]) {
//            cout << table[k] << endl;
//            count ++;
//        }
//    }
//    cout <<count<<endl;
//
//    //release memory held by the table
//    delete[] table;
//    return 0;
//}


//int main() {
//    std::set<PyTriple> table;
//    long N;
//
//    //input
//    cout <<"Enter N(upper bound of the pythagorean triples) --> ";
//    cin >> N;
//    if (N<=0){
//        printf("N must be non-zero positive integer");
//        return 0;
//    }
//
//    long rootN = long(sqrt(double(N)));
//
//    for (int m = 1; m <= rootN ; m++) {
//        for (int n = 1; n <= m; n++) {
//            PyTriple P;
//            P.genPrimitive(m,n);
//            if (P.get('c')<=N){
//                table.insert(P);
//            }
//        }
//
//    }
//
//    std::set<PyTriple>::iterator si;
//    for (si = table.begin(); si != table.end(); ++si) {
//        cout << *si << endl;
//    }
//    cout <<table.size()<<endl;
//
//    return 0;
//}