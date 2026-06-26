#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstddef>

Intern::Intern()
{
}

Intern::Intern(const Intern& other)
{
	(void)other;
}

Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	return *this;
}

Intern::~Intern()
{
}

AForm*	Intern::_makeShrubberyCreationForm(std::string target)
{
	return new ShrubberyCreationForm(target);
}

AForm*	Intern::_makeRobotomyRequestForm(std::string target)
{
	return new RobotomyRequestForm(target);
}

AForm*	Intern::_makePresidentialPardonForm(std::string target)
{
	return new PresidentialPardonForm(target);
}

AForm*	Intern::makeForm(std::string formName, std::string target)
{
	std::string formNames[] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	AForm* (Intern::*formCreators[])(std::string) = {
		&Intern::_makeShrubberyCreationForm,
		&Intern::_makeRobotomyRequestForm,
		&Intern::_makePresidentialPardonForm
	};

	for (int i = 0; i < 3; i++)
	{
		if (formName == formNames[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return (this->*formCreators[i])(target);
		}
		else if (formName.substr(0, 2) == formNames[i].substr(0, 2))
		{
			std::cerr << "✗ Exception: Intern cannot create this form \"" << formName << "\"!"
					<< "\nMaybe you meant " << formNames[i] << " ?"
					<< std::endl;
			return NULL;
		}
	}

	std::cerr << "✗ Exception: Intern cannot create this form " << formName << "!"
				<< std::endl;
	return NULL;
}
