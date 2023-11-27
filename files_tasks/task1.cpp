#include <iostream>
#include <fstream>


int main() {
    std::ifstream in("in.txt");
    if (!in) {
        std::cout << "Failed to open file\n";
        return 1;
    }
    std::ofstream out("out.txt");
    if (!out) {
        std::cout << "Failed to open output!\n";
        return 2;
    }
    bool flag = true;
    while (in.peek() != EOF) {
        char c = in.get();
        if (c == '$') {
            if (flag) {
                out << "<math>";
            } else {
                out << "</math>";
            }
            flag = !flag;
            if (in.peek() == '$')
                //in.seekg(2, std::ios_base::cur);
                //in.get();
                in.ignore();
        } 
        else {
            out.put(c);
        }
    }
    return 0;
}