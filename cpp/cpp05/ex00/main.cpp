#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat first("first", 0);
		// Bureaucrat second("second", 151);

		Bureaucrat A("seongwch", 149);
		Bureaucrat B(A);
		Bureaucrat C;
		C = A;
		A.upGrade();
		A.upGrade();
		B.downGrade();
		C.downGrade();
		// C.downGrade();

		Bureaucrat D("youskim", 2);
		D.upGrade();
		std::cout << D << std::endl;
		D.upGrade();
		std::cout << D << std::endl;
		D.upGrade();
		std::cout << D << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}