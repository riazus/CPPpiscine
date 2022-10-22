#include "../includes/Fixed.hpp"

Fixed::Fixed(void)
{
    std::cout << "Default constructor called" << std::endl;
    this->StoreNum = 0;
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