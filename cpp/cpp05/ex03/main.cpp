#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main()
{
	try
	{
		Bureaucrat seongwch("seongwch", 1);
		Bureaucrat youskim("youskim", 150);

		Intern A;
		Intern B(A);
		Intern C;
		C = A;
		Form *sh = A.makeForm("shrubberycreation request", "A");
		seongwch.signForm(*sh);
		seongwch.executeForm(*sh);
		delete sh;
		std::cout << std::endl;

		Form *rb = B.makeForm("robotomy request", "B");
		seongwch.signForm(*rb);
		seongwch.executeForm(*rb);
		seongwch.executeForm(*rb);
		seongwch.executeForm(*rb);
		delete rb;
		std::cout << std::endl;


		Form *pr = C.makeForm("presidentialpardon request", "C");
		seongwch.signForm(*pr);
		seongwch.executeForm(*pr);
		delete pr;
		std::cout << std::endl;


		Form *ex = C.makeForm("request", "D");
		seongwch.signForm(*ex);
		seongwch.executeForm(*ex);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}