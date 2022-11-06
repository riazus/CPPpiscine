#include "../includes/ClapTrap.hpp"

int main()
{
	ClapTrap john("John");
	ClapTrap jim("Jim");
	ClapTrap joe("Joe");
	int i = 0;

	while (!john.getIsDied() && !jim.getIsDied() && !joe.getIsDied())
	{
		std::cout << "********* " << i << " cycle" << " *********" << std::endl;
		john.attack(jim.getName());
		if (!john.getIsDied())
		{
			jim.takeDamage(john.getAttackDamage());
			jim.beRepaired(john.getAttackDamage());
		}

		jim.attack(joe.getName());
		if (!jim.getIsDied())
		{
			joe.takeDamage(jim.getAttackDamage());
			joe.beRepaired(jim.getAttackDamage());
		}

		joe.attack(john.getName());
		if (!joe.getIsDied())
		{
			john.takeDamage(joe.getAttackDamage());
			john.beRepaired(joe.getAttackDamage());
		}
		i++;
	}
}