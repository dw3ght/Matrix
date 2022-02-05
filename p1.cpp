#include <iostream>
#include <cstdlib>
#include "Matrix.h"
//#include "Matrix.cpp"

using namespace std;

typedef unsigned int uint;

int main() {

  //initializing 
Matrix a(2, 2);
a.at(0, 0) = 1; // [ 1, 2 ]
a.at(0, 1) = 2; // [ 1, 3 ]
a.at(1, 0) = 1;
a.at(1, 1) = 3;
Matrix b(2, 1);
b.at(0, 0) = 3; // [ 3 ]
b.at(1, 0) = 2; // [ 2 ]
Matrix c = a.multiply(b);
 cout << "[ " << c.at(0, 0) << " ]" << endl;  // [ 7 ]
Matrix d = a.add(b);
     cout << "[ " << d.at(1, 0) << " ]" << endl; // [9]
 Matrix e = a.subtract(b);
 cout << "[ " << e.at(0, 0) << " ]" << endl ; // [ 7 ]
Matrix f = a.divide(2);
 cout << "[ " << f.at(0, 0) << " ]" << endl;  // [ 7 ]

 // cout << "Dwight" << endl;

  return EXIT_SUCCESS;
}
