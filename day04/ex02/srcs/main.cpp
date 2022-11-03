#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include <iomanip>

int main()
{
	Animal *animal[4];
	for (int i = 0; i < 4; i++)
	{
		if (i % 2)
			animal[i] = new Dog();
		else
			animal[i] = new Cat();
	}
	std::cout << std::endl;
	for (int i = 0; i < 4; i++)
		delete animal[i];

	std::cout << std::endl;
	const Animal *dog = new Dog();
	const Animal *cat = new Cat();
	std::cout << std::endl;
	delete dog;
	delete cat;

	std::cout << std::endl;
	Dog *first = new Dog;
	Dog *second = new Dog(*first);
	second->getBrain()->getIdea(0);
	std::cout << std::endl;
	delete first;
	delete second;

	return (0);
}