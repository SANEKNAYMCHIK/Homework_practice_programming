#include <iostream>


int main(){
    int n;
    std::cin >> n;
    double ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        ans += (1.0 / i);
    }
    std::cout << ans;
    
}