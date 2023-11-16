#include <iostream>


int main(){
    int rows, cols;
    int counter = 0;
    std::cin >> rows >> cols;
    int** matrix = new int*[rows];
    int** transp = new int*[cols];
    for (int r = 0; r < rows; ++r)
    {
        matrix[r] = new int[cols];
    }
    for (int c = 0; c < cols; ++c)
    {
        transp[c] = new int[rows];
    }
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            matrix[i][j] = counter;
            ++counter;
        }
    }
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            transp[j][i] = matrix[i][j];
        }
    }
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << '\n';
    }
    std::cout << '\n';
    for (int i = 0; i < cols; ++i)
    {
        for (int j = 0; j < rows; ++j)
        {
            std::cout << transp[i][j] << ' ';
        }
        std::cout << '\n';
    }
    for (int r = 0; r < rows; ++r)
    {
        delete[] matrix[r];
    }
    delete[] matrix;
    return 0;
}