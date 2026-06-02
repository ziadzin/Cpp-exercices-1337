#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;

	public:
		AForm();
		AForm(std::string name, int gradeToSign, int gradeToExecute);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm();

		const std::string	getName() const;
		bool				getIsSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;
		void				beSigned(const Bureaucrat& bureaucrat);
		void				checkExecReqs(const Bureaucrat& executor) const;
		virtual void		execute(const Bureaucrat& executor) const = 0;

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("AForm grade is too high!");
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("AForm grade is too low!");
				}
		};

		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Form is not signed!");
				}
		};
};

static std::ostream& operator<<(std::ostream& os, const AForm& form)
{
	bool fsigned = form.getIsSigned();

	if(fsigned)
		os << "✓";
	else
		os << "✗";

	os << "[AForm]=> Name->" << form.getName() << " | Status->";

	if(fsigned)
		os << "signed";
	else
		os << "unsigned";

	os << " | Sign_Grade->" << form.getGradeToSign() 
	<< " | Execute_Grade->" << form.getGradeToExecute() << '.';
	return os;
}

#endif
