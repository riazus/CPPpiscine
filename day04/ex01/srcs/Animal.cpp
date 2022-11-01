#include "../includes/Animal.hpp"

Animal::Animal()
    : type("default")
{
    std::cout << "Animal's default constructor was called" << std::endl;
}

Animal::Animal(std::string type)
    : type(type)
{
    std::cout << "Animal's type constructor was called" << std::endl;
}

Animal::Animal(const Animal &animal)
    : type(animal.type)
{
    std::cout << "Animal's copy constructor was called" << std::endl;
}

Animal &Animal::operator=(const Animal &animal)
{
    this->type = animal.type;
    std::cout << "Animal's assignment operator was called" << std::endl;
    return *this;
}

Animal::~Animal()
{
    std::cout << "Animal's destructor was called" << std::endl;
}

std::string Animal::getType() const
{
    return this->type;
}

void Animal::makeSound() const
{
	std::cout << "Default animal sound" << std::endl;
}