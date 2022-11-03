#include "../includes/Cat.hpp"

Cat::Cat()
    : Animal("Cat"), brain(new Brain())
{
    std::cout << "Cat's default constructor was called" << std::endl;
}

Cat::Cat(std::string type)
    : Animal(type), brain(new Brain())
{
    std::cout << "Cat's type constructor was called" << std::endl;
}

Cat::Cat(const Cat &cat)
    : Animal(cat)
{
    this->brain = cat.brain;
    std::cout << "Cat's copy constructor was called" << std::endl;
}

Cat &Cat::operator=(const Cat &cat)
{
    this->brain = new Brain(*cat.brain);
    this->type = cat.type;
    std::cout << "Cat's assignment operator was called" << std::endl;
    return *this;
}

Cat::~Cat()
{
    delete this->brain;
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