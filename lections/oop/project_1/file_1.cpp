#include <iostream>
#include <math.h>
#include "mycomplex.h"


int main() {
    Complex x;
    x.print();
    x.set(3, 2);
    x.print();
    std::cout << "x = " << x << std::endl;
    Complex x1;
    x1 = x.conj();
    std::cout << "x1 = " << x1 << std::endl;
    std::cout << "abs(x1) = " << x1.abs() << std::endl;
    std::cout << "abs(conj(x)) = " << x.conj().abs() << std::endl;
    const Complex y(1, -4); // = {1, -4};
    /*y.print();
    std::cout << "y = " << y << std::endl;
    Complex y(-1, 5);*/
    Complex z = Complex(2) + y;
    std::cout << "z = " << z << std::endl;
    try {
        z = Complex(1, -1) / (x - y);
        std::cout << "z = " << z << std::endl;
    } catch (const char* error) {
        std::cout << "Error: " << error << std::endl;
    }
    return 0;
}