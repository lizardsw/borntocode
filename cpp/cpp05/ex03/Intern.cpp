#include "Intern.hpp"

Intern::Intern()
{
	this->ft_ptr[0] = &Intern::make_sh;
	this->ft_ptr[1] = &Intern::make_ro;
	this->ft_ptr[2] = &Intern::make_pr;
}

Intern::Intern(const Intern &copy)
{
	this->ft_ptr[0] = copy.ft_ptr[0];
	this->ft_ptr[1] = copy.ft_ptr[1];
	this->ft_ptr[2] = copy.ft_ptr[2];
}

Intern &Intern::operator=(const Intern &copy)
{
	this->ft_ptr[0] = copy.ft_ptr[0];
	this->ft_ptr[1] = copy.ft_ptr[1];
	this->ft_ptr[2] = copy.ft_ptr[2];
	return (*this);
}

Intern::~Intern()
{
}

Form *Intern::makeForm(std::string type, std::string name)
{
	std::string form_type[3] = {"shrubberycreation request","robotomy request", "presidentialpardon request"};
	for (int i = 0; i < 3; i++)
	{
		if (type == form_type[i])
			return ((this->*ft_ptr[i])(name));
	}
	throw(Intern::NoTypeException());
}

Form *Intern::make_sh(std::string name)
{
	ShrubberyCreationForm *temp = new ShrubberyCreationForm(name);
	return (temp);
}

Form *Intern::make_ro(std::string name)
{
	RobotomyRequestForm *temp = new RobotomyRequestForm(name);
	return (temp);
}

Form *Intern::make_pr(std::string name)
{
	PresidentialPardonForm *temp = new PresidentialPardonForm(name);
	return (temp);
}

const char *Intern::NoTypeException::what() const throw()
{
	return ("🚫No type exception🚫");
}
