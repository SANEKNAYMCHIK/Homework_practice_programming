#include <iostream>


bool stoopid(int x) {
    if (x == 1)
        return true;
}


int main() {
    if (stoopid(1) == 1)
        std::cout << "Yeey!\n";
    else
        std::cout << "Nope:/\n";
    if (stoopid(2) == 1)
        std::cout << "Yeey!\n";
    else
        std::cout << "Nope:/\n";
    return 0;
}
