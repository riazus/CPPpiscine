#pragma once
#include <iostream>
#include <string>

class Zombie
{
    public :
        Zombie(std::string name);
        ~Zombie();
        void announce( void ) const;

    private :
        std::string Name;
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );