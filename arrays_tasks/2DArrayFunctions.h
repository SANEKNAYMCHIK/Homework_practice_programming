//include guard
#ifndef __2D_ARRAY_FUNCTION_H__ //Благодаря этому будем определять все в этом файле только один раз
#define __2D_ARRAY_FUNCTION_H__
int& max_ref(int** matrix, int rows, int cols);
static int max_width = 20; //В каждом файле, где используем эту переменную, будет своя копия, 
//т.е. у каждого файла своя такая локальная перемнная со своим значением
extern int max_global = 10; //Одна и та же переменная, объявленная на глобальном уроыне для всех файлов, 
//т.е. меняем в одном файле, отображается и в другом тоже
double sqr(double x) {
    return x * x;
}
//можно объявить как static double или inline double, что-то вроде, как и с static и extern
#endif 