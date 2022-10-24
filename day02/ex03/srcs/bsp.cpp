#include "../includes/Point.hpp"

float sign(Point const point, Point const a, Point const b)
{
	return ((point.getFixedX().toFloat() - b.getFixedX().toFloat()) 
    * (a.getFixedY().toFloat() - b.getFixedY().toFloat()) - (a.getFixedX().toFloat() 
    - b.getFixedX().toFloat()) * (point.getFixedY().toFloat() - b.getFixedY().toFloat()));
}

float distance(Point const a, Point const b)
{
    return std::sqrt(std::pow((a.getFixedX().toFloat() - b.getFixedX().toFloat()), 2) + std::pow((a.getFixedY().toFloat() - b.getFixedY().toFloat()), 2));
}

bool checkExtremeOptions(Point const a, Point const b, Point const c, Point const point)
{
    if (distance(a, point) + distance(b, point) == distance(a, b))
    {
        return false;
    }
    else if (distance(b, point) + distance(c, point) == distance(b, c))
    {
        return false;
    }
    else if (distance(c, point) + distance(a, point) == distance(c, a))
    {
        return false;
    }
    else if (a.getFixedX().toFloat() == point.getFixedX().toFloat() 
            && a.getFixedY().toFloat() == point.getFixedY().toFloat())
    {
        return false;
    }
    else if (b.getFixedX().toFloat() == point.getFixedX().toFloat() 
            && b.getFixedY().toFloat() == point.getFixedY().toFloat())
    {
        return false;
    }
    else if (c.getFixedX().toFloat() == point.getFixedX().toFloat() 
            && c.getFixedY().toFloat() == point.getFixedY().toFloat())
    {
        return false;
    }
    return true;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	float d1, d2, d3;
	bool has_neg, has_pos;

    if(!checkExtremeOptions(a, b, c, point))
    {
        return false;
    }

	d1 = sign(point, a, b);
	d2 = sign(point, b, c);
	d3 = sign(point, c, a);

	has_neg = d1 < 0 || d2 < 0 || d3 < 0;
	has_pos = d1 > 0 || d2 > 0 || d3 > 0;

	return !(has_neg && has_pos);
}