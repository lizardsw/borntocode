#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string name;
		bool sign;
		const int	sign_grade;
		const int	execute_grade;
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
		class NoSigned : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		Form ();
		Form (const std::string name, int sign_grade, int execute_grade);
		Form (const Form &copy);
		Form &operator=(const Form &copy);
		virtual ~Form();

		const std::string &getName() const;
		const bool &getSign() const;
		const int &get_signGrade() const;
		const int &get_executeGrade() const;
		void	setSign(bool check);

		void beSigned(const Bureaucrat &arg);

		virtual void execute(const Bureaucrat &executor) const = 0;
		void check_execute(const Bureaucrat &executor) const;
};

std::ostream& operator<<(std::ostream &out, const Form &arg);

#endif