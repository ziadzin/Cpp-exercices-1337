#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal(): type("WrongAnimal")
{
    std::cout << this->type << " default constructor called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
    this->type = other.type;
    std::cout << this->type << " copy constructor called\n";
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
    std::cout << this->type << " assignment operator called\n";
    if (this != &other)
        this->type = other.type;
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << this->type << " destructor called\n";
}

void WrongAnimal::makeSound() const
{
    std::cout << this->type << " sound\n";
}

std::string WrongAnimal::getType() const
{
	if(type.empty())
		return "Default type(\"\")";
	return type;
}
