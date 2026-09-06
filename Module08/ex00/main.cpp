#include <vector>
#include <iostream>
#include "easyfind.hpp"

int main(void)
{
	std::vector<int> testvec;

	testvec.push_back(42);
	testvec.push_back(33);
	testvec.push_back(13);
	testvec.push_back(9);

	std::vector<int>::iterator it;
	try
	{
		it = easyfind(testvec, 13);
		std::cout << "find => " << *it << std::endl;

		it = easyfind(testvec, 1337);
		std::cout << "find => " << *it << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return 1;
	}
	return 0;
}
