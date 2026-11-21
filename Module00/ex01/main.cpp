#include "PhoneBook.hpp"
#include <iostream>

int main(void)
{
	PhoneBook		pb;
	std::string		mode;

	std::cout << "--->PhoneBook<---\n";
	std::cout << "Commands: ADD, SEARCH, EXIT\n";
	while (1)
	{
		std::cout << "> ";
		if (!std::getline(std::cin, mode))
			break ;
		else if(mode == "ADD")
			add_contact(pb);
		else if (mode == "SEARCH")
			search_contacts(pb);
		else if (mode == "EXIT")
			break ;
		else if (!mode.empty())
			std::cout << "Unknown command. Use: ADD, SEARCH, or EXIT\n";
	}
	std::cout << "Goodbye!\n";
	return 0;
}
