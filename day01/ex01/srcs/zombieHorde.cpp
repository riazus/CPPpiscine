#include "../includes/Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    Zombie* zombies = new(std::nothrow) Zombie[N];
    if (zombies == NULL)
    {
        std::cout << "Bad allocation memory" << std::endl;
        std::exit(1);
    }
    for (int i = 0; i < N; i++)
    {
        zombies[i].setName(name + std::to_string(i + 1));
    }
    return zombies;
}