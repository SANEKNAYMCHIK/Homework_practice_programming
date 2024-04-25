#ifndef FIXEDPOINT_H
#define FIXEDPOINT_H
#include <string>


template <int Size>
class FixedPoint {
private:
	int _integer = 0;
	unsigned char _digits[Size] = {};
public:
	FixedPoint(int intVal = 0) : _integer(intVal) {}
	std::string toString() const {
		std::string intStr = std::to_string(_integer);
		std::string digitsStr;
		for (unsigned char c : _digits) {
			digitsStr += c + '0';
		}
		/*for (auto it = _digits; it != _digits + Size; ++it) {
			digitsStr += *it + '0';
		}*/
		return intStr + std::string(".") + digitsStr;
	}
};


#endif