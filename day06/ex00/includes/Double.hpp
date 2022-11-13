#include <iostream>

class Double
{
    public :
        Double();
        Double(double num);
        Double(const Double &num);
        Double &operator=(const Double &num);
        ~Double();

    private :
        double value;

};

std::ostream& operator<<(std::ostream& o, const Double& num);