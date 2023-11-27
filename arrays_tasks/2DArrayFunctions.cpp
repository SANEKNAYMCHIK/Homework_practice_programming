#include <iostream>
#include "2DArrayFunctions.h"


int& max_ref(int** matrix, int rows, int cols) {
    int max_r = 0;
    int max_c = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] > matrix[max_r][max_c]) {
                max_r = i;
                max_c = j;
            }
        }
    }
    return matrix[max_r][max_c];
}