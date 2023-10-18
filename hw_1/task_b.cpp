#include <iostream>
#include <cmath>


int main(){
    double a, b, c, d;
    std::cin >> a >> b >> c;
    d = (b * b) - 4 * a * c;
    if (d > 0)
    {
        double x1, x2;
        x1 = ((-b) + sqrt(d)) / 2 * a;
        x2 = ((-b) - sqrt(d)) / 2 * a;
        std::cout << "2 корня, равные: ";
        std::cout << x1 << " и " << x2;
    } else if (d == 0) {
        std::cout << "Два одинаковых корня равные: ";
        std::cout << (-b) /  (2 * a);
    } else {
        std::cout << "Решений нет;-(";
    }
    return 0;
}