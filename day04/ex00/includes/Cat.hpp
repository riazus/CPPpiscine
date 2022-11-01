#pragma once
#include "Animal.hpp"

class Cat : public Animal
{
    public :
        Cat();
        Cat(std::string type);
        Cat(const Cat &cat);
        Cat &operator=(const Cat &cat);
        ~Cat();

        void makeSound() const;
};