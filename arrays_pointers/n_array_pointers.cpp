#include <iostream>


int main(){
    int rows = 3;
    int cols = 4;
    int** matrix = new int*[rows];
    for (int r = 0; r < rows; ++r)
    {
        matrix[r] = new int[cols];
    }
    //matrix[1][2] = 5;
    for (int r = 0; r < rows; ++r)
    {
        delete[] matrix[r];
    }
    delete[] matrix;
    return 0;
}