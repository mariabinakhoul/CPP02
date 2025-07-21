#ifndef FIXED_H
# define FIXED_H

#include <iostream>

class Fixed
{
	private:
		int	fixedp;
		static const int fract_bits = 8;
	public:
		Fixed();
		Fixed(const Fixed&);
		~Fixed();
		Fixed& operator=(const Fixed&);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};

#endif