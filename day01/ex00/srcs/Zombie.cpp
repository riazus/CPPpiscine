#include "../includes/Zombie.hpp"

Zombie::Zombie(std::string name)
{
    Name = name;
    return;
}

Zombie::~Zombie(void)
{
    std::cout << "Destroyed " << Name << std::endl;
    return;
}

void Zombie::announce(void) const
{
    std::cout << this->Name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}