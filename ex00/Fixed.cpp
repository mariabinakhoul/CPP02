#include "Fixed.h"

Fixed::Fixed():fixedp(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed& fixedp)
{
	std::cout << "Copy constructor called\n";
	this->fixedp = fixedp.getRawBits();
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

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called\n";
	return this->fixedp;
}

void Fixed::setRawBits( int const raw )
{
	fixedp = raw;
}