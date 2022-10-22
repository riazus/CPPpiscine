#include "../includes/Validator.hpp"
#include "../includes/Algoritm.hpp"

int main(int argc, char **argv)
{
    Validator::Validate(argc, argv);
    Algoritm algoritm(argv[1], argv[2], argv[3]);
    algoritm.WriteToNewFile();
}