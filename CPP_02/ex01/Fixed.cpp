#include "Fixed.hpp"
#include <cmath>

const int Fixed::bits = 8;

Fixed::Fixed() : fixed_point(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    this->fixed_point = value << bits;
}

Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;
    this->fixed_point = static_cast<int>(roundf(value * (1 << bits)));
}

Fixed::Fixed(const Fixed& copy)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->fixed_point = other.fixed_point;
    return *this;
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->fixed_point;
}

void Fixed::setRawBits( int const raw )
{
    this->fixed_point = raw;
}

float Fixed::toFloat( void ) const
{
    return static_cast<float>(this->fixed_point) / (1 << bits);
}

int Fixed::toInt( void ) const
{
    return this->fixed_point >> bits;
}

std::ostream& operator<<(std::ostream& os, Fixed const& rhs)
{
    os << rhs.toFloat();
    return os;
}
