#ifndef PARSER_HPP
# define PARSER_HPP

# include <iostream>
# include <string>
# include <limits>
# include <iomanip>

enum	eType
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	PSEUDOLITERAL,
	OTHER
};

class Parser
{
	private:
		Parser(void);
		Parser(Parser const &src);
		Parser &operator=(Parser const &rhs);
		~Parser(void);

		static bool		_isChar(std::string str);
		static bool		_isInt(std::string str);
		static bool		_isFloat(std::string str);
		static bool		_isDouble(std::string str);
		static bool		_isPseudoLiteral(std::string str);
		static void		_toChar(void);
		static void		_toInt(void);
		static void		_toFloat(void);
		static void		_toDouble(void);

	public:
		static std::string	_input;
		static eType		_type;

		static void		parse_input(std::string &str);
		static void		setInput(std::string str);
		static void		setType(std::string str);
		static void		display_conversion(void);


		class InvalidInputException : public std::exception
		{
			virtual const char *what() const throw();
		};
};

#endif