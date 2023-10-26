#include <iostream>


int main(){
    double pi = 0;
    double cur_var;
    double eps;
    std::cin >> eps;
    int n = 0;
    int ind = 1;
    int st = 1;
    while (true)
    {
        cur_var = (1.0 / ind);
        if (cur_var < eps)
        {
            break;
        }
        ++n;
        ind += 2;
        pi += (st * cur_var);
        st *= -1;
    }
    pi *= 4;
    std::cout << pi << " " << n;
    return 0;
}