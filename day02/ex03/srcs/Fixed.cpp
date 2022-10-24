#include "../includes/Fixed.hpp"

Fixed::Fixed(void)
{
    //std::cout << "Default constructor called" << std::endl;
    this->StoreNum = 0;
}

Fixed::Fixed(const int num)
{
    //std::cout << "Int constructor called" << std::endl;
    this->StoreNum = (num << FractionalBitsNum);
}

Fixed::Fixed(const float num)
{
    //std::cout << "Float constructor called" << std::endl;
    this->StoreNum = int(roundf(num * (1 << FractionalBitsNum)));
}

Fixed::~Fixed(void)
{
    //std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
    : StoreNum(fixed.StoreNum)
{
    //std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator = (const Fixed &fixed)
{
    //std::cout << "Copy assignment operator called" << std::endl;
    this->StoreNum = fixed.StoreNum;
    return *this;
}

int Fixed::getRawBits( void ) const
{
    //std::cout << "getRawBits member function called" << std::endl;
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

#pragma region Comparison operators
bool Fixed::operator >(const Fixed& fixed)
{
    return this->StoreNum > fixed.StoreNum;
}

bool Fixed::operator <(const Fixed& fixed)
{
    return this->StoreNum < fixed.StoreNum;
}

bool Fixed::operator >=(const Fixed& fixed)
{
    return this->StoreNum >= fixed.StoreNum;
}

bool Fixed::operator <=(const Fixed& fixed)
{
    return this->StoreNum <= fixed.StoreNum;
}

bool Fixed::operator ==(const Fixed& fixed)
{
    return this->StoreNum == fixed.StoreNum;
}

bool Fixed::operator !=(const Fixed& fixed)
{
    return this->StoreNum != fixed.StoreNum;
}
#pragma endregion

#pragma region Arithmetic operators
Fixed Fixed::operator +(const Fixed& fixed)
{
    Fixed returnFixed;

    returnFixed.setRawBits(this->StoreNum + fixed.StoreNum);
    return returnFixed;
}

Fixed Fixed::operator -(const Fixed& fixed)
{
    Fixed returnFixed;

    returnFixed.setRawBits(this->StoreNum - fixed.StoreNum);
    return returnFixed;
}

Fixed Fixed::operator *(const Fixed& fixed)
{
    Fixed returnFixed;

    returnFixed.setRawBits(this->StoreNum * fixed.StoreNum >> FractionalBitsNum);
    return returnFixed;
}

Fixed Fixed::operator /(const Fixed& fixed)
{
    Fixed returnFixed;

    returnFixed.setRawBits(this->StoreNum * (1 << FractionalBitsNum) / fixed.StoreNum);
    return returnFixed;
}
#pragma endregion

#pragma region Unary increment/decrement operators
Fixed& Fixed::operator++()
{
    this->StoreNum++;
    return *this;
}

Fixed& Fixed::operator--()
{
    this->StoreNum--;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed tmp = *this;
    ++*this;
    return tmp;
}

Fixed Fixed::operator--(int)
{
    Fixed tmp = *this;
    --*this;
    return tmp;
}
#pragma endregion

#pragma region Min/max
Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    return a < b? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    return a.StoreNum < b.StoreNum? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    return a > b? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    return a.StoreNum > b.StoreNum? a : b;
}

#pragma endregion

std::ostream& operator<<(std::ostream& o, const Fixed& fixed)
{
	o << fixed.toFloat();
	return o;
}