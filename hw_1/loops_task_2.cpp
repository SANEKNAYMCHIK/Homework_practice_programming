#include <iostream>


int main(){
  int height;
  std::cin >> height;
  int width = 1 + 2 * (height - 1);
  int cur_space = (width - 1) / 2 + 1;
  for (int i = 1; i <= height; ++i)
  {
    cur_space--;
    for (int j = 0; j < width - cur_space; ++j)
    {
      std::cout << (j < cur_space ? ' ':'*');
    }
    std::cout << '\n';
  }
  
  return 0;
}