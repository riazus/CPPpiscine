#include "../includes/Form.hpp"
#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
    : name("Default"), grade(150)
{
    //std::cout << "Default constructor was called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade)
    : name(name)
{
    if (grade > 150)
    {
        Bureaucrat::GradeTooHighException();
    }
    else if (grade < 1)
    {
        Bureaucrat::GradeTooLowException();
    }
    else
    {
        this->grade = grade;
    }
}

Bureaucrat::Bureaucrat(Bureaucrat &bur)
    : name(bur.name), grade(bur.grade)
{
    //std::cout << "Copy constructor was called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat &bur)
{
    this->name = bur.name;
    this->grade = bur.grade;
    //std::cout << "Assingment operator was called" << std::endl;
    return *this;
}

Bureaucrat::~Bureaucrat()
{
    //std::cout << "Default destructor was called" << std::endl;
}

void Bureaucrat::incrementGrade()
{
	if (this->grade <= 1)
    {
		throw Bureaucrat::GradeTooHighException();
    }
	else
    {
		this->grade--;
    }
}

void Bureaucrat::decrementGrade()
{
	if (this->grade >= 150)
    {
		throw Bureaucrat::GradeTooLowException();
    }
	else
    {
		this->grade++;
    }
}

std::string Bureaucrat::getName() const
{
    return this->name;
}

unsigned int Bureaucrat::getGrade() const
{
    return this->grade;
}

void Bureaucrat::signForm(Form &form) const
{
    try
	{
		form.beSigned(*this);
		std::cout << *this << " signed " << form << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << *this << " cannot sign " << form << " because " << e.what() << std::endl;
	}
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade too low");
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade too high");
}

std::ostream& operator<<(std::ostream& o, const Bureaucrat& bur)
{
	o << bur.getName() << ", bureaucrat grade " << bur.getGrade();
	return o;
}