#include "ScavTrap.hpp"
#include <iostream>

static void	putname(std::string name)
{
	std::cout << "ScavTrap";
	if(!name.empty())
    	std::cout << ' ' << name;
}

ScavTrap::ScavTrap() : ClapTrap()
{
    hp = 100;
    ep = 50;
    damage = 20;
	putname(name);
    std::cout << " default constructor called\n";
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    hp = 100;
    ep = 50;
    damage = 20;
	putname(name);
    std::cout << " constructor called\n";
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	putname(name);
    std::cout << " copy constructor called\n";
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
    }
	putname(name);
    std::cout << " assignment operator called\n";
    return *this;
}

ScavTrap::~ScavTrap()
{
    putname(name);
    std::cout << " destructor called\n";
}

void ScavTrap::guardGate()
{
	putname(name);
    std::cout << " is now in Gate Keeper mode.\n";
}

void ScavTrap::attack(const std::string &target)
{
    if (ep > 0 && hp > 0)
    {
        ep--;
        putname(name);
        std::cout << " attacks " << target << ", causing " << damage << " points of damage!\n";
    }
    else if(!ep)
    {
        putname(name);
        std::cout << " has no ep(0) left to attack!\n";
    }
	else
	{
		putname(name);
		std::cout << " has no HP(0) left to attack!\n";
	}
}
