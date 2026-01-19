#include "Zombie.hpp"

Zombie::Zombie() : name("")
{
}

std::string Zombie::fetch_name(void)
{
	return this->name;
}

Zombie::~Zombie()
{
	std::cout << name << " is destroyed" << std::endl;
}

void Zombie::announce() const
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
	this->name = name;
}
