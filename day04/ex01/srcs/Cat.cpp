#include "../includes/Cat.hpp"

Cat::Cat()
    : Animal("Cat")
{
    std::cout << "Cat's default constructor was called" << std::endl;
}

Cat::Cat(std::string type)
    : Animal(type)
{
    std::cout << "Cat's type constructor was called" << std::endl;
}

Cat::Cat(const Cat &cat)
    : Animal(cat)
{
    std::cout << "Cat's copy constructor was called" << std::endl;
}

Cat &Cat::operator=(const Cat &cat)
{
    this->type = cat.type;
    std::cout << "Cat's assignment operator was called" << std::endl;
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat's destructor was called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "mur mur" << std::endl;
}

Brain* Cat::getBrain() const
{
    return this->brain;
}