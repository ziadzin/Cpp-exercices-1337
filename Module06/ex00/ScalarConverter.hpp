#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <limits>

enum Type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	PSEUDO,
	OTHER
};

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &other);
		~ScalarConverter();

	public:
		static void convert(const std::string &literal);
};

#endif
