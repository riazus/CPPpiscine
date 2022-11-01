#pragma once
#include "Animal.hpp"

class Dog : public Animal
{
    public :
        Dog();
        Dog(std::string type);
        Dog(const Dog &Dog);
        Dog &operator=(const Dog &Dog);
        ~Dog();

        void makeSound() const;
};