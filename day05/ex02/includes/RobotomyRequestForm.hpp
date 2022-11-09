#include "Form.hpp"

class RobotomyRequestForm : public Form
{
    public :
        RobotomyRequestForm();
        RobotomyRequestForm(const std::string &target);
        RobotomyRequestForm(const RobotomyRequestForm &rrf);
        RobotomyRequestForm &operator=(const RobotomyRequestForm &rrf);
        ~RobotomyRequestForm();

        void action(const Bureaucrat& executor) const;
};