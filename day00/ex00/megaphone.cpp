#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    }
    else
    {
        for(int i = 1; argv[i]; i++)
        {
            for(int j = 0; argv[i][j]; j++)
            {
                putchar(std::toupper(argv[i][j]));
            }
        }
    }
    putchar('\n');
    return 0;
}