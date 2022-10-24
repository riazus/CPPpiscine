#include <iostream>
#include <cmath>

class Fixed
{
    public :
        //OCCF
        Fixed(void);
        Fixed(const int num);
        Fixed(const float num);
        Fixed(const Fixed &fixed);
        ~Fixed();
        Fixed & operator = (const Fixed &fixed);

        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;
        //Comparison operators
        bool operator >(const Fixed& fixed);
        bool operator <(const Fixed& fixed);
        bool operator >=(const Fixed& fixed);
        bool operator <=(const Fixed& fixed);
        bool operator ==(const Fixed& fixed);
        bool operator !=(const Fixed& fixed);
        //Arithmetic operators
        Fixed operator +(const Fixed& fixed);
        Fixed operator -(const Fixed& fixed);
        Fixed operator *(const Fixed& fixed);
        Fixed operator /(const Fixed& fixed);
        //Unary increment/decrement operators
        Fixed& operator++();
        Fixed& operator--();
        Fixed operator++(int);
        Fixed operator--(int);
        //Min/max
        static			Fixed& min(Fixed& a, Fixed& b);
        static const	Fixed& min(const Fixed& a, const Fixed& b);
        static			Fixed& max(Fixed& a, Fixed& b);
        static const	Fixed& max(const Fixed& a, const Fixed& b);

    private :
        int StoreNum;
        static const int FractionalBitsNum = 8;
};

std::ostream& operator<<(std::ostream& o, const Fixed& fixed);