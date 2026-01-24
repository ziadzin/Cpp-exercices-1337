#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() 
{
	Animal* meta = new Animal();
	Animal* j = new Dog();
	Animal* i = new Cat();
	std::cout << j->getType() << " <j type" << std::endl;
	std::cout << i->getType() << " <i type" << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete j;
	delete i;
	std::cout << "---------------------" << std::endl;
	WrongAnimal* wrongMeta = new WrongAnimal();
	WrongAnimal* wrongCat = new WrongCat();
	std::cout << wrongCat->getType() << " " << std::endl;
	wrongCat->makeSound();
	wrongMeta->makeSound();
	delete wrongMeta;
	delete wrongCat;

	Dog test;
	std::cout << test.getType() << " <test type" << std::endl;
	Dog testcpy;
	testcpy = test;
	std::cout << testcpy.getType() << " <testcpy type\n";
    return 0;
}
