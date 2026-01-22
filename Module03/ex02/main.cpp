#include "FragTrap.hpp"
#include "ScavTrap.hpp"
int main()
{
        ScavTrap scav("Scavvy");
        FragTrap frag("Fraggy");

        scav.attack("Dummy");
        scav.guardGate();
        frag.attack("Dummy");
        frag.highFivesGuys();
        return 0;
}
