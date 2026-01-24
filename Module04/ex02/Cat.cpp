#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal(), brain(new Brain())
{
    this->type = "Cat";
    std::cout << this->type << " constructor called\n";
}

Cat::Cat(const Cat& other) : Animal(other)
{
    this->brain = new Brain(*(other.brain));
    std::cout << this->type << " copy constructor called\n";
}

Cat& Cat::operator=(const Cat& other)
{
    if (this != &other)
    {
        Animal::operator=(other);
        *this->brain = *(other.brain);
    }
    std::cout << this->type << " assignment operator called\n";
    return *this;
}

Cat::~Cat()
{
    delete this->brain;
    std::cout << this->type << " destructor called\n";
}

void Cat::makeSound() const
{
    std::cout << this->type << " sound => Meow\n";
}