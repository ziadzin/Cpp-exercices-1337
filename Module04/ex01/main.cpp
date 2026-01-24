#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    std::cout << "=== Creating Animals with Brains ===\n";
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
    
    std::cout << "\n=== Making sounds ===\n";
    dog->makeSound();
    cat->makeSound();
    
    std::cout << "\n=== Deleting Animals (Brain should be deleted too) ===\n";
    delete dog;
    delete cat;

    std::cout << "\n=== Testing Deep Copy ===\n";
    {
        Dog original;
        Dog copy = original;  // Copy constructor - should create new Brain
        
        std::cout << "\n=== Stack objects destructors ===\n";
    }  // Both Dogs deleted, each deletes its own Brain

    std::cout << "\n=== Testing Array of Animals ===\n";
    {
        Animal* animals[4];
        animals[0] = new Dog();
        animals[1] = new Dog();
        animals[2] = new Cat();
        animals[3] = new Cat();
        
        std::cout << "\n=== Deleting array ===\n";
        for (int i = 0; i < 4; i++)
            delete animals[i];
    }

    return 0;
}