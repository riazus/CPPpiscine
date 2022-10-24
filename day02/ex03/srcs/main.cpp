#include "../includes/Point.hpp"

int main( void ) 
{
    std::cout << std::to_string(bsp(Point(2, 1), Point(6, 3), Point(2, 4), Point(3, 3))) << std::endl;

    std::cout << std::to_string(bsp(Point(2, 1), Point(6, 3), Point(2, 4), Point(1, 1))) << std::endl;

    std::cout << std::to_string(bsp(Point(2, 1), Point(6, 3), Point(2, 4), Point(4, 2.5))) << std::endl;

    std::cout << std::to_string(bsp(Point(2, 1), Point(6, 3), Point(2, 4), Point(2, 4))) << std::endl;
}