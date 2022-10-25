#pragma once
#include <string>
#include <iostream>
#include <fstream>

class Validator
{
    public :
        Validator();
        ~Validator();
        static void Validate(int argc, char **argv);

    private :
        static void validateFile(std::string filepath);
};