#include <iostream>
#include <cmath>


int main(){
    int n;
    double x;
    std::cin >> n;
    std::cin >> x;
    double ans = sin(x);
    double sins = sin(x);
    for (int i = 1; i < n; ++i)
    {
        sins = sin(sins);
        ans += sins;
    }
    std::cout << ans;
    
}