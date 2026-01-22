// HumanB.cpp
#include <iostream>
#include "HumanB.hpp"

HumanB::HumanB(const std::string& name)
{
	this->name = name;
	this->weapon = NULL;
}

void HumanB::setWeapon(Weapon& w) {
    weapon = &w;
}

void HumanB::attack() const {
    if (weapon)
        std::cout << name << " attacks with their " << weapon->getType() << '\n';
}
