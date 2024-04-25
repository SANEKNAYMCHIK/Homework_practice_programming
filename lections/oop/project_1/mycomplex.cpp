#include "mycomplex.h"


std::ostream& operator<< (std::ostream& out, const Complex& x) {
    out << x.re();
    if (x.im() < 0) {
            std::cout << x.im() << "i";
    } else {
            std::cout << "+" << x.im() << "i";
    }
    return out;
}


void Complex::print() const {
    std::cout << (*this).real;
    if (imag < 0) {
        std::cout << imag << "i";
    } else {
        std::cout << "+" << imag << "i";
    }
    std::cout << std::endl;
}


Complex::Complex(double real, double im) : real(real), imag(im) {
        std::cout << "new " << *this << std::endl;
        /*this -> real = real;
        this -> imag = imag;*/
}


inline double Complex::im() const {return imag;}


Complex::~Complex() {
    std::cout << "Kill " << *this << std::endl;
    //(*this).print();
    //print();
}