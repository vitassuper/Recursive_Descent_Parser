#include <iostream>
#include "headers/Parser.hpp"

// global TODO
// perform comprehensive improvements
int main() {
	try {
		Parser math(std::string("2*(3+80575706607)+20/2"));
		std::cout << math.execute();
	}
	catch (std::runtime_error& e) {
		std::cout << e.what();
	}
	system("pause");
	return 0;
}


