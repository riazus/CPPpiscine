#pragma once
#include <iostream>

class Animal
{
    public :
        Animal();
        Animal(std::string type);
        Animal(const Animal &animal);
        Animal &operator=(const Animal &animal);
        virtual ~Animal();

        std::string getType() const;
        virtual void makeSound() const;

    protected :
        std::string type;
};