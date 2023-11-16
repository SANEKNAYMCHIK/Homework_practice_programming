#include <iostream>


int main(){
    int n;
    int shift;
    std::cin >> n;
    std::cin >> shift;
    shift %= n;
    int* arr = new int[n];
    for (int i = 0; i < n; ++i)
    {
        arr[i] = i;
    }
    for (int i = 0; i < n / 2; ++i)
    {
        std::swap(arr[i], arr[n - i - 1]);
    }
    for (int i = 0; i < (n - shift) / 2; ++i)
    {
        std::swap(arr[i], arr[n - shift - i - 1]);
    }
    for (int l = (n - shift), int r = n - 1; l < r; ++l, --r) //?
    {
        std::swap(arr[l], arr[r]);
    }
    for (int i = 0; i < n; ++i)
    {
        std::cout << arr[i] << ' ';
    }
    
    std::cout << '\n';
    delete[] arr;
    return 0;
}