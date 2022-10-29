#include <iostream>
#include <string>

int main(void)
{
    std::string str1 = "HI THIS IS BRAIN";
    std::string &stringREF = str1;
    std::string *stringPTR = &str1;

    std::cout << "Memory adress of string: " << &str1 << std::endl;
    std::cout << "Memory adress of reference: " << &stringREF << std::endl;
    std::cout << "Memory adress of pointer: " << stringPTR << std::endl;

    std::cout << "Value of string: " << str1 << std::endl;
    std::cout << "Value of reference: " << stringREF << std::endl;
    std::cout << "Value of pointer: " << *stringPTR << std::endl;
}