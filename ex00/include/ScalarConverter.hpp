#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include "Parser.hpp"

class ScalarConverter
{
	public:
		static void	convert(std::string str);

	private:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter &src);
		ScalarConverter &operator=(const ScalarConverter &op);
		~ScalarConverter(void);
};

#endif