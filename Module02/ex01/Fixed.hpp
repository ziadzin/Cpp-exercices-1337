#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int					value;
		static const int	fraction = 8;
	public:
		Fixed();
		Fixed(const int);
		Fixed(const float);
		Fixed(const Fixed& other_object);
		Fixed& operator=(const Fixed& other);
		~Fixed();
		int toInt() const;
		float toFloat() const;
		int getRawBits(void) const;
		void setRawBits(int const raw);
};

std::ostream &operator<<(std::ostream &right, const Fixed& number);

#endif