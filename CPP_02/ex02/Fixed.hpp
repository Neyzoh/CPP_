#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
    int                 fixed_point;
    static const int    bits;

public:
    // Canonical form
    Fixed();
    Fixed(const int value);
    Fixed(const float value);
    Fixed(const Fixed& copy);
    ~Fixed();

    Fixed&  operator=(const Fixed& other);

    // Getters / setters
    int     getRawBits( void ) const;
    void    setRawBits( int const raw );

    float   toFloat( void ) const;
    int     toInt( void ) const;

    // Comparaison
    bool    operator>(const Fixed& rhs) const;
    bool    operator<(const Fixed& rhs) const;
    bool    operator>=(const Fixed& rhs) const;
    bool    operator<=(const Fixed& rhs) const;
    bool    operator==(const Fixed& rhs) const;
    bool    operator!=(const Fixed& rhs) const;

    // Arithmétique
    Fixed   operator+(const Fixed& rhs) const;
    Fixed   operator-(const Fixed& rhs) const;
    Fixed   operator*(const Fixed& rhs) const;
    Fixed   operator/(const Fixed& rhs) const;

    // Incrément / décrément
    // prefixe
    Fixed&  operator++();    // ++a
    Fixed&  operator--();    // --a
    // postfixe
    Fixed   operator++(int); // a++
    Fixed   operator--(int); // a--

    // min / max
    static Fixed&       min(Fixed& a, Fixed& b);
    static const Fixed& min(Fixed const& a, Fixed const& b);
    static Fixed&       max(Fixed& a, Fixed& b);
    static const Fixed& max(Fixed const& a, Fixed const& b);
};

std::ostream& operator<<(std::ostream& os, Fixed const& rhs);

#endif
