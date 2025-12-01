#include <iostream>
#include "complex.h"
using namespace std;

int main() {
    Complex a(2, 3);
    Complex b(1, 4);

    Complex add = a + b;
    Complex sub = a - b;
    Complex mul = a * b;
    Complex div = a / b;

    cout << "a = ";
    a.display();
    cout << "b = ";
    b.display();

    cout << "\na + b = ";
    add.display();
    cout << "a - b = ";
    sub.display();
    cout << "a * b = ";
    mul.display();
    cout << "a / b = ";
    div.display();

    cout << "\nAre they equal? " << (a == b ? "Yes" : "No") << endl;

    return 0;
}
