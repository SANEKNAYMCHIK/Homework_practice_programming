#include <iostream>
#include <fstream>


int getFileSize(const char* path) {
    std::ifstream in(path, std::ios_base::binary);
    if (!in) {
        return -1;
    }
    in.seekg(0, std::ios_base::end);
    /*int file_size = in.tellg(); //размер файла
    in.seekg(0, std::ios_base::beg); //перемещение в начало файла
    in.clear();*/
    return in.tellg();
}


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
    int file_size = getFileSize("in.txt");
    char* output = new char[file_size];
    while (in.peek() != EOF) {
        char c = in.get();
        if (c >= 'A' && c <= 'Z') {
            c += 32;
            out.put(c);
        }
    }
    return 0;
}