#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T> void print(const T &x)
{
	std::cout << x << " ";
}

void addOne(int &x)
{
	x += 1;
}

int main(void)
{
	int numbers[] = {1, 2, 3, 4, 5};
	std::string words[] = {"hello", "world", "42"};

	std::cout << "int array:    ";
	iter(numbers, 5, print<int>);
	std::cout << std::endl;

	iter(numbers, 5, addOne);
	std::cout << "after addOne: ";
	iter(numbers, 5, print<int>);
	std::cout << std::endl;

	std::cout << "string array: ";
	iter(words, 3, print<std::string>);
	std::cout << std::endl;

	return 0;
}
