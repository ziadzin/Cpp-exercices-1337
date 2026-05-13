#include "Form.hpp"

Form::Form() :
	_name("default_form"), _gradeToSign(150),
	_gradeToExecute(150), _isSigned(false)
{
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _isSigned(false)
{
	if (gradeToSign < 1)
		throw Form::GradeTooHighException();
	else if (gradeToSign > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& other) : 
	_name(other._name), _gradeToSign(other._gradeToSign), 
	_gradeToExecute(other._gradeToExecute), _isSigned(other._isSigned)
{
}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
		this->_isSigned = other._isSigned;
	return *this;
}

const std::string	Form::getName() const
{
	return (this->_name);
}

bool Form::getIsSigned() const
{
	return (_isSigned);
}

int	Form::getGradeToSign() const
{
	return (_gradeToSign);
}

int	Form::getGradeToExecute() const
{
	return (_gradeToExecute);
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if(bureaucrat.getGrade() <= this->getGradeToSign())
	{
		this->_isSigned = true;
		return ;
	}
	throw Form::GradeTooLowException();
}

Form::~Form()
{
}
