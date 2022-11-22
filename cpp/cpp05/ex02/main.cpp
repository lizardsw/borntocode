#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
	try
	{
		Bureaucrat seongwch("seongwch", 1);
		Bureaucrat youskim("youskim", 150);

		ShrubberyCreationForm A("A");
		seongwch.executeForm(A);
		seongwch.signForm(A);
		seongwch.executeForm(A);
		
		PresidentialPardonForm AA("AA");
		seongwch.executeForm(AA);
		seongwch.signForm(AA);
		seongwch.executeForm(AA);

		RobotomyRequestForm AAA("AAA");
		seongwch.executeForm(AAA);
		seongwch.signForm(AAA);
		seongwch.executeForm(AAA);
		seongwch.executeForm(AAA);
		seongwch.executeForm(AAA);
		seongwch.executeForm(AAA);



		std::cout << std::endl << std::endl;

		Form *fA = new ShrubberyCreationForm("fA");
		seongwch.executeForm(*fA);
		seongwch.signForm(*fA);
		seongwch.executeForm(*fA);

		Form *fAA = new PresidentialPardonForm("fA");
		seongwch.executeForm(*fAA);
		seongwch.signForm(*fAA);
		seongwch.executeForm(*fAA);

		Form *fAAA = new RobotomyRequestForm("fA");
		seongwch.executeForm(*fAAA);
		seongwch.signForm(*fAAA);
		seongwch.executeForm(*fAAA);

		std::cout << std::endl << std::endl;

		ShrubberyCreationForm B("B");
		youskim.signForm(B);
		youskim.executeForm(B);
		
		PresidentialPardonForm BB("BB");
		youskim.signForm(BB);
		youskim.executeForm(BB);

		RobotomyRequestForm BBB("BBB");
		youskim.signForm(BBB);
		youskim.executeForm(BBB);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}