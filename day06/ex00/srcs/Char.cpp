#include "../includes/Char.hpp"

Char::Char()
{
}

Char::Char(char ch)
    : value(ch)
{
}

Char::Char(const Char &ch)
    : value(ch.value)
{
}

Char &Char::operator=(const Char &ch)
{
    this->value = ch.value;
    return *this;
}

Char::~Char()
{
}

