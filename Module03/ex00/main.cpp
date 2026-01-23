#include "ClapTrap.hpp"

int main()
{
	ClapTrap z("Z");
	//z.getinfo();

	z.takeDamage(9);
	z.attack("test");
	z.beRepaired(2);

	//z.getinfo();
}
