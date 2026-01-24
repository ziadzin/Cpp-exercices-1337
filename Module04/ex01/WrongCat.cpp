#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat()
{
    this->type = "WrongCat";
    std::cout << this->type << " default constructor called\n";
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
    std::cout << this->type << " copy constructor called\n";
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	if (this != &other)
		WrongAnimal::operator=(other);
    std::cout << this->type << " assignment operator called\n";
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << this->type << " destructor called\n";
}

void WrongCat::makeSound() const
{
    std::cout << this->type << " Meow\n";
}
