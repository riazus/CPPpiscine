#include "Form.hpp"

class PresidentialPardonForm : public Form
{
    public :
        PresidentialPardonForm();
        PresidentialPardonForm(const std::string &target);
        PresidentialPardonForm(const PresidentialPardonForm &ppf);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &ppf);
        ~PresidentialPardonForm();

        void action(const Bureaucrat& executor) const;
};