#include "../includes/WrongCat.hpp"

WrongCat::WrongCat()
    : WrongAnimal("WrongCat")
{
    std::cout << "WrongCat's default constructor was called" << std::endl;
}

WrongCat::WrongCat(std::string type)
    : WrongAnimal(type)
{
    std::cout << "WrongCat's type constructor was called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &WrongCat)
    : WrongAnimal(WrongCat)
{
    std::cout << "WrongCat's copy constructor was called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &WrongCat)
{
    this->type = WrongCat.type;
    std::cout << "WrongCat's assignment operator was called" << std::endl;
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat's destructor was called" << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "meow" << std::endl;
}