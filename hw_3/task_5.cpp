#include <iostream>
#include <cmath>
#include <iomanip>


int main(){
    double x1;
    double x2;
    double dx;
    double eps;
    double ans = 0;
    int counter = 3;
    std::cin >> x1;
    std::cin >> x2;
    std::cin >> dx;
    std::cin >> eps;
    long long int fact = 1;
    for (double i = x1; i <= x2; i = i + dx)
    {
        ans += (1.0 * (pow(i, counter - 2)) / fact);
        fact *= (counter - 1);
        fact *= counter;
        counter += 2;
        std::cout << std::fixed;
        std::cout << std::setprecision(eps);
        std::cout << ans;
        std::cout << " " << sin(ans) << std::endl;
    }
    return 0;
}