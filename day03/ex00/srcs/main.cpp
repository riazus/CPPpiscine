#include "../includes/ClapTrap.hpp"

int main()
{
	ClapTrap john("John");
	ClapTrap jim("Jim");
	ClapTrap joe("Joe");
	int i = 0;

	while (!john.isDied && !jim.isDied && !joe.isDied)
	{
		std::cout << "********* " << i << " cycle" << " *********" << std::endl;
		john.attack(jim.getName());
		jim.takeDamage(john.getAttackDamage());
		jim.beRepaired(john.getAttackDamage());
		jim.attack(joe.getName());
		joe.takeDamage(jim.getAttackDamage());
		joe.beRepaired(jim.getAttackDamage());
		joe.attack(john.getName());
		john.takeDamage(joe.getAttackDamage());
		john.beRepaired(joe.getAttackDamage());
		i++;
	}
}