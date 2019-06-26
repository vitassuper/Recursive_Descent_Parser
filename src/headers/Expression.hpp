#pragma once
#include <string>
#include <vector>
class Expression {
public:
	explicit Expression(std::string token);
	explicit Expression(std::string token, Expression a);
	explicit Expression(std::string token, Expression a, Expression b);

	std::string get_token() const noexcept;
	std::vector<Expression>get_args() const noexcept;
private:
	std::string token;
	std::vector<Expression> args;
};