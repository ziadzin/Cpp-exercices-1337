#include "Animal.hpp"


Animal::Animal() : type("")
{
    std::cout << "Animal constructor called\n";
}

Animal::Animal(const Animal& other)
{
    this->type = other.type;
    std::cout << "Animal copy constructor called\n";
}

Animal& Animal::operator=(const Animal& other)
{
    if (this != &other)
        this->type = other.type;
    std::cout << "Animal assignment operator called\n";
    return *this;
}

Animal::~Animal()
{
    std::cout << "Animal destructor called\n";
}

void Animal::makeSound() const
{
    std::cout << "Animal sound\n";
}

std::string Animal::getType() const
{
	if(type.empty())
		return "Default type(\"\")";
	return type;
}
