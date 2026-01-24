#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal(), brain(new Brain())
{
    this->type = "Dog";
    std::cout << this->type << " constructor called\n";
}

Dog::Dog(const Dog& other) : Animal(other)
{
    this->brain = new Brain(*(other.brain));
    std::cout << this->type << " copy constructor called\n";
}
Dog& Dog::operator=(const Dog& other)
{
    if (this != &other)
    {
        Animal::operator=(other);
        *this->brain = *(other.brain);
    }
    std::cout << this->type << " assignment operator called\n";
    return *this;
}

Dog::~Dog()
{
    delete this->brain;
    std::cout << this->type << " destructor called\n";
}

void Dog::makeSound() const
{
    std::cout << this->type << " sound => Bark\n";
}