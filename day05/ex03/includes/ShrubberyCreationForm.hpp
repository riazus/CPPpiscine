#include "Form.hpp"

class ShrubberyCreationForm : public Form
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& rhs);
		~ShrubberyCreationForm();
		
		void action(const Bureaucrat& executor) const;

		class ErrorOpenFile : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};