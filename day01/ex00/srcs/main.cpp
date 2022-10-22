#include "../includes/Zombie.hpp"

int main(void)
{
    Zombie zombieOne("zombi1");
    Zombie *zombieTwo = newZombie("zombi2");
    zombieOne.announce();
    zombieTwo->announce();
    randomChump("zombi3");
    delete zombieTwo;
}