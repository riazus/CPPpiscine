#include "../includes/Harl.hpp"
#include <iostream>

int main()
{
	Harl Harl;

	std::cout << "DEBUG: " << std::endl;
	Harl.complain("DEBUG");
	std::cout << "INFO: " << std::endl;
	Harl.complain("INFO");
	std::cout << "WARNING: " << std::endl;
	Harl.complain("WARNING");
	std::cout << "ERROR: " << std::endl;
	Harl.complain("ERROR");
}