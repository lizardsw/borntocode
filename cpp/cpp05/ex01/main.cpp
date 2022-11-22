#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Form C("C", 100, 100);
		Form D(C);
		std::cout << C << std::endl;
		C = D;
		std::cout << D << std::endl;
		// Form K("K", 0, 0);
		// Form K("K", 160, 160);

		Bureaucrat AA("seongwch", 10);
		Form A("A", 3,3);
		std::cout << A << std::endl;
		Form B("B", 11, 11);
		AA.signForm(B);
		std::cout << B << std::endl;
		AA.signForm(A);
		std::cout << A << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}