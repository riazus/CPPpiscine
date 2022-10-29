#pragma once
#include "../includes/ScavTrap.hpp"
#include "../includes/FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
    public:
        DiamondTrap();
        DiamondTrap(std::string name);
        DiamondTrap(const DiamondTrap& other);
        DiamondTrap& operator=(const DiamondTrap& diomandTrap);
        ~DiamondTrap();

        void attack(std::string const & target);
        void whoAmI();

    private:
        std::string name;
};