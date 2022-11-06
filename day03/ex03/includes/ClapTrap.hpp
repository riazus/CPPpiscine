#pragma once
#include <string>
#include <iostream>

class ClapTrap
{
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& clapTrap);
		ClapTrap& operator=(const ClapTrap& clapTrap);
		~ClapTrap();

		void attack(std::string const & target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		std::string getName() const;
		unsigned int getAttackDamage() const;
		bool getIsDied() const;

	protected:
		std::string		name;
		unsigned int	hp;
		unsigned int	ep;
		unsigned int	ad;
		bool 			isDied;
};