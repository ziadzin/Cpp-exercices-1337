#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main()
{
	Intern someRandomIntern;

	// "shr" starts with "sh" — matches formNames[0] "shrubbery creation" substr(0,2)
	// so the else if fires on i==0 and returns NULL before even checking for exact match
	AForm* f = someRandomIntern.makeForm("shrubbery creation", "home");
	// f will be NULL — bug confirmed if this prints nothing / crashes on deref
	if (f)
		std::cout << *f << std::endl;
	else
		std::cout << "got NULL instead of a form!" << std::endl;

	return 0;
}
