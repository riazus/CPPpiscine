#include "../includes/Zombie.hpp"

int main(void)
{
    int zombieCount;
    std::cout << "Write count of zombies" << std::endl;
    std::cin >> zombieCount;
    Zombie* zombies = zombieHorde(zombieCount, "zOmBi");
    for(int i = 0; i < zombieCount; i++)
    {
        zombies[i].announce();
    }
    delete []zombies;
}