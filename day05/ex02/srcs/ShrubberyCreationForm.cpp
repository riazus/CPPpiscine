#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
	: Form("shrubbery", "default", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: Form("shrubbery", target, 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: Form(other)
{	
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs)
{
	this->Form::operator=(rhs);
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

const char* ShrubberyCreationForm::ErrorOpenFile::what() const throw()
{
	return("Error open file.");
}

void ShrubberyCreationForm::action(const Bureaucrat& executor) const
{
	this->Form::execute(executor);
	std::string blyat = (this->getTarget() + "_shrubbery");
	std::ofstream ofs;
	ofs.open(blyat.c_str());
	if(ofs.fail())
		throw ShrubberyCreationForm::ErrorOpenFile();

	ofs << "               ,@@@@@@@," << std::endl;
	ofs << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
	ofs << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl;
	ofs << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
	ofs << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
	ofs << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
	ofs << "   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
	ofs << "       |o|        | |         | |" << std::endl;
	ofs << "       |.|        | |         | |" << std::endl;
	ofs << "    \\/ .\\////  ,\\//\\/.  \\///" << std::endl;
	
	ofs.close();
}