#include "../includes/Form.hpp"
#include "../includes/Bureaucrat.hpp"

Form::Form()
    : name("Default"), target(""), isSigned(false), gradeSign(1), gradeExec(1)
{
    std::cout << "Default constructor was called" << std::endl;
}

Form::Form(const std::string &name, const std::string& target)
    : name(name), target(target), isSigned(false), gradeSign(1), gradeExec(1)
{
}

Form::Form(const std::string& name, const unsigned int gradeSign, const unsigned int gradeExec)
    : name(name), target(""), isSigned(false), gradeSign(gradeSign), gradeExec(gradeExec)
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

Form::Form(const std::string& name, const std::string& target, const unsigned int gradeSign, const unsigned int gradeExec)
        : name(name), target(target), isSigned(false), gradeSign(gradeSign), gradeExec(gradeExec)
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
    : name(form.name), target(form.target), isSigned(form.isSigned), gradeSign(form.gradeSign), gradeExec(form.gradeExec)
{
}

Form& Form::operator=(const Form& form)
{
    (void)form;
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

std::string Form::getTarget() const
{
	return this->target;
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

void Form::execute(const Bureaucrat& executor) const
{
	if (!this->getIsSigned())
	{
		throw Form::FormNotSignedException();
	}
	if (executor.getGrade() > this->getGradeExec())
	{
		throw Form::GradeTooLowException();
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

const char* Form::FormNotSignedException::what() const throw()
{
	return ("Form not signed yet");
}

std::ostream& operator<<(std::ostream& o, const Form& form)
{
	o << "Form " << form.getName() << ": ";
	o << "{signed: " << std::boolalpha << form.getIsSigned() << ", gradeSign: " << form.getGradeSign() 
    << ", gradeExec: " << form.getGradeExec() << "}";
	return o;
}