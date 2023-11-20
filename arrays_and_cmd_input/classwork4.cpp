#include <iostream>


int main(){
    const int w = 10;
    const int h = 5;
    int arr[h][w];
    int counter = 1;
    bool flag_1 = true;
    bool flag_2 = true;
    int j;
    for (int i = 0; i < h; ++i)
    {
        if (flag_1)
        {
            if (flag_2)
            {
                j = i;
            } else {
                j = h - 1;
            }
        } else {
            if (flag_2) {
                j = 0;
            } else {
                j = w - 1;
            }
        }
        while ((((counter % w) != 0) && (flag_1 == false)) && (((counter % h) != 0) && (flag_1 == true)))
        {
            if (flag_1)
            {
                arr[j][i] = counter;
            } else {
                arr[i][j] = counter;
            }
            ++counter;
            if (flag_2) 
            {
                ++j;
            } else {
                --j;
            }
        }
        if (flag_2 == true)
        {
            flag_2 = false;
        } else {
            flag_2 = true;
        }
        
    }
    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            std::cout << arr[i][j] << ' ';
        }
        std::cout << '\n';
    }
    return 0;
}