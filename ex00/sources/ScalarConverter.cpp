#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {
}

ScalarConverter::ScalarConverter(ScalarConverter const &src) {
	(void)src;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &rhs) {
	if (this != &rhs) {
		(void)rhs;
	}
	return (*this);
}

ScalarConverter::~ScalarConverter(void) {
}

void	ScalarConverter::convert(std::string str) {
	try {
		Parser::parse_input(str);
		Parser::display_conversion();
	} catch (const std::exception &e) {
		throw e;
	}
}