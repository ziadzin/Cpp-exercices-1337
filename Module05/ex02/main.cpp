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
		//AForm test("garden");
		// and


		//std::cout << john << std::endl;
		//// std::cout << shrubbery << std::endl;

		john.signForm(shrubbery);
		john.executeForm(shrubbery);

	}
	catch (std::exception &e)
	{
		std::cout << "✗ Exception: " << e.what() << std::endl;
	}

	return 0;
}
