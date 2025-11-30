#include "complex.h"

// Constructor
Complex::Complex(double r, double i) : real(r), imag(i) {}
// Copy constructor
Complex::Complex(const Complex& other) {
    real = other.real;
    imag = other.imag;
}
// Assignment operator
Complex& Complex::operator=(const Complex& other) {
    real = other.real;
    imag = other.imag;
    return *this;
}

double Complex::getReal() const { return real; }
double Complex::getImag() const { return imag; }

void Complex::setReal(double r) { real = r; }
void Complex::setImag(double i) { imag = i; }

// Complex + Complex
Complex Complex::operator+(const Complex& other) const {
    return Complex(real + other.real, imag + other.imag);
}
// Complex + double
Complex Complex::operator+(double value) const {
    return Complex(real + value, imag);
}
// Complex - Complex
Complex Complex::operator-(const Complex& other) const {
    return Complex(real - other.real, imag - other.imag);
}
// Complex - double
Complex Complex::operator-(double value) const {
    return Complex(real - value, imag);
}
// Complex * Complex
Complex Complex::operator*(const Complex& other) const {
    return Complex(real * other.real - imag * other.imag,
                   real * other.imag + imag * other.real);
}
// Complex * scalar
Complex Complex::operator*(double value) const {
    return Complex(real * value, imag * value);
}
// Complex / Complex
Complex Complex::operator/(const Complex& other) const {
    double denominator = other.real * other.real + other.imag * other.imag;
    if (denominator == 0) {
        std::cout << "Error: Division by zero!" << std::endl;
        return Complex();
    }

    return Complex((real * other.real + imag * other.imag) / denominator,
                   (imag * other.real - real * other.imag) / denominator);
}
// Complex / scalar
Complex Complex::operator/(double value) const {
    if (value == 0) {
        std::cout << "Error: Division by zero!" << std::endl;
        return Complex();
    }
    return Complex(real / value, imag / value);
}
// += operator for Complex
Complex& Complex::operator+=(const Complex& other) {
    real += other.real;
    imag += other.imag;
    return *this;
}
// += operator for scalar
Complex& Complex::operator+=(double value) {
    real += value;
    return *this;
}

// -= operator for Complex
Complex& Complex::operator-=(const Complex& other) {
    real -= other.real;
    imag -= other.imag;
    return *this;
}
//*= operator
Complex& Complex::operator*=(const Complex& other) {
    double newReal = real * other.real - imag * other.imag;
    double newImag = real * other.imag + imag * other.real;
    real = newReal;
    imag = newImag;
    return *this;
}
// Unary minus
Complex Complex::operator-() const {
    return Complex(-real, -imag);
}

// Comparison operators
bool Complex::operator==(const Complex& other) const {
    return real == other.real && imag == other.imag;
}

bool Complex::operator!=(const Complex& other) const {
    return !(*this == other);
}

void Complex::print() const {
    if (imag >= 0)
        std::cout << real << " + " << imag << "i";
    else
        std::cout << real << " - " << -imag << "i";
}

// double + Complex
Complex operator+(double value, const Complex& c) {
    return c + value;
}
// double - Complex
Complex operator-(double value, const Complex& c) {
    return Complex(value - c.getReal(), -c.getImag());
}
// double * Complex
Complex operator*(double value, const Complex& c) {
    return c * value;
}
// double / Complex
Complex operator/(double value, const Complex& c) {
    double denom = c.getReal() * c.getReal() + c.getImag() * c.getImag();
    if (denom == 0) {
        std::cout << "Error: Division by zero!" << std::endl;
        return Complex();
    }
    return Complex((value * c.getReal()) / denom,
                   (-value * c.getImag()) / denom);
}
