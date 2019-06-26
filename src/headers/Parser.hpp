#pragma once
#include "Expression.hpp"
#include <cctype>
#include <cmath>
#include <algorithm>
#include <stdexcept>
class Parser {
public:
	explicit Parser(std::string input);
	double execute();
	Expression parse();
private:
	std::string input;
	unsigned iter;
	static std::string_view constexpr tokens[] = {	"+", "-", "*", "/", "**", "mod", "sin", "cos" , "(" , ")",	};

	Expression parse_binary_expression(unsigned int min_priority);
	Expression parse_simple_expression();
	std::string parse_token();
	void delete_spaces();
	unsigned char get_priority(std::string& token) const noexcept;
	double eval(const Expression& e) const;
};