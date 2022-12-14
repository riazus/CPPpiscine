#include "../includes/Algoritm.hpp"

Algoritm::Algoritm(std::string filename, std::string s1, std::string s2)
{
    this->ReadFilePath = filename;
    this->s1 = s1;
    this->s2 = s2;
    return;
}

Algoritm::~Algoritm()
{
    return;
}

void Algoritm::WriteToNewFile(void)
{
    std::string fileLine;
    size_t indFind;
    std::ofstream writeFile(this->ReadFilePath + ".replace");
    std::ifstream readFile(this->ReadFilePath);

    while(std::getline(readFile, fileLine))
    {
        indFind = fileLine.find(this->s1);
        while (indFind != std::string::npos)
        {
            fileLine = Algoritm::MyReplace(fileLine, indFind, this->s1.length() + indFind, this->s2);
            indFind = fileLine.find(this->s1);
        }
        writeFile << fileLine << std::endl;
    }
    readFile.close();
    writeFile.close();
}

std::string Algoritm::MyReplace(std::string line, int start, int end, std::string dest)
{
    std::string firstPart = line.substr(0, start);
    std::string secondPart = line.substr(end, line.length());
    return firstPart + dest + secondPart;
}