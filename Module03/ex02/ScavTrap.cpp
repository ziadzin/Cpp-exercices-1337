#include "ScavTrap.hpp"
#include <iostream>
ScavTrap::ScavTrap() : ClapTrap()
{
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap default constructor called\n";
}
ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap " << name << " constructor called\n";
}
ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
    std::cout << "ScavTrap " << name << " copy constructor called\n";
}
ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
    }
    std::cout << "ScavTrap assignment operator called\n";
    return *this;
}
ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << name << " destructor called\n";
}
void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << name << " is now in Gate Keeper mode.\n";
}
void ScavTrap::attack(const std::string &target)
{
    if (energyPoints > 0 && hitPoints > 0)
    {
        energyPoints--;
        std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!\n";
    }
    else
    {
        std::cout << "ScavTrap " << name << " has insufficient energy or hit points to attack.\n";
    }
}