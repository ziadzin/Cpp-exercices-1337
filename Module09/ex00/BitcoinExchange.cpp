#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <cstdlib>

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _db(other._db)
{
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		this->_db = other._db;
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

static std::string trim(const std::string &s)
{
	std::string::size_type	start = s.find_first_not_of(" \t\r\n");
	std::string::size_type	end = s.find_last_not_of(" \t\r\n");

	if (start == std::string::npos)
		return ("");
	return (s.substr(start, end - start + 1));
}

static bool isNumber(const std::string &s)
{
	if (s.empty())
		return (false);
	for (std::string::size_type i = 0; i < s.size(); i++)
	{
		if (s[i] < '0' || s[i] > '9')
			return (false);
	}
	return (true);
}

static bool isValidDate(const std::string &date)
{
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return (false);

	std::string	y = date.substr(0, 4);
	std::string	m = date.substr(5, 2);
	std::string	d = date.substr(8, 2);

	if (!isNumber(y) || !isNumber(m) || !isNumber(d))
		return (false);

	int	year = std::atoi(y.c_str());
	int	month = std::atoi(m.c_str());
	int	day = std::atoi(d.c_str());

	if (month < 1 || month > 12 || day < 1)
		return (false);

	int	days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
		days[1] = 29;
	if (day > days[month - 1])
		return (false);
	return (true);
}

static bool isValidValue(const std::string &s, double &value)
{
	char	*end;

	if (s.empty())
		return (false);
	value = std::strtod(s.c_str(), &end);
	if (*end != '\0')
		return (false);
	return (true);
}

bool BitcoinExchange::loadDatabase(const std::string &filename)
{
	std::ifstream	file(filename.c_str());
	std::string		line;

	if (!file.is_open())
	{
		std::cout << "Error: could not open file." << std::endl;
		return (false);
	}
	std::getline(file, line);
	while (std::getline(file, line))
	{
		std::string::size_type	pos = line.find(',');

		if (pos == std::string::npos)
			continue ;
		std::string	date = trim(line.substr(0, pos));
		std::string	rate = trim(line.substr(pos + 1));
		this->_db[date] = std::strtod(rate.c_str(), NULL);
	}
	file.close();
	return (true);
}

void BitcoinExchange::processInput(const std::string &filename)
{
	std::ifstream	file(filename.c_str());
	std::string		line;

	if (!file.is_open())
	{
		std::cout << "Error: could not open file." << std::endl;
		return ;
	}
	std::getline(file, line);
	if (trim(line) != "date | value")
		file.seekg(0);
	while (std::getline(file, line))
	{
		if (trim(line).empty())
			continue ;

		std::string::size_type	pos = line.find('|');
		if (pos == std::string::npos)
		{
			std::cout << "Error: bad input => " << trim(line) << std::endl;
			continue ;
		}

		std::string	date = trim(line.substr(0, pos));
		std::string	valueStr = trim(line.substr(pos + 1));
		double		value;

		if (!isValidDate(date))
		{
			std::cout << "Error: bad input => " << date << std::endl;
			continue ;
		}
		if (!isValidValue(valueStr, value))
		{
			std::cout << "Error: bad input => " << valueStr << std::endl;
			continue ;
		}
		if (value < 0)
		{
			std::cout << "Error: not a positive number." << std::endl;
			continue ;
		}
		if (value > 1000)
		{
			std::cout << "Error: too large a number." << std::endl;
			continue ;
		}

		std::map<std::string, double>::const_iterator	it = this->_db.lower_bound(date);
		if (it == this->_db.end() || it->first != date)
		{
			if (it == this->_db.begin())
			{
				std::cout << "Error: no data before this date." << std::endl;
				continue ;
			}
			--it;
		}
		std::cout << date << " => " << value << " = " << value * it->second << std::endl;
	}
	file.close();
}
