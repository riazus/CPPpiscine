#pragma once
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
    public :
        FragTrap();
        FragTrap(std::string name);
        FragTrap(const FragTrap& other);
        FragTrap& operator=(const FragTrap& rhs);
        ~FragTrap();
        
        void attack(std::string const & target);
	    void highFivesGuys();
};