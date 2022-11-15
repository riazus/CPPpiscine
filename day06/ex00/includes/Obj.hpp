#include <iostream>
#include <string>
#include <limits>

class Obj
{
    public :
        Obj(std::string str);
        Obj(const Obj &obj);
        Obj &operator=(const Obj &obj);
        ~Obj();

        char toChar() const;
        int toInt() const;
        float toFloat() const;
        double toDouble() const;

        class InvalidInput : public std::exception
        {
        public:
            virtual const char* what() const throw();
        };

        class Impossible : public std::exception
        {
        public:
            virtual const char* what() const throw();
        };

        class NonDisplayable : public std::exception
        {
        public:
            virtual const char* what() const throw();
        };


    private :
        std::string &string;
        int         intVal;
        float       floatVal;
        double      doubleVal;
        char        charVal;

        enum objType
        {
            Int,
            Float,
            Double,
            Char
        } type; 
};

std::ostream& operator<<(std::ostream& o, const Obj& obj);