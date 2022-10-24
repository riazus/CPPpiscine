#include "../includes/Point.hpp"
#include <cmath>

Point::Point() 
    : x(Fixed()), y(Fixed())
{
}

Point::Point(const float x, const float y)
    : x(Fixed(x)), y(Fixed(y))
{
}

Point::Point(const Point &copy)
    : x(copy.x), y(copy.y)
{
}

Point &Point::operator =(const Point &point)
{
    (void)point;
    return *this;
}

Point::~Point()
{
}

const Fixed Point::getFixedX() const
{
    return this->x;
}

const Fixed Point::getFixedY() const
{
    return this->y;
}