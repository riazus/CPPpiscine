#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap()
	: ClapTrap()
{
	std::cout << "FragTrap(void) constructor called" << std::endl;
	this->hp = 100;
	this->ep = 100;
	this->ad = 30;
}

FragTrap::FragTrap(std::string name)
	: ClapTrap(name)
{
	std::cout << "FragTrap(\"" << name << "\") constructor called" << std::endl;
	this->hp = 100;
	this->ep = 100;
	this->ad = 30;
}

FragTrap::FragTrap(const FragTrap& other)
	: ClapTrap(other)
{
	std::cout << "FragTrap copy constructor called on " << other.name << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& fragTrap)
{
	ClapTrap::operator=(fragTrap);
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called for " << this->name << std::endl;
}

void FragTrap::attack(std::string const & target)
{
	std::cout << "FragTrap " << this->name;
	if (this->ep > 0)
	{
		this->ep -= 5;
		std::cout << " attacked " << target << ", causing " << this->ad << " points of damage!" << std::endl;
	}
	else
		std::cout << " has too little energy points to attack." << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << this->name << " would like to high five everyone!" << std::endl;
}