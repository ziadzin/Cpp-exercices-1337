#include "Form.hpp"

int main()
{
	std::cout << "=== TEST 1: Valid Form Creation ===" << std::endl;
	try
	{
		Form taxForm("Tax Return", 50, 30);
		std::cout << "✓ Form created successfully" << std::endl;
		std::cout << taxForm << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "✗ Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== TEST 2: Invalid Form - Grade Too High ===" << std::endl;
	try
	{
		Form invalidForm("Invalid", 0, 30);
	}
	catch (std::exception &e)
	{
		std::cout << "✓ Caught expected exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== TEST 3: Invalid Form - Grade Too Low ===" << std::endl;
	try
	{
		Form invalidForm2("Invalid", 151, 30);
	}
	catch (std::exception &e)
	{
		std::cout << "✓ Caught expected exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== TEST 4: Bureaucrat Signs Form (Success) ===" << std::endl;
	try
	{
		Form contract("Contract", 50, 30);
		Bureaucrat john("John", 45);
		
		std::cout << "Before signing:" << std::endl;
		std::cout << contract << std::endl;
		std::cout << john << std::endl;
		
		john.signForm(contract);
		
		std::cout << "After signing:" << std::endl;
		std::cout << contract << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "✗ Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== TEST 5: Bureaucrat Signs Form (Failure - Grade Too Low) ===" << std::endl;
	try
	{
		Form seniorForm("Senior Document", 30, 20);
		Bureaucrat jane("Jane", 60);
		
		std::cout << "Before signing:" << std::endl;
		std::cout << seniorForm << std::endl;
		std::cout << jane << std::endl;
		
		jane.signForm(seniorForm);
		
		std::cout << "After signing:" << std::endl;
		std::cout << seniorForm << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "✗ Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== TEST 6: Edge Case - Grade 1 (Highest) ===" << std::endl;
	try
	{
		Bureaucrat president("President", 1);
		Form veryImportant("Veto", 1, 1);
		
		std::cout << president << std::endl;
		std::cout << veryImportant << std::endl;
		
		president.signForm(veryImportant);
		std::cout << veryImportant << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "✗ Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== TEST 7: Edge Case - Grade 150 (Lowest) ===" << std::endl;
	try
	{
		Bureaucrat intern("Intern", 150);
		Form simple("Coffee Break Request", 150, 150);
		
		std::cout << intern << std::endl;
		std::cout << simple << std::endl;
		
		intern.signForm(simple);
		std::cout << simple << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "✗ Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== TEST 8: Copy Constructor ===" << std::endl;
	try
	{
		Form original("Original", 50, 30);
		Form copy(original);
		
		std::cout << "Original: " << original << std::endl;
		std::cout << "Copy: " << copy << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "✗ Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== TEST 9: Assignment Operator ===" << std::endl;
	try
	{
		Form form1("Form1", 50, 30);
		Form form2("Form2", 100, 80);
		
		std::cout << "Before assignment:" << std::endl;
		std::cout << "form1: " << form1 << std::endl;
		std::cout << "form2: " << form2 << std::endl;
		
		form1 = form2;
		
		std::cout << "After form1 = form2:" << std::endl;
		std::cout << "form1: " << form1 << std::endl;
		std::cout << "form2: " << form2 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "✗ Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== All tests completed ===" << std::endl;
	return 0;
}
