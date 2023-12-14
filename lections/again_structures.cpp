#include <iostream>


struct A {
    unsigned char x : 3; //amount of memory in bits (3 bits), we can write size only for whole numbers
    unsigned char : 1;
    unsigned char y : 4; //amount of memory in bits (4 bits)
};

void print(const  A& a) {
    std::cout << (int) a.x << ", " << (int) a.y << std::endl;
}
int main() {
    A a;
    std::cout << "sizeof(A) = " << sizeof(a) << std::endl;
    a.x = 2;
    a.y = 5;
    print(a);
    return 0;
}