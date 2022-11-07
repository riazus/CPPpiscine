#pragma once
#include <string>
#include <iostream>

class Bureaucrat;

class Form
{
    public:
        Form();
        Form(const std::string& name);
        Form(const std::string& name, const unsigned int gradeSign, const unsigned int gradeExec);
        Form(const Form& form);
        Form& operator=(const Form& form);
        ~Form();

        unsigned int getGradeSign() const;
        unsigned int getGradeExec() const;
        std::string getName() const;
        bool getIsSigned() const;
        void beSigned(const Bureaucrat& candidate);

        class GradeTooHighException : public std::exception
        {
        public:
            virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
        public:
            virtual const char* what() const throw();
        };

        class FormAlreadySignedException : public std::exception
        {
        public:
            virtual const char* what() const throw();
        };

    private:
        const std::string	name;
        bool				isSigned;
        const unsigned int	gradeSign;
        const unsigned int	gradeExec;
};

std::ostream& operator<<(std::ostream& o, const Form& rhs);