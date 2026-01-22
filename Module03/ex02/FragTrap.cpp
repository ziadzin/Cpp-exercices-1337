#include "FragTrap.hpp"
#include <iostream>
FragTrap::FragTrap() : ClapTrap()
{
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap default constructor called\n";
}
FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap " << name << " constructor called\n";
}
FragTrap::FragTrap(const FragTrap &other) :ClapTrap(other)
{
    std::cout << "FragTrap " << name << " copy constructor called\n";
}
FragTrap &FragTrap::operator=(const FragTrap &other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
    }
    std::cout << "FragTrap assignment operator called\n";
    return *this;
}
FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << name << " destructor called\n";
}
void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap " << name << " is requesting a high five!\n";
}
void FragTrap::attack(const std::string &target)
{
    if (energyPoints > 0 && hitPoints > 0)
    {
        energyPoints--;
        std::cout << "FragTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!\n";
    }
    else
    {
        std::cout << "FragTrap " << name << " has insufficient energy or hit points to attack.\n";
    }
}
