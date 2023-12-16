#include <iostream>


union bytecod {
    unsigned char x;
    struct {
        unsigned char a0: 1;
        unsigned char a1: 1;
        unsigned char a2: 1;
        unsigned char a3: 1;
        unsigned char a4: 1;
        unsigned char a5: 1;
        unsigned char a6: 1;
        unsigned char a7: 1;
    } byte;
};


std::ostream& operator<< (std::ostream& out, const bytecod& B) {
    out << (int) B.byte.a7;
    out << (int) B.byte.a6;
    out << (int) B.byte.a5;
    out << (int) B.byte.a4;
    out << (int) B.byte.a3;
    out << (int) B.byte.a2;
    out << (int) B.byte.a1;
    out << (int) B.byte.a0;
    return out;
}


union cod32 {
    int x;
    bytecod b[4];

};


union codDouble {
    double d;
    cod32 X[2];
};


std::ostream& operator<< (std::ostream& out, const cod32& C) {
    out << C.x << ": ";
    for (int i = 3; i > -1; --i) {
        out << (int) C.b[i].x << '.';
    }
    out << ": ";
    for (int i = 3; i > -1; --i) {
        out << C.b[i] << '.';
    }
    return out;
}


int main() {
    bytecod S;
    for (S.x = 0; S.x < 32; ++S.x) {
        std::cout << (int)S.x << ": " << S << std::endl;
    }
    cod32 C;
    for (C.x = 0; C.x < 3200; ++C.x) {
        std::cout << C << std::endl;
    }
    
    return 0;
}







/*union BI {
    int x;
    unsigned char b[4];
};


int main() {
    BI a;
    std::cout << sizeof(a) << std::endl;
    a.x = 0;
    std::cout << (int) a.b[0] << ". ";
    std::cout << (int) a.b[1] << ". ";
    std::cout << (int) a.b[2] << ". ";
    std::cout << (int) a.b[3] << ". " << std::endl;
    a.b[0] = 255;
    a.b[1] = 255;
    std::cout << a.x << ": ";
    std::cout << (int) a.b[0] << ". ";
    std::cout << (int) a.b[1] << ". ";
    std::cout << (int) a.b[2] << ". ";
    std::cout << (int) a.b[3] << ". " << std::endl;
}*/