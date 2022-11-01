#pragma once
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    public :
        WrongCat();
        WrongCat(std::string type);
        WrongCat(const WrongCat &WrongCat);
        WrongCat &operator=(const WrongCat &WrongCat);
        ~WrongCat();

        void makeSound() const;
};