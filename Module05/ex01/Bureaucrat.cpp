#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(150)
{
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade)
{
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
		this->grade = other.grade;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
}

const std::string	Bureaucrat::getName( void ) const
{
	return (this->name);
}

int Bureaucrat::getGrade( void ) const
{
	return (this->grade);
}

void Bureaucrat::raiseGrade( void )
{
	if (this->grade == 1)
		throw Bureaucrat::GradeTooHighException();
	this->grade--;
}

void Bureaucrat::lowerGrade( void )
{
	if (this->grade == 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade++;
}

void Bureaucrat::signForm( Form &form )
{
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << '\n';
	}
	catch(const std::exception& e)
	{
		std::cerr << this->getName() << "  couldn’t sign " << form.getName() << " because " << e.what() << '\n';
	}
	
}
