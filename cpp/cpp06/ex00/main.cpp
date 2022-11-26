#include <iostream>
#include <string>
#include <cstdlib>

bool is_nan(std::string input)
{
	int length = input.length();
	for (int i = 0; i < length; i++)
	{
		input[i] = static_cast<unsigned char>(std::toupper(input[i]));
	}
	if(!(input.find("NAN") == std::string::npos))
		return (true);
	return (false);
}

bool is_err_float_str(char *float_string)
{
	if (float_string == NULL)
		return (false);
	if (float_string[0] == '\0')
		return (false);
	std::string input(float_string);
	if(input.length() != 1)
		return (true);
	if(!(input.find("f") == std::string::npos))
		return (false);
	return (true);
}

void print_int(double input)
{
	std::cout << "int : ";
	if (input > 2147483647 || input < -2147483648)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(input) << std::endl;
}

void print_char(double input)
{
	std::cout << "char : ";
	if (input < 0 || input > 127)
		std::cout << "impossible" << std::endl;
	else if ((input >= 0 && input <= 31) || input == 127)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << static_cast<char>(input) << std::endl;
}

void print_float(double input)
{
	float float_input = static_cast<float>(input);
	std::cout << "float : ";
	std::cout << float_input;
	if (float_input - static_cast<int>(input) == 0)
		std::cout << ".0";
	std::cout << "f" << std::endl;
}

void print_double(double input)
{
	std::cout << "double : ";
	std::cout << input;
	if (input - static_cast<int>(input) == 0)
		std::cout << ".0";
	std::cout << std::endl;
}

void print_nan()
{
	std::cout <<"char : impossible" << std::endl;
	std::cout <<"int : impossible" << std::endl;
	std::cout <<"float : nanf" << std::endl;
	std::cout <<"double : nan" << std::endl;
}

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		std::cout << "argc error!" << std::endl;
		return (0);
	}
	std::string str_input = std::string(argv[1]);
	double double_input;
	char *float_str = NULL;
	if (str_input.length() == 1 && !(std::isdigit(argv[1][0])))
		double_input = static_cast<char>(argv[1][0]);
	else
		double_input = std::strtod(argv[1], &float_str);
	if (is_nan(str_input) || is_err_float_str(float_str))
	{
		print_nan();
		return (0);
	}
	print_char(double_input);
	print_int(double_input);
	print_float(double_input);
	print_double(double_input);
	return (0);
}
