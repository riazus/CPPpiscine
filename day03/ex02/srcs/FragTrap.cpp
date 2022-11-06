#include "../includes/FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap()
	: ClapTrap()
{
	std::cout << "FragTrap default constructor was called" << std::endl;
	this->hp = 100;
	this->ep = 100;
	this->ad = 30;
}

FragTrap::FragTrap(std::string name)
	: ClapTrap(name)
{
	std::cout << "FragTrap constructor with name parameters was called" << std::endl;
	this->hp = 100;
	this->ep = 100;
	this->ad = 30;
}

FragTrap::FragTrap(const FragTrap& other)
	: ClapTrap(other)
{
	std::cout << "FragTrap copy constructor called on " << other.name << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& rhs)
{
	ClapTrap::operator=(rhs);
	std::cout << "FragTrap assigment operator was called" << std::endl;
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called for " << this->name << std::endl;
}

void FragTrap::attack(std::string const & target)
{
	std::cout << "FragTrap " << this->name;
	if (this->ep > 0 && this->hp > 0)
	{
		this->ep -= 1;
		std::cout << " attacked " << target << ", causing " << this->ad << " points of damage!" << std::endl;
	}
	else
	{
		this-> isDied = true;
		std::cout << " has too little energy points to attack." << std::endl;
	}
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << this->name << " would like to high five everyone!" << std::endl;
}