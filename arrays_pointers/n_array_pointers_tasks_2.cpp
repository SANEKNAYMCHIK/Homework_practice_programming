#include <iostream>
#include <ctime>


int main(){
    srand(time(nullptr));
    int rows, cols;
    int val= 0;
    int max_val = 0;
    std::cin >> rows >> cols;
    int* len = new int[cols];
    int** matrix = new int*[rows];
    int** cur_len = new int*[rows];
    for (int r = 0; r < rows; ++r) {
        matrix[r] = new int[cols];
        cur_len[r] = new int[cols];
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = ((double)rand() / RAND_MAX) * 1000000;
            val += matrix[i][j];
            while (val > 0) {
                max_val += 1;
                val /= 10;
            }
            if (max_val > len[j]) {
                len[j] = max_val;
            }
            cur_len[i][j] = max_val;
            val = 0;
            max_val = 0;
        }
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << matrix[i][j];
            for (int k = 0; k < (len[j] - cur_len[i][j] + 1); ++k) {
                std::cout << ' ';
            }
        }
        std::cout << '\n';
    }
    for (int r = 0; r < rows; ++r)
    {
        delete[] matrix[r];
    }
    delete[] matrix;
    delete[] len;
    delete[] cur_len;
    return 0;
}