#include <iostream>
#include <cstring>
#include <fstream>
#include <string>


bool StartWith(const char* s1, const char* s2) {
    int len_s1 = strlen(s1);
    int len_s2 = strlen(s2);
    if (len_s1 < len_s2)
        return false;
    for (int i = 0; i < len_s2; ++i) {
        if (s1[i] != s2[i])
            return false;
    }
    return true;
}


void grep(const char* s, const char* file) {
    int counter = 0;
    char line[64];
    std::ifstream in(file);
    while (in.peek() != EOF) {
        ++counter;
        in.getline(line, 64);
        int len_str = strlen(line);
        for (int i = 0; i < len_str; i++) {
            if (StartWith(line+i, s))
                std::cout << counter << ' ' << i + 1 << '\n';
        }
    }
}


int main(int argc, char* argv[]) {
    char* input = argv[1];
    char* inp_str = argv[2];
    grep(inp_str, input);
    return 0;
}