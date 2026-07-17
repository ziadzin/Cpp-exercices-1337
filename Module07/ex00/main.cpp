#include <iostream>
#include <string>
#include "whatever.hpp"

int main()
{
	int a = 10;
	int b = 4;
    std::cout << "a=" << a << std::endl;
    std::cout << "b=" << b << std::endl;
    std::cout << "\nmax=" << ::max<int>(a, b) << std::endl;
    std::cout << "min=" << ::min<int>(a, b) << std::endl;
    std::cout << "\nswap\n\n";
	::swap<int>(a, b);
	std::cout << "a=" << a << std::endl;
    std::cout << "b=" << b << std::endl;

	std::string c = "name1";
	std::string d = "name2";
    std::cout << "\nc=" << c << std::endl;
    std::cout << "d=" << d << std::endl;
    std::cout << "\nmax=" << ::max(c, d) << std::endl;
    std::cout << "min=" << ::min(c, d) << std::endl;
    std::cout << "\nswap\n\n";
	::swap(c, d);
	std::cout << "c=" << c << std::endl;
    std::cout << "d=" << d << std::endl;
    return 0;
}
