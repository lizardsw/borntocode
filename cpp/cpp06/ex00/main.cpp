#include "convert.hpp"

int main(int argc, char *argv[])
{
	std::string my_string(argv[1]);

	if (my_string.length() == 1)
	{
		if (std::isdigit(my_string[0])) // 한자릿수 int
			display_input(std::atoi(argv[1]));
		else // 한자리 char
			display_input(argv[1][0]);
	}
	else // char 제외!
	{
		if (!(my_string.find(".") == std::string::npos)) // double, float
		{
			if (!(my_string.find("f") == std::string::npos)) // float
			{
				display_input(static_cast<float>(std::atof(argv[1])));
			}
			else // double
			{
				display_input(std::atof(argv[1]));
			}
		}
		else // int
		{
			long temp = std::atol(argv[1]);
			int ctemp = std::atoi(argv[1]);
			std::cout << temp << std::endl;
			std::cout << ctemp << std::endl;
			display_input(std::atoi(argv[1]));
		}
	}
	float a = 0.0;
	std::cout << a << std::endl;
	return 0;
}
