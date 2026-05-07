#include "Form.hpp"

Form::Form() :
	name("default_form"), gradeToSign(150),
	gradeToExecute(150), isSigned(false)
{
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute), isSigned(false)
{
	if (gradeToSign < 1)
		throw Form::GradeTooHighException();
	else if (gradeToSign > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& other) : 
	name(other.name), gradeToSign(other.gradeToSign), 
	gradeToExecute(other.gradeToExecute), isSigned(other.isSigned)
{
}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
		this->isSigned = other.isSigned;
	return *this;
}

const std::string	Form::getName() const
{
	return (this->name);
}

bool Form::getIsSigned() const
{
	return (isSigned);
}

int	Form::getGradeToSign() const
{
	return (gradeToSign);
}

int	Form::getGradeToExecute() const
{
	return (gradeToExecute);
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if(bureaucrat.getGrade() <= this->getGradeToSign())
	{
		this->isSigned = true;
		return ;
	}
	throw Form::GradeTooLowException();
}

Form::~Form()
{
}
