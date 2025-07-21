#include "Fixed.h"

Fixed::Fixed():fixedp(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called\n";
	this->fixedp = other.getRawBits();
}

Fixed::Fixed(const int fixedp)
{
	std::cout << "Int constructor called\n";
	this->fixedp = fixedp << fract_bits;
}

Fixed::Fixed(const float fixedp)
{
	std::cout << "Float constructor called\n";
	this->fixedp = roundf(fixedp * (1 << fract_bits));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &other)
		this->fixedp = other.getRawBits();
	return (*this);
}

std::ostream& operator<<(std::ostream& out, const Fixed& other)
{
	out << other.toFloat();
	return out;
}


int Fixed::getRawBits( void ) const
{
	return this->fixedp;
}

void Fixed::setRawBits( int const raw )
{
	fixedp = raw;
}

float Fixed::toFloat( void ) const
{
	return (float)this->fixedp / (1 << fract_bits);
}

int Fixed::toInt( void ) const
{
	return this->fixedp >> fract_bits;
}