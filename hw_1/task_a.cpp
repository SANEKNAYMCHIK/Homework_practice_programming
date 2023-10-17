#include <iostream>


int main(){
    int a, b, x, c, d;
    double ans;
    std::cin >> a >> b >> x >> c >> d;
    ans = 1.0 * ((x - a) * (d - c)) / (b - a);
    std::cout << ans;
    return 0;
}