#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    : Form("pardon", "default", 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : Form("pardon", target, 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &ppf)
    : Form(ppf)
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &ppf)
{
    Form::operator=(ppf);
    return *this;
}

void PresidentialPardonForm::action(const Bureaucrat& executor) const
{
    this->Form::execute(executor);
	std::cout << this->getTarget() << "has been pardoned by Zafod Beeblebrox." << std::endl;
}