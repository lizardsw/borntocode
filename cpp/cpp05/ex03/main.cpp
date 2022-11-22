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
		Form *sh = A.makeForm("shrubberycreation request", "A");
		seongwch.signForm(*sh);
		seongwch.executeForm(*sh);

		Form *rb = A.makeForm("robotomy request", "B");
		seongwch.signForm(*rb);
		seongwch.executeForm(*rb);

		Form *rc = A.makeForm("robotomy request", "B");
		seongwch.signForm(*rc);
		seongwch.executeForm(*rc);
		seongwch.executeForm(*rc);

		seongwch.executeForm(*rc);

		seongwch.executeForm(*rc);

	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}