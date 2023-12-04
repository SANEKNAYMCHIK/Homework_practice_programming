#include <iostream>


int getInt(std::istream& in) {
    int tmp = 0;
    in >> tmp;
    if (!in.good()) {
        in.clear();
        tmp = 0;
    }
    in.ignore();
    return tmp;
}