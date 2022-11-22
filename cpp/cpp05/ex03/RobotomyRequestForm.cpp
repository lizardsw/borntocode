#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string name):Form(name, 72, 45)
{	
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy):Form(copy)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
	std::cout << "<<can't change name, grade>>" << std::endl;
	this->setSign(copy.getSign());
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

void RobotomyRequestForm::make_robot() const
{
	int temp = rand() % 2;
	
	std::cout << "dril........................!" << std::endl;
	if (temp == 0)
	{
		std::cout << "🤖" << this->getName() << " has been robotomized success" << std::endl;
	}
	else
	{
		std::cout << "🤖" <<this->getName() << " has been robotomized fail" << std::endl;
	}
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	this->check_execute(executor);
	this->make_robot();
}