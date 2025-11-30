#include "complex.h"

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


    return 0;

}
