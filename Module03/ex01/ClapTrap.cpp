#include "ClapTrap.hpp"
#include <iostream>

static void	putname(std::string name)
{
	std::cout << "ClapTrap";
	if(!name.empty())
    	std::cout << ' ' << name;
}

//void ClapTrap::getinfo( void )
//{
//	std::cout << "ClapTrap " << name << " info:\n";
//	std::cout << "Hit Points: " << hp << "\n";
//	std::cout << "Energy Points: " << ep << "\n";
//	std::cout << "Damage: " << damage << "\n\n";
//}

// default constructor
ClapTrap::ClapTrap()
{
	hp = 10;
	ep = 10;
	damage = 0;
    std::cout << "ClapTrap default constructor called\n";
}

// parameterized constructor
ClapTrap::ClapTrap(std::string name)
{
	this->name = name;
	hp = 10;
	ep = 10;
	damage = 0;
	putname(name);
    std::cout << " constructor called\n";
}

// copy constructor
ClapTrap::ClapTrap(const ClapTrap &other)
{
	name = other.name;
	hp = other.hp;
	ep = other.ep;
	damage = other.damage;
	putname(name);
    std::cout << " copy constructor called\n";
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    if (this != &other)
    {
        name = other.name;
        hp = other.hp;
        ep = other.ep;
        damage = other.damage;
    }

	putname(name);
    std::cout << " assigned\n";
    return *this;
}

ClapTrap::~ClapTrap()
{
	putname(name);
    std::cout << " destructor called\n";
}








void ClapTrap::attack(const std::string &target)
{
	if(this == ClapTrap)
	//std::cout << this << std::endl;
    if (hp > 0 && ep > 0 && ep--)
	{
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

void ClapTrap::takeDamage(unsigned int amount)
{
    if (hp <= amount)
    {
        hp = 0;
		putname(name);
        std::cout << " takes " << amount << " points of damage and died!\n";
    }
    else
    {
        hp -= amount;
		putname(name);
        std::cout << " takes " << amount << " points of damage (HP=" << hp <<")!\n";
    }
}
void ClapTrap::beRepaired(unsigned int amount)
{
    if (hp > 0 && ep > 0)
    {
        ep--;
        hp += amount;
		putname(name);
        std::cout << " is repaired to (HP=" << hp <<")!\n";
    }
	else if(!ep)
	{
		putname(name);
        std::cout << " has no ep(0) to be repaired (destroyed)!\n";
	}
	else
	{
		putname(name);
		std::cout << " has no HP(0) to be repaired (destroyed)!\n";
	}

}
