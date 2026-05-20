#include "AForm.hpp"

AForm::AForm() :
	_name("default_form"), _gradeToSign(150),
	_gradeToExecute(150), _isSigned(false)
{
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _isSigned(false)
{
	if (gradeToSign < 1)
		throw AForm::GradeTooHighException();
	else if (gradeToSign > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& other) : 
	_name(other._name), _gradeToSign(other._gradeToSign), 
	_gradeToExecute(other._gradeToExecute), _isSigned(other._isSigned)
{
}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
		this->_isSigned = other._isSigned;
	return *this;
}

const std::string	AForm::getName() const
{
	return (this->_name);
}

bool AForm::getIsSigned() const
{
	return (_isSigned);
}

int	AForm::getGradeToSign() const
{
	return (_gradeToSign);
}

int	AForm::getGradeToExecute() const
{
	return (_gradeToExecute);
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if(bureaucrat.getGrade() <= this->getGradeToSign())
	{
		this->_isSigned = true;
		return ;
	}
	throw AForm::GradeTooLowException();
}

void AForm::checkExecReqs(const Bureaucrat& executor) const
{
    if (!this->_isSigned)
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > this->_gradeToExecute)
        throw AForm::GradeTooLowException();
}

AForm::~AForm()
{
}
