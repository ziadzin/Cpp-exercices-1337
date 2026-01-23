#include "FragTrap.hpp"
#include <iostream>

static void	putname(std::string name)
{
	std::cout << "FragTrap";
	if(!name.empty())
    	std::cout << ' ' << name;
}

FragTrap::FragTrap() : ClapTrap()
{
    hp = 100;
    ep = 100;
    damage = 30;
	putname(name);
    std::cout << " default constructor called\n";
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    hp = 100;
    ep = 100;
    damage = 30;
	putname(name);
    std::cout << " constructor called\n";
}

FragTrap::FragTrap(const FragTrap &other) :ClapTrap(other)
{
	putname(name);
    std::cout << " copy constructor called\n";
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
    }
	putname(name);
    std::cout << " assignment operator called\n";
    return *this;
}

FragTrap::~FragTrap()
{
	putname(name);
    std::cout << " destructor called\n";
}

void FragTrap::highFivesGuys()
{
	putname(name);
    std::cout << " is requesting a high five!\n";
}

void FragTrap::attack(const std::string &target)
{
    if (ep > 0 && hp > 0)
    {
        ep--;
		putname(name);
        std::cout << " attacks " << target << ", causing " << damage << " points of damage!\n";
    }
    else
    {
        putname(name);
        std::cout << " has insufficient energy or hit points to attack.\n";
    }
}
