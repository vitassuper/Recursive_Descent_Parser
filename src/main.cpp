#include <iostream>
#include "headers/Parser.hpp"


int main() {
	try {
		Parser math(std::string("2*(3+8)+20/2"));
		std::cout << math.execute();
	}
	catch (std::runtime_error e) {
		std::cout << e.what();
	}
	system("pause");
	return 0;
}


