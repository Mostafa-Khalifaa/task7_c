#include <iostream>
#include "complex.h"
using namespace std;

int main() {
    Complex c1(3, 4);
    Complex c2(1, -2);

    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;

    // Arithmetic
    cout << "\nc1 + c2 = " << (c1 + c2) << endl;
    cout << "c1 * c2 = " << (c1 * c2) << endl;

    // Unary
    cout << "\n-c1 = " << (-c1) << endl;

    // Increment
    Complex c3(5, 3);
    cout << "\nc3 = " << c3 << endl;
    cout << "++c3 = " << (++c3) << endl;

    // Comparison
    cout << "\nc1 == c2: " << (c1 == c2 ? "true" : "false") << endl;

    // Subscript
    cout << "\nc1[0] = " << c1[0] << ", c1[1] = " << c1[1] << endl;

    Complex c4(c1);
    c1[0] = 99;
    cout << "\nAfter c1[0]=99: c1=" << c1 << ", c4=" << c4 << " (deep copy!)" << endl;

    return 0;
}
