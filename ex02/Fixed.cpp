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

bool Fixed::operator>(const Fixed& other) const
{
    return (this->fixedp > other.fixedp);
}

bool Fixed::operator<(const Fixed& other) const
{
    return (this->fixedp < other.fixedp);
}

bool Fixed::operator>=(const Fixed& other) const
{
    return (this->fixedp >= other.fixedp);
}

bool Fixed::operator<=(const Fixed& other) const
{
    return (this->fixedp <= other.fixedp);
}

bool Fixed::operator==(const Fixed& other) const
{
    return (this->fixedp == other.fixedp);
}

bool Fixed::operator!=(const Fixed& other) const
{
    return (this->fixedp != other.fixedp);
}

Fixed Fixed::operator+(const Fixed& other)
{
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other)
{
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other)
{
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other)
{
	if (other.fixedp == 0)
	{
		std::cerr << "Error:division by zero\n";
		return Fixed(0);
	}
	return Fixed(this->toFloat() / other.toFloat());
}

Fixed& Fixed::operator++()
{
	this->fixedp += 1;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp = *this;
	this->fixedp += 1;
	return tmp;
}

Fixed& Fixed::operator--()
{
	this->fixedp -= 1;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp = *this;
	this->fixedp -= 1;
	return tmp;
}

Fixed& Fixed::min(Fixed& first, Fixed& second)
{
	if (first < second)
		return (first);
	return (second);
}

const Fixed& Fixed::min(const Fixed& first, const Fixed& second)
{
	if (first < second)
		return (first);
	return (second);
}

Fixed& Fixed::max(Fixed& first, Fixed& second)
{
	if (first > second)
		return (first);
	return (second);
}

const Fixed& Fixed::max(const Fixed& first, const Fixed& second)
{
	if (first > second)
		return (first);
	return (second);
}
		