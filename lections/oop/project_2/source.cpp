#include <iostream>
#include <cstring>
#include <fstream>


class goods {
private:
    char *name_;
    double price_;
    static int counter;
    static double percent;
public:
    goods(const char *name="", double price=0.0) : price_(price) {
        size_t len = strlen(name)+1;
        name_ = new char[len];
        //strcpy(name_, name);
        strcpy_s(name_, len, name);
        ++counter;
    }
    goods(const goods& X) : price_(X.price_) {
        size_t len = strlen(X.name_)+1;
        name_ = new char[len];
        //strcpy(name_, X.name_);
        strcpy_s(name_, len, X.name_);
    }
    ~goods() {
        delete[] name_;
        --counter;
    }
    /*
    ~goods() {
        if (name_ != nullptr) {
            delete[] name_;
            name_ = nullptr;
        }
    }
    */

    goods& operator=(const goods& X) {
        if (this != &X) {
            price_ = X.price_;
            size_t len = strlen(X.name_)+1;
            delete[] name_;
            name_ = new char[len];
            //strcpy(name_, X.name_);
            strcpy_s(name_, len, X.name_);
        }
        return *this;
    }


    
    double getPrice() const {return price_ * (1.0 + percent);}
    double getRealPrice() const {return price_;}
    const char* getName() const {return name_;}
    static int total() {return counter;}
    static void setPercent(double p) {
        percent = (p < -1) ? -1.0 : p;
    }
};


int goods::counter = 0;
double goods::percent = 0.5;


std::ostream& operator<<(std::ostream& out, const goods& X) {
    out << X.getName() << ":\t" << X.getPrice();
}


std::istream& operator>>(std::istream& in, goods& X) {
    char tmp[1024];
    in.getline(tmp, 1024);
    double p;
    in >> p;
    X = goods(tmp, p);
    return in;
}


std::ofstream& operator<<(std::ofstream& out, goods& X) {
    out.write(X.getName(), strlen(X.getName()));
    out << X.getName() << std::endl;
    out << X.getRealPrice() << std::endl;
    return out;
}


void eat(goods A) {
    std::cout << " Eat: " << A.getName();
    std::cout << ", health+" << A.getRealPrice() << std::endl;
}


int main() {
    const int N = 5;
    goods shop[N] = {
        goods("apple", 30.0), 
        goods("orange", 45.0), 
        goods("pineapple", 100.0), 
        goods("banana", 24.0)
    };
    for (int i = 0; i < N; ++i) {
        std::cout << i + 1 << ". " << shop[i] << std::endl;
    }
    eat(shop[3]);
    shop[N - 1] = goods("tomato", 200.0);
    for (int i = 0; i < N; ++i) {
        std::cout << i + 1 << ". " << shop[i] << std::endl;
    }
    int i = 0, j = 4;
    shop[i] = shop[j];
    for (int i = 0; i < N; ++i) {
        std::cout << i + 1 << ". " << shop[i] << std::endl;
    }
    std::cout << "Total: " <<  goods::total << std::endl;
    goods::setPercent(0.2);
    std::ofstream outFile("basa.txt");
    for (int i = 0; i < N; ++i) {
        outFile << shop[i];
    }
    outFile.close();
    system("pause");
    return 0;
}