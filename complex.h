#ifndef COMPLEX_H_INCLUDED
#define COMPLEX_H_INCLUDED

#include <iostream>
#include <cmath>

class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r = 0, double i = 0);
    Complex(const Complex& other);
    Complex& operator=(const Complex& other);

    double getReal() const;
    double getImag() const;

    void setReal(double r);
    void setImag(double i);

    Complex operator+(const Complex& other) const;
    Complex operator+(double value) const;

    Complex operator-(const Complex& other) const;
    Complex operator-(double value) const;

    Complex operator*(const Complex& other) const;
    Complex operator*(double value) const;

    Complex operator/(const Complex& other) const;
    Complex operator/(double value) const;

    Complex& operator+=(const Complex& other);
    Complex& operator+=(double value);

    Complex& operator-=(const Complex& other);
    Complex& operator*=(const Complex& other);

    Complex operator-() const;

    bool operator==(const Complex& other) const;
    bool operator!=(const Complex& other) const;


    void print() const;
};

// Friend-like free functions
Complex operator+(double value, const Complex& c);
Complex operator-(double value, const Complex& c);
Complex operator*(double value, const Complex& c);
Complex operator/(double value, const Complex& c);

#endif // COMPLEX_H_INCLUDED
