#pragma once
#include <string>
#include <iostream>

class Bureaucrat;

class Form
{
    public:
        Form();
        Form(const std::string& name);
		Form(const std::string& name, const std::string& target);
		Form(const std::string& name, const unsigned int gradeSign, const unsigned int gradeExec);
		Form(const std::string& name, const std::string& target, const unsigned int gradeSign, const unsigned int gradeExec);
		Form(const Form& other);
		Form &operator=(const Form& other);
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
        const std::string	name;
		const std::string	target;
        bool				isSigned;
        const unsigned int	gradeSign;
        const unsigned int	gradeExec;
};

std::ostream& operator<<(std::ostream& o, const Form& rhs);