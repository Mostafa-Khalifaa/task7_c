
#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
using namespace std;

class Complex {
private:
    double* real;
    double* imag;

public:
    // ===== CONSTRUCTORS =====
    Complex();
    Complex(double r, double i = 0);
    Complex(const Complex& other);

    // ===== DESTRUCTOR =====
    ~Complex();

    // ===== ASSIGNMENT OPERATORS =====
    Complex& operator=(const Complex& other);

    // ===== GETTERS AND SETTERS =====
    double getReal() const;
    double getImag() const;
    void setReal(double r);
    void setImag(double i);

    // ===== BINARY ARITHMETIC OPERATORS =====
    Complex operator+(const Complex& other) const;
    Complex operator-(const Complex& other) const;
    Complex operator*(const Complex& other) const;
    Complex operator/(const Complex& other) const;

    // ===== COMPOUND ASSIGNMENT OPERATORS =====
    Complex& operator+=(const Complex& other);
    Complex& operator-=(const Complex& other);
    Complex& operator*=(const Complex& other);
    Complex& operator/=(const Complex& other);

    // ===== UNARY OPERATORS =====
    Complex operator-() const;
    Complex operator+() const;

    // ===== INCREMENT/DECREMENT OPERATORS =====
    Complex& operator++();
    Complex operator++(int);
    Complex& operator--();
    Complex operator--(int);

    // ===== COMPARISON OPERATORS =====
    bool operator==(const Complex& other) const;
    bool operator!=(const Complex& other) const;
    bool operator<(const Complex& other) const;
    bool operator>(const Complex& other) const;
    bool operator<=(const Complex& other) const;
    bool operator>=(const Complex& other) const;

    // ===== LOGICAL OPERATORS =====
    bool operator!() const;
    operator bool() const;

    // ===== SUBSCRIPT OPERATOR =====
    double& operator[](int index);
    const double& operator[](int index) const;

    // ===== TYPE CONVERSION =====
    operator double() const;

    // ===== DISPLAY =====
    void display() const;

    // ===== FRIEND FUNCTIONS (STREAM OPERATORS) =====
    friend ostream& operator<<(ostream& os, const Complex& c);
    friend istream& operator>>(istream& is, Complex& c);
};

#endif
