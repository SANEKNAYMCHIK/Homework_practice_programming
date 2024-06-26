#include "stroka.h"


stroka::stroka(const char* str="") {
    size_ = strlen(str) + 1;
    data_ = new char[size_];
    memcpy(data_, str, size_);
}
stroka::stroka(const stroka& other) {
    size_ = other.size_;
    data_ = new char[size_];
    memcpy(data_, other.data_, size_);
}
stroka::stroka(size_t N) {
    size_ = N + 1;
    data_ = new char[size_];
    data_[0] = '\0';
}
stroka::~stroka() {
    delete[] data_;
}
stroka& stroka::operator=(const stroka& other) {
    if (this != &other) {
        /*delete[] data_;
        size_ = other.size_;
        data_ = new char[size_];
        memcpy(data_, other.data_, size_);*/
        stroka tmp(other);
        swap(tmp);
    }
    return *this;
}


stroka& stroka::operator+=(const stroka& other) {
    size_t len1 = length();
    size_t len2 = other.length();
    if (len1 + len2 + 1 > size_) {
        char *tmp = new char[len1 + len2 + 1];
        memcpy(tmp, data_, len1);
        delete[] data_;
        data_ = tmp;
        size_ = len1 + len2 + 1;
    }
    memcpy(data_ + len1, other.data_, len2 + 1);
    return *this;
}

stroka operator+(const stroka& left, const stroka& right) {
    stroka result(left);
    result += right;
    return result;
}       


inline char stroka::operator[](size_t index) const {
    if (index >= size_) {
        throw "Out of string limits";
    }
    return data_[index];
}


bool operator==(const stroka& left, const stroka& right) {
    return strcmp(left.str(), right.str()) == 0;
}
bool operator!=(const stroka& left, const stroka& right) {
    return !(left == right);
    //return strcmp(left.str(), right.str()) != 0;
}
bool operator<(const stroka& left, const stroka& right) {
    return 1;
}


#include <iostream>
std::ostream& operator<<(std::ostream& out, const stroka& X) {
    out << X.str();
    return out;
}