#include "../includes/Dog.hpp"

Dog::Dog()
    : Animal("Dog"), brain(new Brain())
{
    std::cout << "Dog's default constructor was called" << std::endl;
}

Dog::Dog(std::string type)
    : Animal(type), brain(new Brain())
{
    std::cout << "Dog's type constructor was called" << std::endl;
}

Dog::Dog(const Dog &dog)
    : Animal(dog)
{
    this->brain = new Brain(*dog.brain);
    std::cout << "Dog's copy constructor was called" << std::endl;
}

Dog &Dog::operator=(const Dog &dog)
{
    this->brain = new Brain(*dog.brain);
    this->type = dog.type;
    std::cout << "Dog's assignment operator was called" << std::endl;
    return *this;
}

Dog::~Dog()
{
    delete this->brain;
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