#include <iostream>
#include "FixedPoint.h"


int main() {
	FixedPoint<8> val;
	std::cout << val.toString() << '\n';
	return 0;
}