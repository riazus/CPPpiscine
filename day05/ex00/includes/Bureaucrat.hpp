#include <iostream>
#include <string>

class Bureaucrat
{
    public :
        Bureaucrat();
        Bureaucrat(std::string name, unsigned int grade);
        Bureaucrat(Bureaucrat &bur);
        Bureaucrat &operator=(Bureaucrat &bur);
        ~Bureaucrat();

        std::string getName() const;
        int getGrade() const;
        void incrementGrade();
	    void decrementGrade();

        class GradeTooHighException : public std::exception
        {
            public :
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public :
                virtual const char* what() const throw();
        };

    private :
        std::string name;
        int         grade;
};

std::ostream& operator<<(std::ostream& o, const Bureaucrat& bur);