#pragma once
#include <string>
#include <vector>
class Expression {
public:
	Expression(std::string token) : token(token) {}
	Expression(std::string token, Expression a) : token(token), args{ a } {}
	Expression(std::string token, Expression a, Expression b) : token(token), args{ a,b } {}
	std::string get_token() const;
	std::vector<Expression>get_args() const;
private:
	std::string token;
	std::vector<Expression>args;
};