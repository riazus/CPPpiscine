#include "../includes/ShrubberyCreationForm.hpp"
#include <fstream>
#include <cstdlib> 

ShrubberyCreationForm::ShrubberyCreationForm()
    : Form("pardon", "default", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : Form("pardon", target, 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &rrf)
    : Form(rrf)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rrf)
{
    Form::operator=(rrf);
    return *this;
}

void ShrubberyCreationForm::action(const Bureaucrat& executor) const
{
    this->Form::execute(executor);
	std::string newStr = this->getTarget() + "_shrubbery";
	std::ofstream ofs;

	if (!ofs.is_open())
    {
        std::cout << "Error to open file" << std::endl;
        std::exit(1);
    }
	ofs << "               ,@@@@@@@," << std::endl;
	ofs << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
	ofs << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl;
	ofs << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
	ofs << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
	ofs << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
	ofs << "   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
	ofs << "       |o|        | |         | |" << std::endl;
	ofs << "       |.|        | |         | |" << std::endl;
	ofs << "    \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_" << std::endl;
}