#include <iostream>
#include "Array.hpp"

int main()
{
	Array<int> a;
	Array<int> b = a;
	(void)a;
	std::cout << "constructed an empty Array<int>" << std::endl;
	return 0;
}
