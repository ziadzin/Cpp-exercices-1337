#include <iostream>
#include <string>
#include "Array.hpp"

int main()
{
	Array<int> a(10);
	std::cout << "a size=" << a.size() << '\n';
	for (unsigned int i = 0; i < a.size(); i++)
		a[i] = 9;

	for (unsigned int i = 0; i < a.size(); i++)
		std::cout << a[i] << " ";
	std::cout << std::endl;


	Array<int> b(a);
	std::cout << "b size=" << b.size() << '\n';
	for (unsigned int i = 0; i < b.size(); i++)
		std::cout << b[i] << " ";
	std::cout << std::endl;

	b[0] = 42;
	for (unsigned int i = 0; i < b.size(); i++)
		std::cout << b[i] << " ";
	std::cout << std::endl;

	//out of bounds test 1
	try
	{
		std::cout << "a[10] = " << a[10] << "\n";
		std::cout << "a[10] = " << a[10] << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	//empty array;
	Array<int> empty_arr;

	std::cout << "empty_arr size=" << empty_arr.size() << '\n';


	Array<std::string> s(3);
	for (unsigned int i = 0; i < s.size(); i++)
	{
		std::string value = "value";
		s[i] = value + static_cast<char>(i + 1 + '0');
	}
	for (unsigned int i = 0; i < 3; i++)
		std::cout << s[i] << " ";
	std::cout << std::endl;

	//out of bounds test 2
	try
	{
		s[3] = "hello";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	Array<std::string> s2;
	std::cout << "s2 size=" << s2.size() << '\n';
	s2 = s;
	std::cout << "s2 size=" << s2.size() << '\n';
	std::cout << "s2[0] = " << s2[0] << '\n';
	for (unsigned int i = 0; i < s2.size(); i++)
		std::cout << s2[i] << " ";
	std::cout << std::endl;

	return 0;
}
