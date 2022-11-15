#include <iostream>
#include <string>
#include "../includes/Obj.hpp"

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		try
		{
			Obj obj(argv[1]);
			std::cout << obj;
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	else
		std::cerr << "Usage: ./convert <value>" << std::endl;
}