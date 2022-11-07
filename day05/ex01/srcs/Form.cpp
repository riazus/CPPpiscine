#include "../includes/Form.hpp"
#include "../includes/Bureaucrat.hpp"

Form::Form()
    : name("Default"), isSigned(false), gradeSign(1), gradeExec(1)
{
    std::cout << "Default constructor was called" << std::endl;
}

Form::Form(const std::string &name)
    : name(name), isSigned(false), gradeSign(1), gradeExec(1)
{
}

Form::Form(const std::string& name, const unsigned int gradeSign, const unsigned int gradeExec)
    : name(name), isSigned(false), gradeSign(gradeSign), gradeExec(gradeExec)
{
    if (gradeSign < 1 || gradeExec < 1)
    {
        throw Form::GradeTooHighException();
    }
    else if (gradeSign > 150 || gradeExec > 150)
    {
        throw Form::GradeTooLowException();
    }
}

Form::Form(const Form &form)
    : name(form.name), isSigned(form.isSigned), gradeSign(form.gradeSign), gradeExec(form.gradeExec)
{
}

Form& Form::operator=(const Form& form)
{
    this->isSigned = form.isSigned;
    return *this;
}

Form::~Form()
{
}

unsigned int Form::getGradeSign() const
{
	return this->gradeSign;
}

unsigned int Form::getGradeExec() const
{
	return this->gradeExec;
}

std::string Form::getName() const
{
	return this->name;
}

bool Form::getIsSigned() const
{
	return this->isSigned;
}

void Form::beSigned(const Bureaucrat& candidate)
{
    if (!this->isSigned)
	{
		if (candidate.getGrade() <= this->gradeSign)
        {
			this->isSigned = true;
        }
		else
        {
			throw Form::GradeTooLowException();
        }
	}
	else
    {
		throw Form::FormAlreadySignedException();
    }
}

const char* Form::GradeTooLowException::what() const throw()
{
    return ("Grade too low");
}

const char* Form::GradeTooHighException::what() const throw()
{
    return ("Grade too high");
}

const char* Form::FormAlreadySignedException::what() const throw()
{
    return ("Form is already signed");
}

std::ostream& operator<<(std::ostream& o, const Form& form)
{
	o << "Form " << form.getName() << ": ";
	o << "{signed: " << std::boolalpha << form.getIsSigned() << ", gradeSign: " << form.getGradeSign() 
    << ", gradeExec: " << form.getGradeExec() << "}";
	return o;
}