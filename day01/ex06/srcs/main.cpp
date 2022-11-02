#include "../includes/Harl.hpp"
#include <iostream>

void putPhrases(int ind, std::string levels[4], Harl Harl)
{
	for (int j = 4; ind < j; ind++)
	{
		std::cout << "[ " << levels[ind] << " ]" << std::endl;
		Harl.complain(levels[ind]);
		std::cout << std::endl;
	}
}

int main(int argc, char **argv)
{
	Harl Harl;

	if (argc == 2)
	{
		std::string levels[4] = {
			"DEBUG",
			"INFO",
			"WARNING",
			"ERROR"
		};
		int i = 0;
		while (i < 4 && levels[i] != argv[1])
			i++;
		switch (i)
		{
			case 0:
				putPhrases(i, levels, Harl);
				break;
			case 1:
				putPhrases(i, levels, Harl);
				break;
			case 2:
				putPhrases(i, levels, Harl);
				break;
			case 3:
				putPhrases(i, levels, Harl);
				break;
			default:
				std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		}
	}
}