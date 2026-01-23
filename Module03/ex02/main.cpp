#include "FragTrap.hpp"
#include "ScavTrap.hpp"
int main()
{
        ScavTrap scav("player1");
        FragTrap frag("player2");
        FragTrap z;
		z = frag;

        scav.attack("test2");
        scav.guardGate();
        frag.attack("test1");
        frag.highFivesGuys();
        return 0;
}
