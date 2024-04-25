#include <iostream>


template <class T>
struct removeptr {
    typedef T type;
};


template <class T>
struct removeptr<T*>{
    //typedef T type;
    using type = typename removeptr<T>::type;
};


int main() {
    return 0;
}