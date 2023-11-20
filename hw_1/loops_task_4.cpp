#include <iostream>


int main(){
    int height, amount;
    std::cin >> height >> amount;
    int width = 1 + 2 * (height - 1);
    int cur_space = (width - 1) / 2 + 1;
    for (int i = 0; i <= (2 * height - 1); ++i)
    {
        (i < height) ? (--cur_space):(++cur_space);
        for (int j = 0; j < 4 * width - cur_space; ++j)
        {
            for (int k = 0; k < width; ++k)
            {
                if ((j < cur_space) || (j > width - cur_space)){
                    std::cout << ' ';
                } else {
                    std::cout << '*';
                }
            }
        }
        std::cout << '\n';
    }
    
    return 0;
}