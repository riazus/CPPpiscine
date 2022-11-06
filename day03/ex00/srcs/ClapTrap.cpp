#include "../includes/ClapTrap.hpp"

ClapTrap::ClapTrap()
    : name("default"), hp(10), ep(10), ad(0)
{
    std::cout << "Default constructor was called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
    : name(name), hp(10), ep(10), ad(0)
{
    std::cout << "Constructor with name parameters was called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& clapTrap)
    : name(clapTrap.name), hp(clapTrap.hp), ep(clapTrap.ep), ad(clapTrap.ad)
{
    std::cout << "Default constructor was called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& clapTrap)
{
    this->name = clapTrap.name;
    this->ad = clapTrap.ad;
    this->hp = clapTrap.hp;
    this->ep = clapTrap.ep;
    return *this;
}

ClapTrap::~ClapTrap()
{
}

void ClapTrap::attack(std::string const & target)
{
    std::cout << "ClapTrap " << this->name;
	if (this->ep > 0)
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

void ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << "ClapTrap " << this->name;
    if (this->hp == 0)
    {
        std::cout << " is already dead, enough!" << std::endl;
    }
    else if (amount >= this->hp)
    {
        this->isDied = true;
        std::cout << " is died" << std::endl;
    }
    else
    {
        this->hp -= amount;
        std::cout << " took " << amount << " points damage"
        << ". There is also " << this->hp << " hp" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    std::cout << "ClapTrap " << this->name;
	if (this->ep > 0)
	{
		this->ep -= 1;
        this->hp += amount;
		std::cout << " is healed " << amount << " hit points, now has " 
        << this->hp << " hit points." << std::endl;
	}
	else
    {
        this->isDied = true;
		std::cout << " has too little energy points to repair." << std::endl;
    }
}

std::string ClapTrap::getName() const
{
    return this->name;
}

unsigned int ClapTrap::getAttackDamage() const
{
    return this->ad;
}