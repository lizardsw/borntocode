#include <string>
#include <iostream>
#include <iomanip>

void modified(std::string temp)
{
	std::cout << temp << std::endl;
	temp[0] = 'a';
	std::cout << temp << std::endl;
}

void test(std::string arg[])
{




}

void test1(std::string arg[6])
{
	arg[0] = "hello"; 
}

int main()
{
	std::string hi[4];
	std::string temp;


	// hi[0] = "yes";
	// hi[1] = "hi";
	// hi[2] = "me";
	// std::cout << hi[0];
	// std::cout << hi[1] << std::endl;
	// test1(hi);
	// std::cout << hi[0];
	// std::cout << hi[1] << std::endl;
	while (1)
	{
		std::getline(std::cin, hi[0]);
		std::cout << hi[0] << std::endl;
		modified(hi[0]);
		std::cout << "|";
		std::cout << std::setw(4);
		std::cout << hi[0];
		std::cout << "|" << std::endl;
		std::cout << hi[0] << std::endl;
		std::cout << hi[0].length() << std::endl;
		std::cout << hi[0].insert(2,"hi") << std::endl;
		std::cout << hi[0].erase(2, hi[0].length()) << std::endl;
		std::cout << std::setfill('-') << std::setw(10) << "-" << std::endl;
		

	}

	return (0);
}