#include "headers/Expression.hpp"

Expression::Expression(std::string token) : token(token) {}
Expression::Expression(std::string token, Expression a) : token(token), args{ a } {}
Expression::Expression(std::string token, Expression a, Expression b) : token(token), args{ a,b } {}

std::string Expression::get_token() const noexcept {
	return this->token;
}
std::vector<Expression>Expression::get_args() const noexcept {
	return this->args;
}