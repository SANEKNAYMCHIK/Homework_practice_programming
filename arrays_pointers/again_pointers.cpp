#include <iostream>


int main() {
    int x = 3;
    int *px = &x;
    int &rx = x;
    *px = 5;
    &rx;
    const int &cx = x; // Ссылка на x, но через нее нельзя записывать
    const int y = 0; //Задаем константу
    int &ry = y; //Выдаст ошибку компиляции, так как неконстантная ссылка на константу
    //
    int z;
    px = &z;
    const int *cpz = &z;
    *cpz = 3; //Wrong
    cpz = &x;
    const int * const ccz = &z; //Константный указатель на константу / Constant pointer on constant variable | Читать справа налево
    *ccz = 3; //Wrong
    ccz = &x; //Wrong
    return 0;
}