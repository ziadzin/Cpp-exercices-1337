#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

using namespace std;

int main()
{
	// Intern someRandomIntern;

	// AForm* f = someRandomIntern.makeForm("shrubbery creation", "home");
	// if (f)
	// 	std::cout << *f << std::endl;
	// else
	// 	std::cout << "got NULL instead of a form!" << std::endl;
	// someRandomIntern.makeForm("robotomy request", "Bender");
	std::string formName = "run";
	try
	{
		std::cout << formName.at(3) << std::endl;
		throw out_of_range("f");
	}
	catch(std::out_of_range & e)
	{
		std::cout << "Exception caught:" << e.what() << std::endl;
	}
	
	
	return 0;
}
