#include <iostream>


int main(){
    int n;
    double ans;
    std::cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; ++i)
    {
        arr[i] = rand()%n;
    }
    for (int i = 0; i < n; ++i)
    {
        ans += (arr[i] * 1.0 / n);
    }
    for (int i = 0; i < n; ++i)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
    delete[] arr;
    std::cout << ans;
    return 0;
}