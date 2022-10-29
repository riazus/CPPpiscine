#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(const FragTrap& other);
	FragTrap& operator=(const FragTrap& fragTrap);
	~FragTrap();

	void attack(std::string const & target);
	void highFivesGuys();
};