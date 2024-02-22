#include <iostream>


int GLOBALX = 42;
int IntDynArray::static_val = 5;

struct IntDynArrayStruct {
    int size;
    int ptr;
    int* data;
};


class IntDynArray {
private:
    int m_size;
    int m_ptr;
    int* m_data;
    int& ref;
    const int const_val;
    void init(int size);
    static int static_val;
    //inline static int static_val;
public:
    // constructor
    IntDynArray(int size);
    // default constructor
    IntDynArray();
    //IntDynArray() = default;
    int& getElem(int idx);
    bool at(int idx, int& val);
    int getSize() const;
    void print() const;

    static void staticMethod() {
        std::cout << "Static method\n";
    }
};


IntDynArray::~IntDynArray() {
    delete[] m_data;
    m_data = nullptr;
    m_size = 0;
    m_ptr = 0;
}


// default constructor
IntDynArray::IntDynArray() : m_size(1), ref(GLOBALX), const_val(42) {
    init(1);
}


// constructor with size
IntDynArray::IntDynArray(int size) : ref(GLOBALX), const_val(42) {
    init(size);
}


void IntDynArray::init(int size) {
    m_data = new int[size]();
    m_size = size;
    m_ptr = 0;
}


int& IntDynArray::getElem(int idx) {
    if (idx < 0 || idx >= m_size) {
        throw std::range_error("list index out of range");
    }
    return this -> m_data[idx];
}


bool IntDynArray::at(int idx, int& val) {
    if (idx < 0 || idx >= m_size) {
        return false;
    }
    val = m_data[idx];
    return true;
}





int IntDynArray::getSize() const {
    return this -> m_size;
}


inline void IntDynArray::print() const {
    for (int i = 0; i < m_size; ++i) {
        std::cout << m_data[i] << ' ';
    }
    std::cout << '\n';
}


/*IntDynArrayStruct initArray(int size) {
    IntDynArrayStruct obj;
    obj.data = new int[size]();
    obj.size = size;
    obj.ptr = 0;
    return obj;
}


void deleteObj(IntDynArrayStruct& obj) {
    delete[] obj.data;
}*/


int main() {
    const IntDynArray obj_c;
    obj_c.getSize();
    IntDynArray obj(10);
    obj.getElem(5);
    obj.print();
    IntDynArray::staticMethod();
    return 0;
}