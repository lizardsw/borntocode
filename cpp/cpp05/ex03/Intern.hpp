#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	private:
		Form  *(Intern::*ft_ptr[3])(std::string name);
		Form *make_sh(std::string name);
		Form *make_ro(std::string name);
		Form *make_pr(std::string name);
	public:
		class NoTypeException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		Intern();
		Intern(const Intern &copy);
		Intern &operator=(const Intern &copy);
		~Intern();
		Form *makeForm(std::string type, std::string name);
};

#endif