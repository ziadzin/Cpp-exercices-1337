#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	std::cout << "=== TEST 1: ShrubberyCreationForm ===" << std::endl;
	try
	{
		Bureaucrat john("John", 136);
		ShrubberyCreationForm shrubbery("garden");

		std::cout << john << std::endl;
		std::cout << shrubbery << std::endl;

		john.signForm(shrubbery);
		john.executeForm(shrubbery);
	}
	catch (std::exception &e)
	{
		std::cout << "✗ Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== TEST 2: RobotomyRequestForm ===" << std::endl;
	try
	{
		Bureaucrat alice("Alice", 40);
		RobotomyRequestForm robotomy("Bob");

		std::cout << alice << std::endl;
		std::cout << robotomy << std::endl;

		alice.signForm(robotomy);
		alice.executeForm(robotomy);
	}
	catch (std::exception &e)
	{
		std::cout << "✗ Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== TEST 3: PresidentialPardonForm ===" << std::endl;
	try
	{
		Bureaucrat president("President", 1);
		PresidentialPardonForm pardon("Criminal");

		std::cout << president << std::endl;
		std::cout << pardon << std::endl;

		president.signForm(pardon);
		president.executeForm(pardon);
	}
	catch (std::exception &e)
	{
		std::cout << "✗ Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== TEST 4: Grade too low for RobotomyRequestForm ===" << std::endl;
	try
	{
		Bureaucrat intern("Intern", 150);
		RobotomyRequestForm robotomy2("Alice");

		std::cout << intern << std::endl;
		std::cout << robotomy2 << std::endl;

		intern.signForm(robotomy2);
		intern.executeForm(robotomy2);
	}
	catch (std::exception &e)
	{
		std::cout << "✗ Exception: " << e.what() << std::endl;
	}

	return 0;
}
