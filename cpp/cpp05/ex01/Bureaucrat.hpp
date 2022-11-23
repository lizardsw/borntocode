#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
		const std::string name;
		int grade;
		Bureaucrat ();
	public:
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		Bureaucrat (const std::string name, int grade);
		Bureaucrat (const Bureaucrat &copy);
		Bureaucrat &operator=(const Bureaucrat &copy);
		~Bureaucrat();

		const std::string &getName() const;
		const int &getGrade() const;
		void	setGrade(int grade);

		void	upGrade();
		void	downGrade();

		void	signForm(Form &arg) const;
};

std::ostream& operator<<(std::ostream &out, const Bureaucrat &arg);

#endif