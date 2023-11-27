#include <iostream>
#include <cmath>

/* 1
int Sqrt(double val, double &res) {
    if (val < 0) {
        return 1;
    } 
    res = sqrt(val);
    return 0;
}*/


int Sqrt(double val, double &res) {
    if (val < 0) {
        throw "negative value!";
    }
    return sqrt(val);
}


double norm(double x, double y, double &res) {
    // 1
    /*if (x < 0 || y < 0)
        return 2;
    int err = Sqrt(x * x + y * y, res);
    return err;*/
    double res;
    return Sqrt(x * x + y * y, res);
}


int main() {
    return 0;
}