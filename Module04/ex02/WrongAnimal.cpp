#include "WrongAnimal.hpp"
#include <iostream>
WrongAnimal::WrongAnimal()
    : type("WrongAnimal")
{
    std::cout << "WrongAnimal default constructor called\n";
}
WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
    std::cout << "WrongAnimal copy constructor called\n";
    this->type = other.type;
}
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
    std::cout << "WrongAnimal assignment operator called\n";
    if (this != &other)
        this->type = other.type;
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal Destructor called\n";
}
void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal sound\n";
}