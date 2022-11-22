#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string name):Form(name, 145, 137)
{	
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy):Form(copy)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
	std::cout << "<<can't change name, grade>>" << std::endl;
	this->setSign(copy.getSign());
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

void ShrubberyCreationForm::makeforest() const
{
	std::ofstream	outfile;
	std::string		file_name(this->getName() + "_shrubbery");
	std::string		forest(ASCII_FOREST);
	outfile.open(file_name, std::ios::trunc);
	outfile << forest;
	outfile.close();
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	this->check_execute(executor);
	this->makeforest();
}
