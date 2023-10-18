#include <iostream>
#include <cmath>


int main(){
    double x, y, r, R;
    std::cin >> x >> y >> r >> R;
    if (((pow(x, 2) + pow(y, 2)) > pow(r, 2)) && ((pow(x, 2) + pow(y, 2)) < pow(R, 2))){
        std::cout << "Точка попала, ура!";
    } else {
        std::cout << "К сожалению, точка не попала:(";
    }
    return 0;
}