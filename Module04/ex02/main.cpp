#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>
int main() 
{
    //Animal *a = new Animal(); // abstract class cannot be instantiated
	Dog dog;
	Cat cat;
	std::cout << dog.getType() << " <dog type" << std::endl;
	std::cout << cat.getType() << " <cat type" << std::endl;
	dog.makeSound();
	cat.makeSound();
    return 0;
}