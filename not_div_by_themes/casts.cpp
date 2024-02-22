#include <iostream>


int main() {
    /* static_cast - логическое преобразование (меняем значение) int y = (int) 1.5;
    const_cast:
    float y = 0.5;
    const float& ry = y;
    float& z = const_cast<float&>(ry);
    z = 5; - const_cast снял ограничение const на переменную, теперь можем ее изменять
    reinterpret_cast - int x = reinterpret_cast<int&>(0.5); - берем те же самые биты, что и вл float. но смотрим на них просто как на int
    dynamic_cast - что-то с классами
    */
    return 0;
}