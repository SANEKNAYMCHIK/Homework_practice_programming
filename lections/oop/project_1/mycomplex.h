#ifndef _MYCOMPLEX24_
#define _MYCOMPLEX24_
#include <iostream>

//class Complex;
//std::ostream& operator<< (std::ostream& out, const Complex& x);


class Complex {
    double real;
    double imag;
public:
    Complex(double real = 0, double im = 0);
    Complex(const Complex& x) : real(x.real), imag(x.imag) {
        std::cout << "copy "; print();std::cout << std::endl;
    }
    /*void print() const {
        std::cout << (*this).real;
        if (imag < 0) {
            std::cout << imag << "i";
        } else {
            std::cout << "+" << imag << "i";
        }
        std::cout << std::endl;
    }*/
    void print() const;
    double re() const {return real;}
    double im() const;
    double abs() const {return sqrt(real * real + imag * imag);}
    Complex conj() const {
        return Complex(real, -imag);
    }
    void set(double real, double imag) {
        (*this).real = real;
        this -> imag = imag;
    }

    Complex operator+(const Complex& right) const {
        return Complex(real + right.real, imag + right.imag);
    }

    Complex operator-(const Complex& right) const {
        return Complex(real - right.real, imag - right.imag);
    }

    Complex operator*(const Complex& right) const {
        Complex tmp(*this);
        tmp *= right;
        return tmp;
        //return Complex(real * right.real - imag * right.imag, real * right.imag + imag * right.real);
    }

    Complex operator/(const Complex& right) const {
        Complex tmp = ~right;
        if (tmp.real == 0) {
            throw "Divide by zero";
        }
        Complex z = (*this) * right.conj();
        z.real /= tmp.real;
        z.imag /= tmp.imag;
        return z;
    }
    
    Complex& operator+=(const Complex& right) {
        real += right.real;
        imag += right.imag;
        return *this;
    }

    Complex& operator-=(const Complex& right) {
        real -= right.real;
        imag -= right.imag;
        return *this;
    }

    Complex& operator*=(const Complex& right) {
        double tmp = real * right.real - imag * right.imag;
        imag = real * right.imag + imag * right.real;
        real = tmp;
        return *this;
    }

    Complex& operator/=(const Complex& right) {
        (*this) = (*this) / right;
        return *this;
    }
    
    Complex operator~() const {
        return Complex(real, -imag);
    }

    //friend std::ostream& operator<< (std::ostream& out, Complex x);


    ~Complex();
};


/*Complex operator+(const Complex& x, const Complex& y) {
    return Complex(x.re() + y.re(), x.im() + y.im());
}*/

std::ostream& operator<< (std::ostream& out, const Complex& x);

#endif