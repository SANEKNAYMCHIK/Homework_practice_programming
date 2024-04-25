#include <iostream>


int main() {
    try {
        int a = 5;
        int b = 0;
        int k =  (a / b);
    } catch (...) {
        std::cout << "error";
    }
    return 0;
}