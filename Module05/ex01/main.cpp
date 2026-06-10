#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << "=== TEST 1: Valid Form ===\n";
	try
	{
		Form taxForm("TaxReturn", 50, 30);
		std::cout << taxForm << '\n';
	}
	catch (std::exception& e)
	{
		std::cout << "Unexpected: " << e.what() << '\n';
	}

	std::cout << "\n=== TEST 2: Sign grade too high ===\n";
	try { Form f("Bad", 0, 30); }
	catch (std::exception& e) { std::cout << "Caught: " << e.what() << '\n'; }

	std::cout << "\n=== TEST 3: Sign grade too low ===\n";
	try { Form f("Bad", 151, 30); }
	catch (std::exception& e) { std::cout << "Caught: " << e.what() << '\n'; }

	std::cout << "\n=== TEST 4: Exec grade too high ===\n";
	try { Form f("Bad", 50, 0); }
	catch (std::exception& e) { std::cout << "Caught: " << e.what() << '\n'; }

	std::cout << "\n=== TEST 5: Exec grade too low ===\n";
	try { Form f("Bad", 50, 151); }
	catch (std::exception& e) { std::cout << "Caught: " << e.what() << '\n'; }

	std::cout << "\n=== TEST 6: Successful sign ===\n";
	try
	{
		Form contract("Contract", 50, 30);
		Bureaucrat john("John", 45);
		std::cout << contract << '\n';
		std::cout << john << '\n';
		john.signForm(contract);
		std::cout << contract << '\n';
	}
	catch (std::exception& e)
	{
		std::cout << "Unexpected: " << e.what() << '\n';
	}

	std::cout << "\n=== TEST 7: Failed sign (grade too low) ===\n";
	try
	{
		Form senior("Senior", 30, 20);
		Bureaucrat jane("Jane", 60);
		jane.signForm(senior);
		std::cout << senior << '\n';
	}
	catch (std::exception& e)
	{
		std::cout << "Unexpected: " << e.what() << '\n';
	}

	std::cout << "\n=== TEST 8: Double sign (idempotent / no-op) ===\n";
	try
	{
		Form memo("Memo", 100, 100);
		Bureaucrat boss("Boss", 1);
		boss.signForm(memo);
		boss.signForm(memo);
		std::cout << memo << '\n';
	}
	catch (std::exception& e)
	{
		std::cout << "Unexpected: " << e.what() << '\n';
	}

	return 0;
}
