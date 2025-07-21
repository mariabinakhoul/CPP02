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

		bool operator>(const Fixed&) const;
		bool operator<(const Fixed&) const;
		bool operator>=(const Fixed&) const;
		bool operator<=(const Fixed&) const;
		bool operator==(const Fixed&) const;
		bool operator!=(const Fixed&) const;

		Fixed operator+(const Fixed&);
		Fixed operator-(const Fixed&);
		Fixed operator*(const Fixed&);
		Fixed operator/(const Fixed&);

		Fixed& operator++();
		Fixed operator++(int);
		Fixed& operator--(const Fixed&);
		Fixed operator--(int);

		static Fixed& min(Fixed&, Fixed&);
		static const Fixed& min(const Fixed&, const Fixed&);
		static Fixed& max(Fixed&, Fixed&);
		static const Fixed& max(const Fixed&, const Fixed&);
		
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& value);


#endif