#include "Form.hpp"

// const dest
Form::Form():name("default"),sign_grade(-1),execute_grade(-1)
{
	this->sign = false;
}

Form::Form(const std::string name, int sign_grade, int execute_grade):name(name), sign_grade(sign_grade), execute_grade(execute_grade)
{
	this->sign = false;
	if (sign_grade < 1 || execute_grade < 1)
		throw (Form::GradeTooHighException());
	else if (sign_grade > 150 || execute_grade > 150)
		throw (Form::GradeTooLowException());
}

Form::Form(const Form &copy):name(copy.name), sign_grade(copy.sign_grade), execute_grade(copy.execute_grade)
{
	this->sign = copy.sign;
}

Form &Form::operator=(const Form &copy)
{
	std::cout << "<<can't change name, grade>>" << std::endl;
	this->sign = copy.sign;
	return (*this);
}

Form::~Form()
{
}

// get function
const std::string &Form::getName() const
{
	return (this->name);
}

const int &Form::get_signGrade() const
{
	return (this->sign_grade);
}

const int &Form::get_executeGrade() const
{
	return (this->execute_grade);
}

const bool &Form::getSign() const
{
	return (this->sign);
}

// other
void Form::beSigned(const Bureaucrat &arg)
{
	if (this->sign_grade < arg.getGrade())
		throw (Form::GradeTooLowException());
	else
	{
		std::cout << "✅Form beSigned....." << std::endl;
		this->sign = true;
	}
}

std::ostream &operator<<(std::ostream &out, const Form &arg)
{
	out << "─────────────────────" << std::endl;
	out << "📝" << arg.getName() << " Form " << std::endl;
	out << std::boolalpha << "1️⃣ sign : " << arg.getSign() << std::endl;
	out << "2️⃣ sign_grade : " << arg.get_signGrade() << std::endl;
	out << "3️⃣ execute_grade : " << arg.get_executeGrade() << std::endl;
	out << "─────────────────────";
	
	return (out);
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("🚫Grade too high exception!🚫");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("🚫Grade too low exception!🚫");
}



