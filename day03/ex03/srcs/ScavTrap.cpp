#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap()
	: ClapTrap()
{
	std::cout << "ScavTrap(void) constructor called" << std::endl;
	this->hp = 100;
	this->ep = 50;
	this->ad = 20;
}

ScavTrap::ScavTrap(std::string name)
	: ClapTrap(name)
{
	std::cout << "ScavTrap(\"" << name << "\") constructor called" << std::endl;
	this->hp = 100;
	this->ep = 50;
	this->ad = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other)
	: ClapTrap(other)
{
	std::cout << "ScavTrap copy constructor called on " << other.name << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& scavTrap)
{
	ClapTrap::operator=(scavTrap);
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called for " << this->name << std::endl;
}

void ScavTrap::attack(std::string const & target)
{
	std::cout << "ScavTrap " << this->name;
	if (this->ep > 0)
	{
		this->ep -= 5;
		std::cout << " attacked " << target << ", causing " << this->ad << " points of damage!" << std::endl;
	}
	else
		std::cout << " has too little energy points to attack." << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->name << " has entered Gate keeper mode!" << std::endl;
}