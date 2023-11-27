#include <iostream>
#include <ctime>
#include "2DArrayFunctions.h"


int main() {
    srand(time(nullptr));
    int rows, cols;
    std::cin >> rows >> cols;
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = rand() % 100;
        }
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << '\n';
    }
    std::cout << max_ref(matrix, rows, cols);
    for (int r = 0; r < rows; ++r) {
        delete[] matrix[r];
    }
    delete[] matrix;
    return 0;
}
