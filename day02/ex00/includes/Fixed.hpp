#pragma once
#include <iostream>

class Fixed
{
    public :
        //OCCF
        Fixed();
        Fixed(const Fixed &fixed);
        ~Fixed();
        Fixed & operator = (const Fixed &fixed);

        int getRawBits( void ) const;
        void setRawBits( int const raw );

    private :
        int StoreNum;
        static const int FractionalBitsNum = 8;
};