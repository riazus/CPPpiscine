#include "../includes/HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name) :
	name(name)
{
}

HumanB::~HumanB(void)
{
}

void HumanB::setWeapon(Weapon& weapon)
{
	this->weapon = &weapon;
}

void HumanB::attack(void) const
{
	std::cout << this->name << " attacks with his ";
	if (this->weapon)
		std::cout << this->weapon->getType();
	else
		std::cout << "bare fists";
	std::cout << std::endl;
}