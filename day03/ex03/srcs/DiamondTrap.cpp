#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap()
	: ClapTrap("defaultclapname"), ScavTrap(), FragTrap(), name("default")
{
	std::cout << "DiamondTrap(void) constructor called" << std::endl;
	this->FragTrap::hp = 100;
	this->ScavTrap::ep = 50;
	this->FragTrap::ad = 30;
}

DiamondTrap::DiamondTrap(std::string name)
	: ClapTrap(name + "clapname"), ScavTrap(), FragTrap(), name(name)
{
	std::cout << "DiamondTrap(\"" << name << "\") constructor called" << std::endl;
	this->FragTrap::hp = 100;
	this->ScavTrap::ep = 50;
	this->FragTrap::ad = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
	: ClapTrap(other), ScavTrap(), FragTrap()
{
	std::cout << "DiamondTrap copy constructor called on " << other.name << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& diamondTrap)
{
	ClapTrap::operator=(diamondTrap);
	ScavTrap();
	FragTrap();
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called for " << this->name << std::endl;
}

void DiamondTrap::attack(std::string const & target)
{
	this->ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "whoAmI(): I am DiamondTrap " << this->name << " and my ClapTrap name is " << this->ClapTrap::name << std::endl;
}