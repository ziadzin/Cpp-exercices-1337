#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{

	std::cout << "--- Test 1: Invalid Form Creation ---" << std::endl;
	try
	{
		Form invalidForm("Invalid", 151, 50);
	}
	catch (std::exception &e)
	{
		std::cout << "✗ Exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- Test 2: Valid Form & Successful Sign ---" << std::endl;
	try
	{
		Bureaucrat boss("Boss", 1);
		Form taxForm("TaxForm", 50, 50);
		
		std::cout << taxForm << std::endl;
		boss.signForm(taxForm);
		std::cout << taxForm << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "✗ Exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- Test 3: Valid Form & Failed Sign (Grade too low) ---" << std::endl;
	try
	{
		Bureaucrat intern("Intern", 100);
		Form topSecretForm("TopSecret", 10, 10);
		
		std::cout << topSecretForm << std::endl;
		intern.signForm(topSecretForm);
		std::cout << topSecretForm << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "✗ Exception: " << e.what() << std::endl;
	}

	return 0;
}
