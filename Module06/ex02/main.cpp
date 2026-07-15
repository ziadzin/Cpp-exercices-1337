#include <iostream>
#include <exception>
#include <cstdlib>
#include <ctime>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base	*generate(void)
{
	//int r = std::rand();
	//int num = r % 3;
	//std::cout << r << " / " << 3  << " = " << r/3 << " => " << num << '\n';
	switch (std::rand() % 3)
	{
		case 0:
			return (new A());
		case 1:
			return (new B());
		case 2:
			return (new C());
	}
	return NULL;
}

void	identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A" << '\n';
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << '\n';
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << '\n';
	else
		std::cout << "unknown" << '\n';
}

void	identify(Base &p)
{
	try { (void)dynamic_cast<A &>(p); std::cout << "A" << '\n'; return; }
	catch (std::exception &e) {}
	try { (void)dynamic_cast<B &>(p); std::cout << "B" << '\n'; return; }
	catch (std::exception &e) {}
	try { (void)dynamic_cast<C &>(p); std::cout << "C" << '\n'; return; }
	catch (std::exception &e) {}
	std::cout << "unknown" << '\n';
}

int main(void)
{
	Base	*p;

	std::srand(std::time(NULL));
	p = generate();
	std::cout << "pointer   -> ";
	identify(p);
	std::cout << "reference -> ";
	identify(*p);
	delete p;
	return (0);
}
