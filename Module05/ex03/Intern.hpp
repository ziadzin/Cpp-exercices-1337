#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include "AForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);
		~Intern();

		AForm*	makeForm(std::string formName, std::string target);
	private:
		AForm*	_makeShrubberyCreationForm(std::string target);
		AForm*	_makeRobotomyRequestForm(std::string target);
		AForm*	_makePresidentialPardonForm(std::string target);
};

#endif
