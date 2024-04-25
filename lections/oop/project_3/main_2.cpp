#include <iostream>
#include <fstream>
#include "dictpairs.h"
#include "array.h"


int main() {
    /*stroka str("Hello");
    stroka str2("world");
    std::cout << str + " " + str2 + "!" << std::endl;*/
    const char fname[] = "dict.txt";
    std::ifstream inFile(fname);
    if (!inFile) {
        std::cout << "Can't open the file: " << fname << std::endl;
        return 1;
    }
    Array<dictPara> Dictionary;
    dictPara X;
    int cnt = 0;
    while (inFile.peek() != EOF) {
        inFile >> X;
        Dictionary.push_back(X);
        ++cnt;
    }
    inFile.close();
    std::cout << "Total: " << cnt << std::endl;
    dictPara what("bus", "");
    for (size_t i = 0; i < Dictionary.size(); ++i) {
        if (Dictionary[i] == what) {
            std::cout << Dictionary[i];
        }
    }
    return 0;
}