#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
    int                 fixed_point;
    static const int    bits;

public:
    Fixed();                            // default
    Fixed(const int value);             // from int
    Fixed(const float value);           // from float
    Fixed(const Fixed& copy);           // copy
    ~Fixed();                           // destructor

    Fixed&  operator=(const Fixed& other);

    int     getRawBits( void ) const;
    void    setRawBits( int const raw );

    float   toFloat( void ) const;
    int     toInt( void ) const;
};

// operator<< non-membre
std::ostream& operator<<(std::ostream& os, Fixed const& rhs);

#endif
