#ifndef FIXED_H
# define FIXED_H

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int	fixedp;
		static const int fract_bits = 8;

	public:
		Fixed();
		Fixed(const Fixed&);
		Fixed(const int);
		Fixed(const float);
		~Fixed();
		Fixed& operator=(const Fixed&);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& value);


#endif