#include "DiamondTrap.hpp"

int main()
{
	ClapTrap john("John");
	ClapTrap jim("Jim");
	ClapTrap joe("Joe");
	ScavTrap jane("Jane");
	FragTrap joseph("Joseph");
	DiamondTrap daniel("Daniel");
	int i = 0;

	while (!john.getIsDied() || !jim.getIsDied() || !joe.getIsDied() 
			|| !jane.getIsDied() || !joseph.getIsDied())
	{
		std::cout << "********* " << i << " cycle" << " *********" << std::endl;

		john.attack(jim.getName());
		if (!john.getIsDied())
		{
			jim.beRepaired(john.getAttackDamage());
			jim.takeDamage(john.getAttackDamage());
		}
		jim.attack(joe.getName());

		if (!jim.getIsDied())
		{
			joe.takeDamage(jim.getAttackDamage());
			joe.beRepaired(jim.getAttackDamage());
		}
		joe.attack(jane.getName());

		if (!joe.getIsDied())
		{
			jane.takeDamage(joe.getAttackDamage());
			jane.beRepaired(joe.getAttackDamage());
		}
		jane.attack(joseph.getName());

		if(!jane.getIsDied())
		{
			joseph.takeDamage(jane.getAttackDamage());
			joseph.beRepaired(jane.getAttackDamage());
		}
		
		joseph.attack(daniel.getName());
		if(!joseph.getIsDied())
		{
			daniel.takeDamage(joseph.getAttackDamage());
			daniel.beRepaired(joseph.getAttackDamage());
		}

		daniel.attack(john.getName());
		if(!daniel.getIsDied())
		{
			john.takeDamage(daniel.getAttackDamage());
			john.beRepaired(daniel.getAttackDamage());
		}
		i++;
	}
	
	daniel.guardGate();
	daniel.highFivesGuys();
	daniel.whoAmI();
}