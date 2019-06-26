#include "headers/Parser.hpp"

double Parser::execute() {
	return this->eval(this->parse());
}

Expression Parser::parse() {
	return this->parse_binary_expression(0);
}

std::string Parser::parse_token() {
	if (this->input.size() > this->iter) {
		if (std::isdigit(this->input.at(this->iter))) {
			std::string number;
			while (this->input.size() > this->iter && (std::isdigit(this->input.at(this->iter)) || this->input.at(this->iter) == '.')) {
				number.push_back(this->input.at(this->iter)); this->iter++;
			}
			return number;
		}

		static std::string tokens[] = {
			"+", "-", "*", "/", "**", "mod", "sin", "cos" , "(" , ")",
		};
		for (auto &t : tokens) {
			if (std::strncmp(this->input.substr(iter).c_str(), t.c_str(), t.size()) == 0) {
				this->iter += t.size();
				return t;
			}
		}
	}
	return "";
}


Expression Parser::parse_simple_expression() {
	std::string token = this->parse_token();
	if (token.empty()) {
		throw std::runtime_error("Invalid Expression");
	}
	if (std::isdigit(token.at(0))) {
		return Expression(token);
	}
	if (token == "(") {
		Expression result = parse();
		if (this->parse_token() != ")") {
			throw std::runtime_error("Expected )...");
		}
		return result;
	}
	return Expression(token, parse_simple_expression());
}

Expression Parser::parse_binary_expression(unsigned int min_priority) {
	Expression left_expr = parse_simple_expression();
	while (true) {
		std::string op = this->parse_token();
		unsigned int priority = this->get_priority(op);
		if (priority <= min_priority) {
			this->iter -= op.size();
			return left_expr;
		}
		Expression right_expr = this->parse_binary_expression(priority);
		left_expr = Expression(op, left_expr, right_expr);
	}
}


unsigned int Parser::get_priority(std::string & token) {
	if (token == "+") return 1;
	if (token == "-") return 1;
	if (token == "*") return 2;
	if (token == "/") return 2;
	if (token == "mod") return 2;
	if (token == "**") return 3;
	return 0;
}



double Parser::eval(const Expression & e) {
	if (e.get_args().size() == 2) {
		double a = eval(e.get_args()[0]);
		double b = eval(e.get_args()[1]);
		if (e.get_token() == "+") return a + b;
		if (e.get_token() == "-") return a - b;
		if (e.get_token() == "*") return a * b;
		if (e.get_token() == "/") return a / b;
		if (e.get_token() == "**") return pow(a, b);
		if (e.get_token() == "mod") (int)a % (int)b;
		throw std::runtime_error("Unknow binary operation");
	}
	if (e.get_args().size() == 1) {
		double a = eval(e.get_args()[0]);
		if (e.get_token() == "+") return +a;
		if (e.get_token() == "-") return -a;
		if (e.get_token() == "sin") return sin(a);
		if (e.get_token() == "cos") return cos(a);
		throw std::runtime_error("Unknow unary operation");
	}
	if (e.get_args().size() == 0) {
		return strtod(e.get_token().c_str(), nullptr);
	}
	throw std::runtime_error("Unknow expression type");
}

void Parser::delete_spaces() {
	this->input.erase(std::remove_if(this->input.begin(), this->input.end(), std::isspace), input.end());
}