#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal(): type("WrongAnimal")
{
    std::cout << this->type << " default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
    this->type = other.type;
    std::cout << this->type << " copy constructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
    std::cout << this->type << " assignment operator called" << std::endl;
    if (this != &other)
        this->type = other.type;
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << this->type << " destructor called" << std::endl;
}

void WrongAnimal::makeSound() const
{
    std::cout << this->type << " sound" << std::endl;
}

std::string WrongAnimal::getType() const
{
	if(type.empty())
		return "Default type(\"\")";
	return type;
}
