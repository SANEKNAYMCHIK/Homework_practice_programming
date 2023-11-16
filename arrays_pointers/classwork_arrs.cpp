#include <iostream>


int main(){
    int n;
    std::cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; ++i)
    {
        arr[i] = i;
    }
    for (int i = 0; i < n / 2; ++i)
    {
        std::cout << arr[i] << ' ';
        std::cout << arr[n - i - 1] << ' ';
    }
    if (n % 2 == 1)
    {
        std::cout << arr[n/2];
    }
    std::cout << '\n';
    delete[] arr;
    return 0;
}