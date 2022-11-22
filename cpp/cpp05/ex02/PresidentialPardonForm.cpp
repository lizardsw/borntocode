#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string name):Form(name, 25, 5)
{	
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy):Form(copy)
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
	std::cout << "<<can't change name, grade>>" << std::endl;
	this->setSign(copy.getSign());
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{

}

void PresidentialPardonForm::make_pardon() const
{
	std::cout << "📩" << this->getName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	this->check_execute(executor);
	this->make_pardon();
}