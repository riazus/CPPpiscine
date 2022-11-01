#include "../includes/Dog.hpp"

Dog::Dog()
    : Animal("Dog")
{
    std::cout << "Dog's default constructor was called" << std::endl;
}

Dog::Dog(std::string type)
    : Animal(type)
{
    std::cout << "Dog's type constructor was called" << std::endl;
}

Dog::Dog(const Dog &dog)
    : Animal(dog)
{
    std::cout << "Dog's copy constructor was called" << std::endl;
}

Dog &Dog::operator=(const Dog &dog)
{
    this->type = dog.type;
    std::cout << "Dog's assignment operator was called" << std::endl;
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog's destructor was called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "GAF! GAF! GAF!" << std::endl;
}

Brain* Dog::getBrain() const
{
    return this->brain;
}