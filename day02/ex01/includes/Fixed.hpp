#pragma once
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

    private :
        int StoreNum;
        static const int FractionalBitsNum = 8;
};

std::ostream& operator<<(std::ostream& o, const Fixed& fixed);