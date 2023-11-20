#include <iostream>


int main(int argc, const char* argv[]){
    char str[] = "Hello";
    //Выводит на 1 больше, чем длина самой строки, потому что в конец дописывается еще один элемент
    //Обозначающий конец строки, а именно '\0'
    std::cout << sizeof(str) << '\n';
    std::cout << str << '\n';
    for (int idx = 0; idx < strlen(str) + 1; ++idx)
    {
        std::cout << (int)str[idx] << '\n';
    }
    //Так инициализируется массив символов, автоматически подставляя после строки '\0', потому что до него он будет выводить символы, 
    //А когда встретит '\0', то вывод закончится, это знак того, что уже конец строки
    char strBaza[] = {'h', 'e', 'l', 'l', 'o', '\0'};
    int strCodes[] = {104, 101, 108, 108, 111, 0};
    std::cout << strBaza << '\n';
    int sz = strlen(argv[1]);
    int val = 0;
    int deg = 1;
    for (int idx = 0; idx < sz; ++idx)
    {
        val += (argv[1][sz - idx - 1] - 48) * deg;
        deg *= 10;
    }
    std::cout << "Char Input: " << argv[1] << '\n';
    std::cout << "Converted int: " << val << '\n';

    char upper[] = "**-=FlUfFY PuPpY=-**";
    int idx = 0;
    //Переводим все символы в нижний регистр
    //Также еще есть функции tolower() и toupper(), которые также переводят элементы в нижний или верхний регистры
    while (upper[idx] != 0)
    {
        if (upper[idx] >= 'A' && upper[idx] <= 'Z')
        {
            upper[idx] += 'a' - 'A';
        }
        ++idx;
    }
    std::cout << upper << '\n';
    //Если из данных, введенных пользователем, то можно так
    //Размер указываем примерно максимально возможное значение
    char buf[32];
    std::cin >> buf; // ввод до первого элемента по типу (' ', '\n', '\r', '\t')
    std::cin.getline(buf, 32);// вводит все, что есть
    return 0;
}