#include <iostream>
#include <fstream>
#include <cstring>


int main(int argc, char* argv[]) {
    std::ifstream in(argv[2]);
    if (!in.is_open()) {
        std::cout << "Error!" << '\n';
        return 1;
    }
    std::ofstream out(argv[3]);
    if (!in.is_open()) {
        std::cout << "Error!" << '\n';
        return 1;
    }
    char* method = argv[1];
    int flag;
    if (strcmp(method, "left") == 0) {
        flag = 0;
    } else if (strcmp(method, "center") == 0) {
        flag = 1;
    } else if (strcmp(method, "right") == 0) {
        flag = 2;
    } else {
        std::cout << "Error!" << '\n';
        return 1;
    }
    char temp_vals[81] = {0};
    int temp_len;
    int inds;
    int ind1;
    int ind2;
    int spaces;
    int amount1;
    int amount2;
    int tabs;
    while (in.peek() != EOF) {
        in.getline(temp_vals, 81);
        temp_len = strlen(temp_vals);
        ind1 = 0;
        ind2 = temp_len - 1;
        for (int i = 0; i < temp_len; ++i) {
            if ((temp_vals[i] != ' ') && (temp_vals[i] != '\t')) {
                ind1 = i;
                break;
            }
        }
        for (int i = temp_len - 1; i > -1; --i) {
            if ((temp_vals[i] != ' ') && (temp_vals[i] != '\t')) {
                ind2 = i;
                break;
            }
        }
        for (int i = ind1; i < ind2  + 1; ++i) {
            if ((temp_vals[i] == '\t')) {
                ++tabs;
            }
        }
        temp_len = ind2 - ind1 + 1;
        temp_vals[ind2 + 1] = '\0';
        if (flag == 0) {
            out << (temp_vals + ind1);
        } else if (flag == 1) {
            if (temp_len % 2 == 0) {
                amount1 = (80 - temp_len) / 2;
                amount2 = (80 - temp_len) / 2;
            } else {
                amount1 = (80 - temp_len) / 2 + 1;
                amount2 = (80 - temp_len) / 2;
            }
            for (int i = 0; i < amount1; ++i) {
                out << ' ';
            }
            out << (temp_vals + ind1);
            for (int i = 0; i < amount2; ++i) {
                out << ' ';
            }
        } else {
            for (int i = 0; i < (80 - temp_len); ++i) {
                out << ' ';
            }
            out << (temp_vals + ind1);
        }
        out << '\n';
        memset(temp_vals, 0, 81);
    }
    in.close();
    out.close();
    return 0;
}