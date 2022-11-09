#pragma once
#include <string>
#include <iostream>
#include <cstdlib>

class Bureaucrat;

class Form
{
    public:
        Form(const std::string& name);
        Form(const std::string& name, const std::string& target);
        Form(const std::string& name, const unsigned int gradeSign, const unsigned int gradeExec);
        Form(const std::string& name, const std::string& target, const unsigned int gradeSign, const unsigned int gradeExec);
        Form(const Form& form);
        Form& operator=(const Form& form);
        ~Form();

        unsigned int getGradeSign() const;
        unsigned int getGradeExec() const;
        std::string getName() const;
        bool getIsSigned() const;
        std::string getTarget() const;
        void beSigned(const Bureaucrat& candidate);

        void execute(const Bureaucrat& executor) const;
	    virtual void action(const Bureaucrat& executor) const = 0;

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

        class FormNotSignedException : public std::exception
        {
        public:
            virtual const char* what() const throw();
        };

    private:
        Form() : name(""), target(""), isSigned(false), gradeSign(1), gradeExec(1) {};

        const std::string	name;
        const std::string   target;
        bool				isSigned;
        const unsigned int	gradeSign;
        const unsigned int	gradeExec;
};

std::ostream& operator<<(std::ostream& o, const Form& rhs);