#include "Zombie.hpp"

Zombie* zombieHorde(int size, std::string name)
{
	if (size <= 0)
		return NULL;

	Zombie* arr = new Zombie[size];
	for (int i = 0; i < size; i++)
		arr[i].setName(name);

	return arr;
}
