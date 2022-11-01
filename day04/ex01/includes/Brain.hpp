#pragma once
#include <iostream>

class Brain
{
	public:
		Brain();
		Brain(const Brain& other);
		Brain& operator=(const Brain& rhs);
		~Brain();

		const std::string& getIdea(int index) const;

	private:
		std::string ideas[100];
};
