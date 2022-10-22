#include "../includes/Validator.hpp"

void Validator::Validate(int argc, char **argv)
{
    if (argc == 4)
    {
        Validator::validateFile(argv[1]);
    }
    else
    {
        std::cout << "Please, write 3 args: file name and 2 strings for replacement" << std::endl;
        std::exit(1);
    }
}

void Validator::validateFile(std::string filepath)
{
    std::ifstream f;
    f.open(filepath);
    if (!f)
    {
        std::cout << "Error file name or path" << std::endl;
        std::exit(1);
    }
}