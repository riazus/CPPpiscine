#include "Form.hpp"

class ShrubberyCreationForm : public Form
{
    public :
        ShrubberyCreationForm(const std::string &target);
        ShrubberyCreationForm(const ShrubberyCreationForm &scf);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &scf);
        ~ShrubberyCreationForm();

        void action(const Bureaucrat& executor) const;
    private :
        ShrubberyCreationForm();
};