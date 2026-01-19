#include "Zombie.hpp"

int main()
{
	int hordeSize = 5;//arr size
	Zombie* horde = zombieHorde(hordeSize, "HordeZombie");

	for (int i = 0; i < hordeSize; i++)
		horde[i].announce();
	delete[] horde;
	return 0;
}
