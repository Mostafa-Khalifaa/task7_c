#include "complex.h"
using namespace std;

// Default Constructor
Complex::Complex() {
    real = 0;
    imag = 0;
}

// Parameter Constructor
Complex::Complex(double r, double i) {
    real = r;
    imag = i;
}

// Getters
double Complex::getReal() const { return real; }
double Complex::getImag() const { return imag; }

// Setters
void Complex::setReal(double r) { real = r; }
void Complex::setImag(double i) { imag = i; }

// Addition
Complex Complex::operator+(const Complex& other) const {
    return Complex(real + other.real, imag + other.imag);
}

// Subtraction
Complex Complex::operator-(const Complex& other) const {
    return Complex(real - other.real, imag - other.imag);
}

// Multiplication
Complex Complex::operator*(const Complex& other) const {
    return Complex((real * other.real - imag * other.imag),
                   (real * other.imag + imag * other.real));
}

// Division
Complex Complex::operator/(const Complex& other) const {
    double d = (other.real * other.real + other.imag * other.imag);
    return Complex((real * other.real + imag * other.imag) / d,
                   (imag * other.real - real * other.imag) / d);
}

// Comparison
bool Complex::operator==(const Complex& other) const {
    return (real == other.real && imag == other.imag);
}

bool Complex::operator!=(const Complex& other) const {
    return !(*this == other);
}

// Print
void Complex::display() const {
    cout << real;
    if (imag >= 0) cout << "+";
    cout << imag << "i" << endl;
}
