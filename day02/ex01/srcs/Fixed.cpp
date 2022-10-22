#include "../includes/Fixed.hpp"

Fixed::Fixed(void)
{
    std::cout << "Default constructor called" << std::endl;
    this->StoreNum = 0;
}

Fixed::Fixed(const int num)
{
    std::cout << "Int constructor called" << std::endl;
    this->StoreNum = (num << FractionalBitsNum);
}

Fixed::Fixed(const float num)
{
    std::cout << "Float constructor called" << std::endl;
    this->StoreNum = int(roundf(num * (1 << FractionalBitsNum)));
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
    : StoreNum(fixed.StoreNum)
{
    std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator = (const Fixed &fixed)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->StoreNum = fixed.StoreNum;
    return *this;
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->StoreNum;
}

void Fixed::setRawBits (int const raw)
{
    this->StoreNum = raw;
}

float Fixed::toFloat(void) const
{
	return float(this->StoreNum) / (1 << FractionalBitsNum);
}

int Fixed::toInt(void) const
{
	return this->StoreNum >> FractionalBitsNum;
}

std::ostream& operator<<(std::ostream& o, const Fixed& fixed)
{
	o << fixed.toFloat();
	return o;
}