#include "Fixed.hpp"

const int Fixed::bits = 8;

Fixed::Fixed() : fixed_point(0) 
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy)
{
    std::cout << "Copy constructor called" << std::endl;
    this->fixed_point = copy.fixed_point;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->fixed_point = other.fixed_point;
    return (*this);
}

void Fixed::setRawBits( int const raw )
{
    this->fixed_point = raw;
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->fixed_point;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}