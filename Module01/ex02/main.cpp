#include <iostream>
#include <string>

int main()
{
	std::string brain = "HI THIS IS BRAIN";
	std::string *ptr = &brain;
	std::string *ref = ptr;

	std::cout << "ADDRESS =>\n";
	std::cout << &brain << '\n';
	std::cout << ptr << '\n';
	std::cout << ref << '\n';

	std::cout << "VALUES =>\n";
	std::cout << brain << '\n';
	std::cout << *ptr << '\n';
	std::cout << *ref << '\n';
	return 0;
}