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

		// class InternCannotCreateFormException : public std::exception
		// {
		// 	private:
		// 		std::string _msg;
		// 	public:
		// 		InternCannotCreateFormException(std::string formName, std::string closestFormName) throw()
		// 		{
		// 			this->_msg = "Intern cannot create this form \"" + formName + "\" !";
		// 			if (!closestFormName.empty())
		// 				this->_msg += "\nMaybe you meant \"" + closestFormName + "\" ?";
		// 		}
		// 		virtual ~InternCannotCreateFormException() throw() {}
		// 		virtual const char* what() const throw()
		// 		{
		// 			return (this->_msg.c_str());
		// 		}
		// };

	private:
		AForm*	_makeShrubberyCreationForm(std::string target);
		AForm*	_makeRobotomyRequestForm(std::string target);
		AForm*	_makePresidentialPardonForm(std::string target);
};

#endif
