#pragma once
#include "Expression.hpp"
#include <cctype>
#include <algorithm>
class Parser {
public:
	explicit Parser(std::string input) : input(input), iter(0) { this->delete_spaces(); }
	double execute();
	Expression parse();
private:
	std::string input;
	unsigned iter;

	Expression parse_binary_expression(unsigned int min_priority);
	Expression parse_simple_expression();
	std::string parse_token();
	void delete_spaces();
	unsigned int get_priority(std::string & token);
	double eval(const Expression &e);
};