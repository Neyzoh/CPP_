#include <iostream>
#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
private:
    int fixed_point;
    static const int bits;
public:
    Fixed();
    Fixed(int fixed_point);
    ~Fixed();
    Fixed(const Fixed& copy);
    Fixed& operator=(const Fixed& other);
    int getRawBits( void ) const;
    void setRawBits( int const raw );
};

#endif