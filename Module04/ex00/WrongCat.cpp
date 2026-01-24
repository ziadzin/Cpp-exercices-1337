#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat()
{
    this->type = "WrongCat";
    std::cout << this->type << " default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
    std::cout << this->type << " copy constructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	if (this != &other)
		WrongAnimal::operator=(other);
    std::cout << this->type << " assignment operator called" << std::endl;
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << this->type << " destructor called" << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << this->type << " Meow" << std::endl;
}
