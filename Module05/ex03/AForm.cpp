#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() :
	_name("default_form"), _isSigned(false), _gradeToSign(150),
	_gradeToExecute(150)
{
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& other) : 
	_name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), 
	_gradeToExecute(other._gradeToExecute)
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
	return (_name);
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
		_isSigned = true;
		return ;
	}
	throw AForm::GradeTooLowException();
}

void AForm::checkExecReqs(const Bureaucrat& executor) const
{
    if (!_isSigned)
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > _gradeToExecute)
        throw AForm::GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const AForm& form)
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

AForm::~AForm()
{
}
