#ifndef COMPLEX_H_INCLUDED
#define COMPLEX_H_INCLUDED

#include <iostream>

class Complex {
private:
    double real;
    double imag;

public:
    // Constructors
    Complex();
    Complex(double r, double i);

    // Get & Set functions
    double getReal() const;
    double getImag() const;
    void setReal(double r);
    void setImag(double i);

    // Arithmetic Operators
    Complex operator+(const Complex& other) const;
    Complex operator-(const Complex& other) const;
    Complex operator*(const Complex& other) const;
    Complex operator/(const Complex& other) const;

    // Comparison
    bool operator==(const Complex& other) const;
    bool operator!=(const Complex& other) const;

    // Print Method
    void display() const;
};

#endif // COMPLEX_H_INCLUDED
