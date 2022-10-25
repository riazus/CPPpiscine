#pragma once
#include <iostream>
#include <string>

class Zombie
{
    public :
        Zombie(void);
        ~Zombie(void);
        void announce( void ) const;
        void setName(std::string name);

    private :
        std::string Name;
};

Zombie* zombieHorde( int N, std::string name );