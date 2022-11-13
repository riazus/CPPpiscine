#include <iostream>

class Char
{
    public :
        Char();
        Char(char ch);
        Char(const Char &num);
        Char &operator=(const Char &num);
        ~Char();
        
        char getValue();
        void setValue(char ch);
        
    private :
        char value;

};

std::ostream& operator<<(std::ostream& o, const Char& ch);