#include "headers/Expression.hpp"

std::string Expression::get_token() const {
	return this->token;
}

std::vector<Expression>Expression::get_args() const {
	return this->args;
}