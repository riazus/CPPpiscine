#include "../includes/ScavTrap.hpp"

int main()
{
	ClapTrap john("John");
	ClapTrap jim("Jim");
	ClapTrap joe("Joe");
	ScavTrap jane("Jane");
	int i = 0;

	while (!john.getIsDied() || !jim.getIsDied() || !joe.getIsDied() || !jane.getIsDied())
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
		jane.attack(john.getName());

		if(!jane.getIsDied())
		{
			john.takeDamage(jane.getAttackDamage());
			john.beRepaired(jane.getAttackDamage());
		}
		i++;
	}
}