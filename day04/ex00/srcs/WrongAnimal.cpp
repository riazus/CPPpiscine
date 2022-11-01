#include "../includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
    : type("default")
{
    std::cout << "WrongAnimal's default constructor was called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type)
    : type(type)
{
    std::cout << "WrongAnimal's type constructor was called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &WrongAnimal)
    : type(WrongAnimal.type)
{
    std::cout << "WrongAnimal's copy constructor was called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &WrongAnimal)
{
    this->type = WrongAnimal.type;
    std::cout << "WrongAnimal's assignment operator was called" << std::endl;
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal's destructor was called" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return this->type;
}

void WrongAnimal::makeSound() const
{
	std::cout << "Default WrongAnimal sound" << std::endl;
}