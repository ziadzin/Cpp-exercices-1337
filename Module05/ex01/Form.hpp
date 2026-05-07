#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;
class Form
{
	private:
		const std::string	name;
		bool				isSigned;
		const int			gradeToSign;
		const int			gradeToExecute;

	public:
		Form();
		Form(std::string name, int gradeToSign, int gradeToExecute);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();

		const std::string	getName() const;
		bool				getIsSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;
		void				beSigned(const Bureaucrat& bureaucrat);

		class GradeTooHighException : public std::exception
		{
				public:
					virtual const char* what() const throw()
					{
						return ("Form grade is too high!");
					}
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Form grade is too low!");
				}
		};
};

static std::ostream& operator<<(std::ostream& os, const Form& form)
{
	bool fsigned = form.getIsSigned();

	if(fsigned)
		os << "✅";
	else
		os << "❌";

	os << "[Form]=> Name->" << form.getName() << " | Status->";

	if(fsigned)
		os << "signed";
	else
		os << "unsigned";

	os << " | Sign_Grade->" << form.getGradeToSign() 
	<< " | Execute_Grade->" << form.getGradeToExecute() << '.';
	return os;
}

#endif