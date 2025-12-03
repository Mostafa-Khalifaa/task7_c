#include <cmath>
#include "complex.h"


// ===== CONSTRUCTORS =====

// Default Constructor
Complex::Complex() {
    real = new double(0);
    imag = new double(0);
}

// Parameter Constructor
Complex::Complex(double r, double i) {
    real = new double(r);
    imag = new double(i);
}

// Copy Constructor (Deep Copy)
Complex::Complex(const Complex& other) {
    real = new double(*other.real);
    imag = new double(*other.imag);
}

// ===== DESTRUCTOR =====

Complex::~Complex() {
    delete real;
    delete imag;
}

// ===== ASSIGNMENT OPERATORS =====

// Copy Assignment Operator
Complex& Complex::operator=(const Complex& other) {
    if (this != &other) {
        *real = *other.real;
        *imag = *other.imag;
    }
    return *this;
}

// ===== GETTERS AND SETTERS =====

double Complex::getReal() const {
    return *real;
}

double Complex::getImag() const {
    return *imag;
}

void Complex::setReal(double r) {
    *real = r;
}

void Complex::setImag(double i) {
    *imag = i;
}

// ===== BINARY ARITHMETIC OPERATORS =====

Complex Complex::operator+(const Complex& other) const {
    return Complex(*real + *other.real, *imag + *other.imag);
}

Complex Complex::operator-(const Complex& other) const {
    return Complex(*real - *other.real, *imag - *other.imag);
}

Complex Complex::operator*(const Complex& other) const {
    return Complex(
        (*real * *other.real - *imag * *other.imag),
        (*real * *other.imag + *imag * *other.real)
    );
}

Complex Complex::operator/(const Complex& other) const {
    double denominator = (*other.real * *other.real + *other.imag * *other.imag);
    if (denominator == 0) {
        throw runtime_error("Division by zero");
    }
    return Complex(
        (*real * *other.real + *imag * *other.imag) / denominator,
        (*imag * *other.real - *real * *other.imag) / denominator
    );
}

// ===== COMPOUND ASSIGNMENT OPERATORS =====

Complex& Complex::operator+=(const Complex& other) {
    *real += *other.real;
    *imag += *other.imag;
    return *this;
}

Complex& Complex::operator-=(const Complex& other) {
    *real -= *other.real;
    *imag -= *other.imag;
    return *this;
}

Complex& Complex::operator*=(const Complex& other) {
    double newReal = (*real * *other.real - *imag * *other.imag);
    double newImag = (*real * *other.imag + *imag * *other.real);
    *real = newReal;
    *imag = newImag;
    return *this;
}

Complex& Complex::operator/=(const Complex& other) {
    double denominator = (*other.real * *other.real + *other.imag * *other.imag);
    if (denominator == 0) {
        throw runtime_error("Division by zero");
    }
    double newReal = (*real * *other.real + *imag * *other.imag) / denominator;
    double newImag = (*imag * *other.real - *real * *other.imag) / denominator;
    *real = newReal;
    *imag = newImag;
    return *this;
}

// ===== UNARY OPERATORS =====

Complex Complex::operator-() const {
    return Complex(-*real, -*imag);
}

Complex Complex::operator+() const {
    return Complex(*real, *imag);
}

// ===== INCREMENT/DECREMENT OPERATORS =====

// Prefix increment
Complex& Complex::operator++() {
    (*real)++;
    return *this;
}

// Postfix increment
Complex Complex::operator++(int) {
    Complex temp = *this;
    (*real)++;
    return temp;
}

// Prefix decrement
Complex& Complex::operator--() {
    (*real)--;
    return *this;
}

// Postfix decrement
Complex Complex::operator--(int) {
    Complex temp = *this;
    (*real)--;
    return temp;
}

// ===== COMPARISON OPERATORS =====

bool Complex::operator==(const Complex& other) const {
    return (*real == *other.real && *imag == *other.imag);
}

bool Complex::operator!=(const Complex& other) const {
    return !(*this == other);
}

// Compare by magnitude
bool Complex::operator<(const Complex& other) const {
    double mag1 = sqrt(*real * *real + *imag * *imag);
    double mag2 = sqrt(*other.real * *other.real + *other.imag * *other.imag);
    return mag1 < mag2;
}

bool Complex::operator>(const Complex& other) const {
    return other < *this;
}

bool Complex::operator<=(const Complex& other) const {
    return !(other < *this);
}

bool Complex::operator>=(const Complex& other) const {
    return !(*this < other);
}

// ===== LOGICAL OPERATORS =====

bool Complex::operator!() const {
    return (*real == 0 && *imag == 0);
}

Complex::operator bool() const {
    return (*real != 0 || *imag != 0);
}

// ===== SUBSCRIPT OPERATOR =====

double& Complex::operator[](int index) {
    if (index == 0) return *real;
    else if (index == 1) return *imag;
    else throw out_of_range("Index must be 0 or 1");
}

const double& Complex::operator[](int index) const {
    if (index == 0) return *real;
    else if (index == 1) return *imag;
    else throw out_of_range("Index must be 0 or 1");
}

// ===== TYPE CONVERSION =====

Complex::operator double() const {
    return *real;
}

// ===== DISPLAY =====

void Complex::display() const {
    cout << *real;
    if (*imag >= 0) cout << " + ";
    else cout << " - ";
    cout << abs(*imag) << "i" << endl;
}

// ===== STREAM OPERATORS =====

ostream& operator<<(ostream& os, const Complex& c) {
    os << c.getReal();
    if (c.getImag() >= 0) os << " + ";
    else os << " - ";
    os << abs(c.getImag()) << "i";
    return os;
}

istream& operator>>(istream& is, Complex& c) {
    double r, i;
    cout << "Enter real part: ";
    is >> r;
    cout << "Enter imaginary part: ";
    is >> i;
    c.setReal(r);
    c.setImag(i);
    return is;
}
