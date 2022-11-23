#include <iostream>
#include <string>
#include <cstdlib>


int main(int argc, char *argv[])
{
	std::string A(argv[1]);
	std::cout << static_cast<char>(A) << std::endl;
	std::cout << static_cast<int>(A) << std::endl;
	std::cout << static_cast<float>(A) << std::endl;
	std::cout << static_cast<double>(A) << std::endl;

	return 0;
}