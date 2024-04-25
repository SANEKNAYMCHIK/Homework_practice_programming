#include <iostream>
#include <exception>
#include <cmath>


class Vector {
private:
    double* m_data;
    size_t m_size;
public:
    //Vector() = default;
    Vector(size_t size = 1);
    Vector(const double* data, size_t size);
    Vector(const Vector& source);
    ~Vector();
    void print() const;
    double norm() const;
    Vector& operator++(); //prefix
    Vector operator++(int); //postfix
    Vector& operator=(const Vector& b);
    Vector& operator+=(const Vector& b);
    double& operator[](size_t idx);
    double operator()(double val) const;
    double& operator[](size_t idx) const;
    size_t size() const {
        return m_size;
    }
    //friend std::ostream& operator<<(std::ostream&, const Vector& a);
    //static bool equal(const Vector& a, const Vector& b);
    //Vector operator+(const Vector& b) const;
    //friend Vector operator+(const Vector &a, const Vector &b);
};

Vector::Vector(size_t size) : m_size(size), m_data(new double[size]) {}

Vector::Vector(const double* data, size_t size) : Vector(size) {
    for (size_t idx = 0; idx < size; ++idx) {
        m_data[idx] = data[idx];
    }   
}


Vector::Vector(const Vector& source) : Vector(source.m_data, source.m_size) {}


Vector::~Vector() {
    delete[] m_data;
    m_data = nullptr;
    m_size = 0;
}

void Vector::print() const {
    for (size_t idx = 0; idx < m_size; ++idx) {
        std::cout << m_data[idx] << ' ';
    }
    std::cout << '\n';
}


Vector& Vector::operator=(const Vector& b) {
    if (&b != this) {
        delete[] m_data;
        m_data = new double[b.m_size];
        m_size = b.m_size;
        for (size_t idx = 0; idx < m_size; ++idx) {
            m_data[idx] = b.m_data[idx];
        }
    }
    return *this;
}


Vector& Vector::operator+=(const Vector& b) {
    if (m_size != b.m_size) {
        throw std::runtime_error("vector size mismatch");
    }
    for (size_t idx = 0; idx < m_size; ++idx) {
        m_data[idx] += b.m_data[idx];
    }
    return *this;
}


/*Vector Vector::operator+(const Vector& b) const {
    if (m_size != b.m_size) {
        throw std::runtime_error("vector size mismatch");
    }
    Vector result(*this);
    for (size_t idx = 0; idx < m_size; ++idx) {
        result.m_data[idx] += b.m_data[idx];
    }
    return result;
}*/


Vector operator+(const Vector &a, const Vector &b) {
    Vector result(a);
    result += b;
    return result;
}


/*bool Vector::equal(const Vector& a, const Vector& b) {
    if (a.m_size != b.m_size) {
        return false;
    }
    for (size_t idx = 0; idx < a.m_size; ++idx) {
        if (a.m_data[idx] != b.m_data[idx]) {
            return false;
        }
    }
    return true;
}*/


double Vector::norm() const {
    double result = 0;
    for (size_t idx = 0; idx < m_size; ++idx) {
        result += m_data[idx] * m_data[idx];
    }
    result = std::sqrt(result);
    return result;
}


bool operator<(const Vector &a, const Vector &b) {
    return a.norm() < b.norm();
}


bool operator==(const Vector &a, const Vector &b) {
    return !(a < b) && !(b < a);
    //return Vector::equal(a, b);
}


bool operator!=(const Vector &a, const Vector &b) {
    return !(a == b);
}


bool operator>(const Vector &a, const Vector &b) {
    return !(a < b) && !(a == b);
}


bool operator>=(const Vector &a, const Vector &b) {
    return !(a < b);
}


bool operator<=(const Vector &a, const Vector &b) {
    return !(a > b);
}


Vector& Vector::operator++() {
    for (size_t idx = 0; idx < m_size; ++idx) {
        ++m_data[idx];
    }
    return *this;
}


Vector Vector::operator++(int) {
    Vector result(*this);
    ++(*this);
    return result;
}


double& Vector::operator[](size_t idx) {
    //for not const values
    return m_data[idx];
}


double& Vector::operator[](size_t idx) const {
    //for const values
    return m_data[idx];
}


double Vector::operator()(double val) const {
    double result = 0;
    double deg = 1;
    for (size_t idx = 0; idx < m_size; ++idx) {
        result += m_data[idx] * deg;
        deg *= val;
    }
    return result;
}


std::ostream& operator<<(std::ostream& out, const Vector& a) {
    for (size_t idx = 0; idx < a.size(); ++idx) {
        out << a[idx] << ' ';
    }
    out << '\n';
    return out;
}


int main() {
    double xyz1[] = {1, 0, 0};
    double xyz2[] = {0, 1, 0};
    Vector vec1(xyz1, 3);
    Vector vec2(xyz2, 3);
    vec1.print();
    vec1[1] = 5;
    vec1.print();
    vec2.print();
    //Vector vec3(vec1);
    // то же самое, не присваивание, а инициализация
    Vector vec3 = vec1;
    //а это уже присваивание: 
    //vec3 = vec1
    //Правило трех:
    //Если реализовали (переопределили) что-то из следующих трех:
    //деструктор, оператор присваивания, копирующий конструктор
    //то тогда нужно и переопределить оставшиеся два
    Vector sum = vec1 + vec2;
    sum.print();
    std::cout << sum[1] << '\n';
    std::cout << sum(2) << '\n';
    std::cout << sum;
    return 0;
}