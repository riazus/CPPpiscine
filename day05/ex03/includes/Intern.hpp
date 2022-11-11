#include "Form.hpp"

class Intern
{
    public:
        Intern();
        ~Intern();

        class InvalidFormException : public std::exception
        {
        public:
            virtual const char* what() const throw();
        };

        Form* makeForm(const std::string& formName, const std::string& target) const;
};