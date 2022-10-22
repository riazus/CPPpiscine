#include "../includes/Zombie.hpp"

Zombie::Zombie(void)
{
    return;
}

Zombie::~Zombie(void)
{
    std::cout << "Destroyed " << Name << std::endl;
    return;
}

void Zombie::setName(std::string name)
{
    this->Name = name;
}

void Zombie::announce(void) const
{
    std::cout << this->Name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}