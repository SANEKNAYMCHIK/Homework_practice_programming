#include <iostream>


//Type - переменная, в которой хранится тип
template <typename Type>
void Swap(Type& a, Type& b) {
    Type tmp = a;
    a = b;
    b = tmp;
}


//template <class Left, class Right> - то же самое, что и строка ниже (typename и class - синонимы)
template <typename Left, typename Right>
double Sum(Left a, Right b) {
    return a + b;
}


template <int N>
double sumFirst(double* arr, int sz) {
    if (sz < N) {
        throw "too big N";
    }
    
    double sum = 0;
    for (int i = 0; i < N; ++i) {
        sum += arr[i];
    }
    return sum;
}


template <class T>
int countCalls(T val) {
    static int count = 0; //Не удаляется (глобальная перемнная)
    return ++count;
}


//Перегрузка ф-ии типом double
/*
void Swap(double& a, double& b) {
    int tmp = a;
    a = b;
    b = tmp;
}
*/


struct test {
    int v;
};


int main() {
    double x = 2;
    double y = 2;
    Swap<double>(x, y); //Явно указываем какой тип данных будет
    //Swap(x, y); //Неявно указываем какой тип данных будет
    int z = 2;
    test t1;
    test t2;
    Sum(x, y);
    Sum(y, z);
    //Sum(x, t1); - ошибка компиляции, так как у пользовательского типа данных(структуры) не задана операция сложения(то, как складывать эти элементы)
    double arr[] = {1, 2, 3};
    double sum = sumFirst<2>(arr, 3);
    countCalls(x);
    countCalls(t1);
    // верхние две строки создадут разные функции и каждая статическая переменная будет уникальной в своей функции,
    // то есть счетчик и там и там будет равен единице
    return 0;
}