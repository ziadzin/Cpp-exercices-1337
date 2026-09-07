#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>

static bool	isValidDate(const std::string &date)
{
	std::istringstream	iss(date);
	int		year;
	int		month;
	int		day;
	char	dash1;
	char	dash2;

	iss >> year >> dash1 >> month >> dash2 >> day;
	std::cout << year << std::endl;
	if (iss.fail() || !iss.eof() || date.size() != 10)
		return (false);
	if (dash1 != '-' || dash2 != '-')
		return (false);
	return (month >= 1 && month <= 12 && day >= 1 && day <= 31);
}

static bool	parseValue(const std::string &str, double &value)
{
	std::istringstream	iss(str);

	iss >> value;
	return (!iss.fail() && iss.eof());
}

BitcoinExchange::BitcoinExchange() : _db()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	*this = other;
}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		_db = other._db;
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

void	BitcoinExchange::loadDatabase(const std::string &file)
{
	std::ifstream	in(file.c_str());
	std::string	line;

	if (!in.is_open())
		throw std::runtime_error("Error: could not open file.");
	std::getline(in, line);
	while (std::getline(in, line))
	{
		std::string::size_type	sep = line.find(',');
		double	rate;

		if (sep != std::string::npos && parseValue(line.substr(sep + 1), rate))
			_db[line.substr(0, sep)] = rate;
	}
}

void	BitcoinExchange::processInput(const std::string &file)
{
	std::ifstream	in(file.c_str());
	std::string	line;

	if (!in.is_open())
		throw std::runtime_error("Error: could not open file.");
	std::getline(in, line);
	while (std::getline(in, line))
	{
		std::string::size_type	sep = line.find(" | ");
		std::string		date = line.substr(0, sep);
		double			value = 0;

		if (sep == std::string::npos || !isValidDate(date) || !parseValue(line.substr(sep + 3), value))
			std::cout << "Error: bad input => " << line << std::endl;
		else if (value < 0)
			std::cout << "Error: not a positive number." << std::endl;
		else if (value > 1000)
			std::cout << "Error: too large a number." << std::endl;
		else
		{
			std::map<std::string, double>::iterator	it = _db.upper_bound(date);

			if (it == _db.begin())
				std::cout << "Error: no data before this date." << std::endl;
			else
				std::cout << date << " => " << value << " = "
					<< value * (--it)->second << std::endl;
		}
	}
}
