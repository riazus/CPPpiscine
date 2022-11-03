#include "../includes/Brain.hpp"

Brain::Brain()
{
	const std::string examples[] = {
		"I want to sleep",
		"I want food",
		"I want pets",
		"I want to go for a walk",
		"I want water",
		"I want a treat"
	};
	for (int i = 0; i < 100; i++)
	{
		this->ideas[i] = examples[i % (sizeof(examples) / sizeof(std::string))];
	}
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain& brain)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = brain.ideas[i];
	std::cout << "Brain copy constructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& brain)
{
	if (this != &brain)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = brain.ideas[i];
	}
	std::cout << "Brain's assignment operator was called" << std::endl;
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

const std::string& Brain::getIdea(int index) const
{
	return this->ideas[index];
}