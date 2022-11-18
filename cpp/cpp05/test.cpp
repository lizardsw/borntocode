#include <exception>
#include <iostream>

int main(void)
{
	std::string	key;
	int value;

	while (true)
	{
		try
		{
			std::cin >> value;
			if (value > 10)
			{
				throw(value);
				std::cout << "throw!" << std::endl;
			}
			// else if (value > 20)
			// {
			// 	throw(std::string("hello"));
			// }
			std::cout<< "not throw!" << std::endl;
		}
		catch(int value)
		{
			std::cout << "catch!" << value << std::endl;
		}
		catch (std::string hello)
		{
			std::cout << "catchb!" << hello << std::endl;
		}
		std::cout << "hello!" << std::endl;
		
	}
	return (0);
}