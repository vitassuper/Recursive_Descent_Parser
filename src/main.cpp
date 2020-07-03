#include <iostream>
#include "headers/Parser.hpp"

// global TODO
// perform comprehensive improvements
int main() {
	try {
		Parser math(std::string("(1+2+3+4)")); // 10
		std::cout << math.execute();
	}
	catch (std::runtime_error& e) {
		std::cout << e.what();
	}
	std::cin.get();
	return 0;
}