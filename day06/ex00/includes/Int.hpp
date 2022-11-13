#include <iostream>

class Int
{
    public :
        Int();
        Int(int num);
        Int(const Int &num);
        Int &operator=(const Int &num);
        ~Int();

    private :
        int value;

};

std::ostream& operator<<(std::ostream& o, const Int& num);