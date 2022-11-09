#include "../includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
    : Form("pardon", "default", 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : Form("pardon", target, 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &rrf)
    : Form(rrf)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rrf)
{
    Form::operator=(rrf);
    return *this;
}

void RobotomyRequestForm::action(const Bureaucrat& executor) const
{
    this->Form::execute(executor);
	std::cout << "Makes some drilling noises" << std::endl;
	if (std::rand() < RAND_MAX / 2)
		std::cout << this->getTarget() << " has been robotomized successfully." << std::endl;
	else
		std::cout << "Robotomy on " << this->getTarget() << " has failed." << std::endl;
}