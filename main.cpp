// ============================================
// Complex.h - Header File
// ============================================
#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
#include <cmath>

class Complex {
private:
    double real;
    double imag;

public:
    // Constructor: Can create complex numbers in different ways
    // Complex() creates 0+0i
    // Complex(5) creates 5+0i (only real part)
    // Complex(3, 4) creates 3+4i (both parts)
    Complex(double r = 0, double i = 0) {
        real = r;
        imag = i;
    }

    // Copy Constructor: Makes a copy of another Complex number
    Complex(const Complex& other) {
        real = other.real;
        imag = other.imag;
    }

    // Assignment Operator: c1 = c2
    Complex& operator=(const Complex& other) {
        real = other.real;
        imag = other.imag;
        return *this;
    }

    // Get the real part
    double getReal() const {
        return real;
    }

    // Get the imaginary part
    double getImag() const {
        return imag;
    }

    // Set the real part
    void setReal(double r) {
        real = r;
    }

    // Set the imaginary part
    void setImag(double i) {
        imag = i;
    }

    // Add two complex numbers: (a+bi) + (c+di) = (a+c) + (b+d)i
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // Add real number to complex: (a+bi) + c = (a+c) + bi
    Complex operator+(double value) const {
        return Complex(real + value, imag);
    }

    // Subtract two complex numbers
    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    // Subtract real number from complex
    Complex operator-(double value) const {
        return Complex(real - value, imag);
    }

    // Multiply two complex numbers: (a+bi)(c+di) = (ac-bd) + (ad+bc)i
    Complex operator*(const Complex& other) const {
        double newReal = real * other.real - imag * other.imag;
        double newImag = real * other.imag + imag * other.real;
        return Complex(newReal, newImag);
    }

    // Multiply complex by real number
    Complex operator*(double value) const {
        return Complex(real * value, imag * value);
    }

    // Divide two complex numbers
    Complex operator/(const Complex& other) const {
        double denominator = other.real * other.real + other.imag * other.imag;
        if (denominator == 0) {
            std::cout << "Error: Division by zero!" << std::endl;
            return Complex(0, 0);
        }
        double newReal = (real * other.real + imag * other.imag) / denominator;
        double newImag = (imag * other.real - real * other.imag) / denominator;
        return Complex(newReal, newImag);
    }

    // Divide complex by real number
    Complex operator/(double value) const {
        if (value == 0) {
            std::cout << "Error: Division by zero!" << std::endl;
            return Complex(0, 0);
        }
        return Complex(real / value, imag / value);
    }

    // Compound assignment: c1 += c2 (add and store result in c1)
    Complex& operator+=(const Complex& other) {
        real += other.real;
        imag += other.imag;
        return *this;
    }

    // Compound assignment: c1 += 5
    Complex& operator+=(double value) {
        real += value;
        return *this;
    }

    // Compound assignment: c1 -= c2
    Complex& operator-=(const Complex& other) {
        real -= other.real;
        imag -= other.imag;
        return *this;
    }

    // Compound assignment: c1 *= c2
    Complex& operator*=(const Complex& other) {
        double newReal = real * other.real - imag * other.imag;
        double newImag = real * other.imag + imag * other.real;
        real = newReal;
        imag = newImag;
        return *this;
    }

    // Unary minus: -c gives negative of complex number
    Complex operator-() const {
        return Complex(-real, -imag);
    }

    // Check if two complex numbers are equal
    bool operator==(const Complex& other) const {
        return (real == other.real) && (imag == other.imag);
    }

    // Check if two complex numbers are not equal
    bool operator!=(const Complex& other) const {
        return !(*this == other);
    }

    // Calculate magnitude (absolute value): |a+bi| = sqrt(a² + b²)
    double magnitude() const {
        return std::sqrt(real * real + imag * imag);
    }

    // Calculate argument (angle in radians)
    double argument() const {
        return std::atan2(imag, real);
    }

    // Get conjugate: conjugate of (a+bi) is (a-bi)
    Complex conjugate() const {
        return Complex(real, -imag);
    }

    // Print the complex number
    void print() const {
        if (imag >= 0)
            std::cout << real << " + " << imag << "i";
        else
            std::cout << real << " - " << -imag << "i";
    }
};

// These functions allow: real_number + complex_number
// For example: 5 + c1

Complex operator+(double value, const Complex& c) {
    return c + value;
}

Complex operator-(double value, const Complex& c) {
    return Complex(value - c.getReal(), -c.getImag());
}

Complex operator*(double value, const Complex& c) {
    return c * value;
}

Complex operator/(double value, const Complex& c) {
    double denom = c.getReal() * c.getReal() + c.getImag() * c.getImag();
    if (denom == 0) {
        std::cout << "Error: Division by zero!" << std::endl;
        return Complex(0, 0);
    }
    return Complex(value * c.getReal() / denom, -value * c.getImag() / denom);
}

#endif

int main() {
    std::cout << "=== Creating Complex Numbers ===" << std::endl;
    Complex c1;              // 0 + 0i (default)
    Complex c2(5);           // 5 + 0i (only real part)
    Complex c3(3, 4);        // 3 + 4i (both parts)
    Complex c4(0, 2);        // 0 + 2i (only imaginary part)

    std::cout << "c1 = "; c1.print(); std::cout << std::endl;
    std::cout << "c2 = "; c2.print(); std::cout << std::endl;
    std::cout << "c3 = "; c3.print(); std::cout << std::endl;
    std::cout << "c4 = "; c4.print(); std::cout << std::endl;

    std::cout << "\n=== Copy Constructor ===" << std::endl;
    Complex c5(c3);  // Copy c3 into c5
    std::cout << "c5 = "; c5.print(); std::cout << std::endl;

    std::cout << "\n=== Basic Operations ===" << std::endl;
    std::cout << "c3 + c2 = "; (c3 + c2).print(); std::cout << std::endl;
    std::cout << "c3 - c2 = "; (c3 - c2).print(); std::cout << std::endl;
    std::cout << "c3 * c2 = "; (c3 * c2).print(); std::cout << std::endl;
    std::cout << "c3 / c2 = "; (c3 / c2).print(); std::cout << std::endl;

    std::cout << "\n=== Operations with Real Numbers ===" << std::endl;
    std::cout << "c3 + 10 = "; (c3 + 10).print(); std::cout << std::endl;
    std::cout << "10 + c3 = "; (10 + c3).print(); std::cout << std::endl;
    std::cout << "c3 * 2 = "; (c3 * 2).print(); std::cout << std::endl;
    std::cout << "2 * c3 = "; (2 * c3).print(); std::cout << std::endl;

    std::cout << "\n=== Compound Assignment ===" << std::endl;
    Complex c6(10, 5);
    std::cout << "c6 = "; c6.print(); std::cout << std::endl;
    c6 += 3;
    std::cout << "After c6 += 3: "; c6.print(); std::cout << std::endl;
    c6 -= Complex(1, 1);
    std::cout << "After c6 -= (1+1i): "; c6.print(); std::cout << std::endl;

    std::cout << "\n=== Other Operations ===" << std::endl;
    std::cout << "-c3 = "; (-c3).print(); std::cout << std::endl;
    std::cout << "Magnitude of c3 = " << c3.magnitude() << std::endl;
    std::cout << "Conjugate of c3 = "; c3.conjugate().print(); std::cout << std::endl;

    return 0;
}
