#include "convert.hpp"

void display_input(char input)
{
	std::cout << "display char" << std::endl;
	std::cout << "char : " << static_cast<char>(input) << std::endl;
	std::cout << "int : " << static_cast<int>(input) << std::endl;
	std::cout << "float : " << static_cast<float>(input) << std::endl;
	std::cout << "double : " << static_cast<double>(input) << std::endl;
}

void display_input(int input)
{
	std::cout << "display int" << std::endl;
	std::cout << "char : " << static_cast<char>(input) << std::endl;
	std::cout << "int : " << static_cast<int>(input) << std::endl;
	std::cout << "float : " << static_cast<float>(input) << std::endl;
	std::cout << "double : " << static_cast<double>(input) << std::endl;
}

void display_input(float input)
{
	std::cout << "display float" << std::endl;
	std::cout << "char : " << static_cast<char>(input) << std::endl;
	std::cout << "int : " << static_cast<int>(input) << std::endl;
	std::cout << "float : " << static_cast<float>(input) << std::endl;
	std::cout << "double : " << static_cast<double>(input) << std::endl;
}

void display_input(double input)
{
	std::cout << "display double" << std::endl;
	std::cout << "char : " << static_cast<char>(input) << std::endl;
	std::cout << "int : " << static_cast<int>(input) << std::endl;
	std::cout << "float : " << static_cast<float>(input) << std::endl;
	std::cout << "double : " << static_cast<double>(input) << std::endl;
}

std::ostream &operator<<(std::ostream &out, char temp)
{
	if (temp <= 31 || temp >= 127)
	{
		out << "can't display ascii code";
	}
	return (out);
}