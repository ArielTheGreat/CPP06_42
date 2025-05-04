# include "Parser.hpp"

/* Orthodox Canonical Class Form */

Parser::Parser(void) {
}

Parser::Parser(Parser const &src) {
	(void)src;
}

Parser &Parser::operator=(Parser const &rhs) {
	if (this != &rhs) {
		(void)rhs;
	}
	return (*this);
}

Parser::~Parser(void) {
}

/* Static Variables */

std::string Parser::_input = "";
eType		Parser::_type = OTHER;


const char *Parser::InvalidInputException::what() const throw()
{
    return ("InvalidInputException: the string is invalid for conversion");
}

void Parser::display_conversion()
{

}

void Parser::parse_input(std::string &str)
{
    try
    {
        setInput(str);
        setType(_input);
    }
    catch(const std::exception& e)
    {
        throw InvalidInputException();
    }   
}

void Parser::setInput(std::string str)
{
    if (str.length() == 0)
        throw InvalidInputException();
    
    std::string white_spaces = " \t\n\v\f\r";
    size_t		start	= str.find_first_not_of(white_spaces);
	size_t		end		= str.find_last_not_of(white_spaces);
    if (start != std::string::npos && end != std::string::npos)
        _input = str.substr(start, end - start + 1);
}

void Parser::setType(std::string str)
{
    if (_isChar(str))
    {
        _type = CHAR;
    }else if(_isInt(str))
    {
        _type = INT;
    } else if (_isFloat(str)) {
		_type = FLOAT;
	} else if (_isDouble(str)) {
		_type = DOUBLE;
	} else if (_isPseudoLiteral(str)) {
		_type = PSEUDOLITERAL;
	} else {
		throw InvalidInputException();
	}
}

bool		_isChar(std::string str)
{
    if (str.length() == 1 && !isdigit(str[0])) {
		return (true);
	}
	return (false);
}

bool		_isInt(std::string str)
{
    for (size_t	i = 0; i < str.length(); i++) {
		if (i == 0 && (str[i] == '-' || str[i] == '+')) {
			continue ;
		} else if (!isdigit(str[i])) {
			return (false);
		}
	}
    long num = atol(str.c_str());
	long max = std::numeric_limits<int>::max();
	long min = std::numeric_limits<int>::min();
	return (num >= min && num <= max);
}

bool		_isFloat(std::string str)
{
    size_t	count_dot = 0;
	for (size_t i = 0; i < str.length(); i++) {
		if (i == 0 && (str[i] == '-' || str[i] == '+')) {
			continue ;
		} else if (count_dot < 1 && str[i] == '.') {
			count_dot++;
		} else if (!isdigit(str[i]) && !(i == str.length() - 1 && str[i] == 'f')) {
			return (false);
		}
	}
	double num = strtod(str.c_str(), NULL);
	double max = std::numeric_limits<float>::max();
	double min = -std::numeric_limits<float>::max();
	return (num >= min && num <= max);
}
bool		_isDouble(std::string str)
{
    size_t	count_dot = 0;
	for (size_t i = 0; i < str.length(); i++) {
		if (i == 0 && (str[i] == '-' || str[i] == '+')) {
			continue ;
		} else if (count_dot < 1 && str[i] == '.') {
			count_dot++;
		} else if (!isdigit(str[i])) {
			return (false);
		}
	}
	double num = strtod(str.c_str(), NULL);
	double max = std::numeric_limits<double>::max();
	double min = -std::numeric_limits<double>::max();
	return (num >= min && num <= max);
}

bool		_isPseudoLiteral(std::string str)
{
    if (str == "-inff" || str == "+inff" || str == "nanf" || str == "-inf" || str == "+inf" || str == "nan") {
		return (true);
	}
	return (false);
}

/* Display Conversion */

void Parser::display_conversion(void)
{
    try
    {
        _toChar();
        _toInt();
        _toFloat();
        _toDouble();
    }
    catch(const std::exception& e)
    {
        throw InvalidInputException();
    }
}

void		_toChar(void)
{

}
void		_toInt(void)
{

}

void		_toFloat(void)
{

}

void		_toDouble(void)
{
    
}