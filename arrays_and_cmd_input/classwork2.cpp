#include <iostream>
#include <ctime>


int main(){
    srand(time(nullptr));
    int a = 3;
    int b = 10;
    const int SIZE = 10;
    int arr[SIZE] = {};
    //Заполняем массив рандомными значениями
    for (int idx = 0; idx < SIZE; ++idx)
    {
        arr[idx] = a + rand() % (b - a + 1);
    }
    for (int idx = 0; idx < SIZE; ++idx)
    {
        std::cout << arr[idx] << ' ';
    }
    std::cout << '\n';
    int minIdx = 0;
    int maxIdx = 0;
    //Пишем свою функцию нахождения минимума и максимума
    for (int idx = 0; idx < SIZE; ++idx)
    {
        if (arr[idx] < arr[minIdx])
        {
            minIdx = idx;
        }
        if (arr[idx] > arr[maxIdx])
        {
            maxIdx = idx;
        }
    }
    //Два варианта как поменять два элемента местами
    std::swap(arr[minIdx], arr[maxIdx]);
    /*int tmp = arr[minIdx];
    arr[minIdx] = arr[maxIdx];
    arr[maxIdx] = tmp;*/
    for (int idx = 0; idx < SIZE; ++idx)
    {
        std::cout << arr[idx] << ' ';
    }
    std::cout << '\n';
    return 0;
}