#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main()
{
	Intern someRandomIntern;
	AForm* form1 = NULL;
	AForm* form2 = NULL;
	AForm* form3 = NULL;

	std::cout << "--- Test 1: Invalid Form ---" << std::endl;
	try
	{
		form1 = someRandomIntern.makeForm("rob", "garden");
		if (form1) {
			std::cout << *form1 << std::endl;
			delete form1;
		}
	}
	catch (std::exception &e)
	{
		std::cout << "✗ Exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- Test 2: Shrubbery Creation Form ---" << std::endl;
	try
	{
		form2 = someRandomIntern.makeForm("shrubbery creation", "home");
		if (form2) {
			std::cout << *form2 << std::endl;
			delete form2;
		}
	}
	catch (std::exception &e)
	{
		std::cout << "✗ Exception:" << e.what() << std::endl;
	}

	std::cout << "\n--- Test 3: Robotomy Request Form ---" << std::endl;
	try
	{
		form3 = someRandomIntern.makeForm("robotomy request", "Bender");
		if (form3) {
			std::cout << *form3 << std::endl;
			delete form3;
		}
	}
	catch (std::exception &e)
	{
		std::cout << "✗ Exception: " << e.what() << std::endl;
	}

	return 0;
}
