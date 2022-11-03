#pragma once
#include <iostream>

class Brain
{
	public:
		Brain();
		Brain(const Brain& brain);
		Brain& operator=(const Brain& brain);
		~Brain();

		const std::string& getIdea(int index) const;

	private:
		std::string ideas[100];
};
