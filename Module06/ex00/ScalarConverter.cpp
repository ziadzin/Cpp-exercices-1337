#include "ScalarConverter.hpp"

#include <iostream>
#include <cctype>
#include <cstdlib>
#include <cmath>
#include <limits>

static void printImpossible()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

static bool isPseudo(const std::string& literal)
{
	return (literal == "nanf" || literal == "+inff" || literal == "-inff" || literal == "nan" || literal == "+inf" || literal == "-inf");
}

static bool isDouble(const std::string& literal, size_t end)
{
	size_t	i = 0;
	bool	dot = false;

	if (i < end && (literal[i] == '+' || literal[i] == '-'))
		i++;
	while (i < end)
	{
		if (literal[i] == '.' && !dot)
			dot = true;
		else if (!std::isdigit(static_cast<char> (literal[i])))
			return false;
		i++;
	}
	return (true);
}

static bool isInt(const std::string& literal)
{
	size_t	i = 0;

	if (literal[i] == '+' || literal[i] == '-')
		i++;
	while (i < literal.length())
	{
		if (!std::isdigit(static_cast<char> (literal[i])))
			return false;
		i++;
	}
	return (true);
}

static Type getType(const std::string& literal)
{
	if (literal.empty())
		return (OTHER);
	if (literal.length() == 1 && !std::isdigit(literal[0]))
		return (CHAR);
	if (isPseudo(literal))
		return (PSEUDO);
	if (isInt(literal))
		return (INT);
	if (literal[literal.length() - 1] == 'f' && isDouble(literal, literal.length() - 1))
		return (FLOAT);
	if (isDouble(literal, literal.length()))
		return (DOUBLE);
	return (OTHER);
}

static void printChar(double num)
{
	if (num < 0 || num > 127)
		std::cout << "impossible";
	else if (!std::isprint(static_cast<int> (num)))
		std::cout << "Non displayable";
	else
		std::cout << "'" << static_cast<char> (num) << "'";
}

static void printInt(double num)
{
	if (num < std::numeric_limits<int>::min() || num > std::numeric_limits<int>::max())
		std::cout << "impossible";
	else
		std::cout << static_cast<int> (num);
}

static void printFD(const std::string& type, double num, const std::string& f)
{
	std::cout << type << ": " << num;
	if (std::floor(num) == num && std::fabs(num) < 1000000.0)
		std::cout << ".0";
	std::cout << f << '\n';
}

static void printCI(double num,Type type)
{
//char
	std::cout << "char: ";
	if(type == PSEUDO)
		std::cout << "impossible";
	else
		printChar(num);
	std::cout << '\n';

//int
	std::cout << "int: ";
	if(type == PSEUDO)
		std::cout << "impossible";
	else
		printInt(num);
	std::cout << '\n';
}

void ScalarConverter::convert(const std::string &literal)
{
	Type	type;
	double	num = 0;

	type = getType(literal);
	if (type == OTHER)
	{
		printImpossible();
		return;
	}
	if (type == CHAR)
		num = static_cast<double> (literal[0]);
	else
		num = std::strtod(literal.c_str(), NULL);
	printCI(num, type);
	printFD("float", static_cast<float> (num), "f");
	printFD("double", num, "");
}
