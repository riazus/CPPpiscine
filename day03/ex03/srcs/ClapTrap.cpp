#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap()
	: name("default"), hp(10), ep(10), ad(0)
{
	std::cout << "ClapTrap(void) constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
	: name(name), hp(10), ep(10), ad(0)
{
	std::cout << "ClapTrap(\"" << name << "\") constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
	: name(other.name), hp(other.hp), ep(other.ep), ad(other.ad) 
{
	std::cout << "ClapTrap copy constructor called on " << other.name << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& clapTrap)
{
	this->name = clapTrap.name;
	this->hp = clapTrap.hp;
	this->ep = clapTrap.ep;
	this->ad = clapTrap.ad;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called for " << this->name << std::endl;
}

void ClapTrap::attack(std::string const & target)
{
	std::cout << "ClapTrap " << this->name;
	if (this->ep > 0)
	{
		this->ep -= 5;
		std::cout << " attacked " << target << ", causing " << this->ad << " points of damage!" << std::endl;
	}
	else
		std::cout << " has too little energy points to attack." << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->name;
	if (this->hp == 0)
		std::cout << " is already dead, stop it!";
	else if (amount > this->hp)
	{
		std::cout << " takes " << this->hp << " damage and dies!" << std::endl;
		this->hp = 0;
	}
	else
	{
		this->hp -= amount;
		std::cout << " takes " << amount << " damage, " << this->hp << " hp remaining!" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	this->hp += amount;
	std::cout << "ClapTrap " << this->name << " is healed " << amount << " hit points, now has " << this->hp << " hit points." << std::endl;
}
