#include <iostream>
#include <vector>
#include <cstdlib>
#include "Span.hpp"

int	main(void)
{
	{
		std::cout << "test 1" << std::endl;
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	try
	{
		std::cout << "test 2" << std::endl;
		Span sp = Span(7);

		sp.addNumber(6);
		sp.addNumber(8);
		sp.addNumber(3);
		sp.addNumber(13);
		sp.addNumber(7);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;

	}
	catch(std::exception& e)
	{
		std::cout << e.what();
	}

	try
	{
		std::cout << "test 3" << std::endl;
		Span sp = Span(6);

		sp.addNumber(3);
		sp.addNumber(9);

		std::vector<int> testvec;
		testvec.push_back(42);
		testvec.push_back(33);
		testvec.push_back(13);
		testvec.push_back(9);

		sp.addAll(testvec);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;

	}
	catch(std::exception& e)
	{
		std::cout << e.what();
	}


	return (0);
}
