#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

int	main(void)
{
	std::vector<int>	vec;

	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(20);

	std::vector<int>::iterator	vit = easyfind(vec, 20);
	std::cout << "vector: found " << *vit << " at index " << (vit - vec.begin()) << std::endl;

	std::list<int>	lst(vec.begin(), vec.end());
	std::list<int>::iterator	lit = easyfind(lst, 30);
	std::cout << "list: found " << *lit << std::endl;

	std::deque<int>	deq(vec.begin(), vec.end());
	std::deque<int>::iterator	dit = easyfind(deq, 10);
	std::cout << "deque: found " << *dit << " at index " << (dit - deq.begin()) << std::endl;

	try
	{
		easyfind(vec, 42);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
