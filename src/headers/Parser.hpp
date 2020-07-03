#pragma once
#ifndef __PARSER_HPP__
#define __PARSER_HPP__

#include <cctype>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <stdexcept>

#include "Expression.hpp"

class Parser {
public:
	explicit Parser(std::string input);
	double execute();
	Expression parse();
private:
	std::string input;
	size_t iter;
	static std::string_view constexpr tokens[] = {	"+", "-", "*", "/", "**", "mod", "sin", "cos" , "(" , ")",	};

	Expression parse_binary_expression(unsigned int min_priority);
	Expression parse_simple_expression();
	std::string parse_token();
	void delete_spaces();
	unsigned char get_priority(std::string& token) const noexcept;
	double eval(const Expression& e) const;
};

#endif // !__PARSER_HPP__