#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
    public :
        Dog();
        Dog(std::string type);
        Dog(const Dog &Dog);
        Dog &operator=(const Dog &Dog);
        ~Dog();

        void makeSound() const;
        Brain *getBrain() const;

    private :
        Brain *brain;
};