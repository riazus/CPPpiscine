#pragma once
#include "Fixed.hpp"

class Point
{
    public :
        Point();
        Point(const float x, const float y);
        Point(const Point &point);
        Point &operator =(const Point &point);
        ~Point();
        const Fixed getFixedX() const;
        const Fixed getFixedY() const;
    
    private :
        const Fixed x;
        const Fixed y;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);