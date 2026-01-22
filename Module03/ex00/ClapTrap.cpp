#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() : hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap default constructor called\n";
}
ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap " << name << " constructor called\n";
}
ClapTrap::ClapTrap(const ClapTrap &other) : name(other.name), hitPoints(other.hitPoints), 
      energyPoints(other.energyPoints), attackDamage(other.attackDamage)
{
    std::cout << "ClapTrap " << name << " copy constructor called\n";
}
ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    if (this != &other)
    {
        name = other.name;
        hitPoints = other.hitPoints;
        energyPoints = other.energyPoints;
        attackDamage = other.attackDamage;
    }
    std::cout << "ClapTrap " << name << " assigned.\n";
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << name << " destructor called\n";
}
void ClapTrap::attack(const std::string &target)
{
    if (hitPoints > 0 && energyPoints > 0)
    {
        energyPoints--;
        std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
    }
    else
    {
        std::cout << "ClapTrap " << name << " has no energy or hit points left to attack!" << std::endl;
    }    
}
void ClapTrap::takeDamage(unsigned int amount)
{
    if (hitPoints <= amount)
    {
        hitPoints = 0;
        std::cout << "ClapTrap " << name << " takes " << amount << " points of damage and is now destroyed!" << std::endl;
    }
    else
    {
        hitPoints -= amount;
        std::cout << "ClapTrap " << name << " takes " << amount << " points of damage!" << std::endl;
    }
}
void ClapTrap::beRepaired(unsigned int amount)
{
    if (hitPoints > 0 && energyPoints > 0)
    {
        energyPoints--;
        hitPoints += amount;
        std::cout << "ClapTrap " << name << " is repaired by " << amount << " points!" << std::endl;
    }
    else
    {
        std::cout << "ClapTrap " << name << " has no energy or hit points left to be repaired!" << std::endl;
    }
}
