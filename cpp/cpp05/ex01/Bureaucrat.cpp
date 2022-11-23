#include "Bureaucrat.hpp"

// const dest
Bureaucrat::Bureaucrat(void):name("default")
{
	this->grade = -1;
}

Bureaucrat::Bureaucrat(const std::string name, int grade):name(name)
{
	this->grade = grade;
	if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	else if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy):name(copy.name)
{
	this->grade = copy.grade;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy)
{
	std::cout << "<<can't change name>>" << std::endl;
	this->grade = copy.grade;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
}

// get & set funct
const std::string &Bureaucrat::getName() const
{
	return (this->name);
}

const int &Bureaucrat::getGrade() const
{
	return (this->grade);
}

void Bureaucrat::setGrade(int grade)
{
	this->grade = grade;
}

// other
void Bureaucrat::upGrade()
{
	this->grade--;
	if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	else
		std::cout << "⬆️ upgrade .... now " << *this << std::endl;
}

void Bureaucrat::downGrade()
{
	this->grade++;
	if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	else
		std::cout << "⬇️ downgrade .... now " << *this << std::endl;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("🚫Grade too high exception!🚫");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("🚫Grade too low exception!🚫");
}

std::ostream& operator<<(std::ostream &out, const Bureaucrat &arg)
{
	out << "🙍" << arg.getName() << " bureaucrat grade " << arg.getGrade();
	return (out);
}

// extra
void	Bureaucrat::signForm(Form &arg) const
{
	try
	{
		arg.beSigned(*this);
		std::cout << "✅" << this->name << " signed " <<  arg.getName() << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << "🚫" << this->name << " couldn't sign " << arg.getName() << " becuase bureaucrat grade..." << std::endl;
		std::cout << e.what() << std::endl;
	}
}