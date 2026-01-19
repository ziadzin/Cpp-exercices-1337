#include "Zombie.hpp"

int main()
{
	Zombie *pzombie = newZombie("HeapZombie");// => heap
	pzombie->announce();

	randomChump("StackZombie");// => stack
	delete pzombie;
	return 0;
}
