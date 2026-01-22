#include "Harl.hpp"

void Harl::debug(void)
{
	std::cout << "[ DEBUG ]\n";
	std::cout << "Debuging mode >>\n";
}

void Harl::info(void)
{
	std::cout << "[ INFO ]\n";
	std::cout << "No info to show >>\n";
}

void Harl::warning(void)
{
	std::cout << "[ WARNING ]\n";
	std::cout << "This may cause a problem >>\n";
}

void Harl::error(void)
{
	std::cout << "[ ERROR ]\n";
	std::cout << "Invalid input >>\n";
}

Harl::Harl( void )
{
	methods[0] = &Harl::debug;
	methods[1] = &Harl::info;
	methods[2] = &Harl::warning;
	methods[3] = &Harl::error;

	options[0] = "DEBUG";
	options[1] = "INFO";
	options[2] = "WARNING";
	options[3] = "ERROR";
}

void Harl::complain(std::string level)
{
	for (int i = 0; i < 4; i++)
	{
		if(level == options[i])
		{
			(this->*methods[i])();
			return ;
		}
	}
	std::cout << "[ " << level << " ] => Invalid condition!";
}
