#pragma once
#include <string>

class Weapon
{
private:
    std::string type;

public:
    Weapon(std::string type);
    ~Weapon();
    std::string getType() const;
    void setType(std::string newtype);
};
