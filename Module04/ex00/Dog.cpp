#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal()
{
    this->type = "Dog";
    std::cout << this->type << " constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
    std::cout << this->type << " copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    if (this != &other)
        Animal::operator=(other);
    std::cout << this->type << " assignment operator called" << std::endl;
    return *this;
}

Dog::~Dog()
{
    std::cout << this->type << " destructor called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << this->type << " sound => Bark" << std::endl;
}
