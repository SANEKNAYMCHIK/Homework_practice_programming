#include <iostream>


int main(){
    int n;
    std::cin >> n;
    double ans = 0;
    int pow_num = 1;
    for (int i = 0; i <= n; ++i)
    {
        ans += (1.0 / pow_num);
        pow_num *= 2;
    }
    std::cout << ans;
    
}