#include <iostream>

class Float
{
    public :
        Float();
        Float(float num);
        Float(const Float &num);
        Float &operator=(const Float &num);
        ~Float();

    private :
        float value;

};

std::ostream& operator<<(std::ostream& o, const Float& num);