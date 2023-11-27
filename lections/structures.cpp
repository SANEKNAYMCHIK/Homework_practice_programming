#include <iostream>


struct complex {
    double re;
    double im;
    char ch;
};


void print(const complex &x) {
    std::cout << x.re;
    if (x.im >= 0)
        std::cout << "+ ";
    std::cout << x.im << "i";
}


std::ostream& operator <<(std::ostream& out, const complex& x) {
    out << x.re;
    if (x.im >= 0)
        out << "+";
    out << x.im << "i";
    return out;
}


complex operator+(const complex &x, const complex &y) {
    complex z;
    z.re = x.re + y.re;
    z.im = x.im + y.im;
    return z;
}


void print(const complex M[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << M[i] << std::endl;
    }
}



int main() {
    complex x;
    complex y = {-5.4, -6.7};
    x.re = 2;
    x.im = 4;
    print(x);
    std::cout << "\n";
    std::cout << x << "\n";
    print(y);
    std::cout << "\n";
    std::cout << "x + y = " << x + y << "\n";
    //x+y
    //operator+(x,y)

    complex M[3] = {{1, 2}, {-4, 2.1}};
    print(M, 3);


    /*struct {
        int a;
        int b;
        char ch;
        double M[4];
    } X, Y, *p, S[10];

    struct {
        int a;
        int b;
        char ch;
        double M[4];
    } Z;

    X = Y;
    X = Z; // Разные структуры, поэтому так нельзя

    X.a = 1;
    X.b = 2;
    X.ch = 'x';
    X.M[0] = 1.2;
    X.M[1] = -0.3;

    Y.a = 2;
    Y.b = 1;
    Y.ch = 'y';
    Y.M[0] = 4.3;

    p = &X;

    //(*p).a = 3;
    p -> a = 3; // То же самое, что и запись выше || The same, that wrote higher

    p = &Y;
    p -> b = 5;

    S[0].a = 5;
    S[0].M[3] = 5.6;*/
    return 0;
}