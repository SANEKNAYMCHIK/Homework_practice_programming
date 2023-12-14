#include <iostream>


bool check(const char* str) {
    int a = 0;
    int i = 0;
    while (str[i] != '\0') {
        a += ((str[i++] == '(') ? 1 : -1);
        if (a < 0) {
            break;
        }
    }
    return a == 0;
}


bool unitTest() {
    bool total = true;
    bool empty_str = (check("") == true);
    total = total && empty_str;
    bool simple_str = (check("()") == true);
    total = total && simple_str;
    bool simple_wrong = (check(")(") == false);
    total = total && simple_wrong;
    bool open_only = (check("(") == false);
    total = total && open_only;
    bool close_only = (check(")") == false);
    total = total && close_only;
    bool too_many_open = (check("(()") == false);
    total = total && too_many_open;
    bool too_many_close = (check("())") == false);
    total = total && too_many_close;
    bool nested = (check("(())") == true);
    total = total && nested;
    bool sequence = (check("()()") == true);
    total = total && sequence;
    if (total) {
        std::cout << "TESTS OK\n";
    } else {
        std::cout << "TESTS FAILED\n";
    }
    
}


int main() {
    unitTest();
    return 0;
}