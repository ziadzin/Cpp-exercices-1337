#include "Fixed.hpp"

Fixed::Fixed():value(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &other_object)
{
	std::cout << "Copy constructor called\n";
	*this = other_object;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &other)
		this->value = other.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

void Fixed::setRawBits( int const raw )
{
	this->value = raw;
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called\n";
	return (this->value);
}
