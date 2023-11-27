#include <iostream>
#include <fstream>


int** MatrixFromFile(const char* path, int& rows, int& cols) {
    std::ifstream input(path);
    if (!input.is_open()) {
        throw "file opening error";
    }
    int** matrix = new int*[rows];
    input >> rows >> cols;
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
        for (int j = 0; j < cols; ++j) {
            input >> matrix[i][j];
        }
    }
    return matrix;
}


void DeleteMatrix(int** matrix, int rows) {
    for (int r = 0; r < rows; ++r) {
        delete[] matrix[r];
    }
    delete[] matrix;
}


int main() {
    int rows;
    int cols;
    int** matrix;
    try {
        matrix = MatrixFromFile("in.txt", rows, cols);
        DeleteMatrix(matrix, rows);
    } catch(const char* error) {
        std::cout << "Error message: " << error << '\n';
        return 1;
    }
    std::ofstream out("out.txt");
    if (!out.is_open()) {
        ;
    }
    out << 1 << ' ' << 2 << '\n';
    return 0;
}