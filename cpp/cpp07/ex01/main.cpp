#include "iter.hpp"

int main()
{
	int int_array[10] = {1,2,3,4,5,6,7,8,9,10};
	char char_array[5] = {'a', 'b', 'c', 'd', 'e'};
	float float_array[5] = {0.1, 0.2, 0.3, 0.4, 0.5};
	std::string string_array[5] = {"one", "two", "three", "four", "five"};

	iter(int_array, 10, iter_print<int>);
	std::cout << std::endl;
	iter(char_array, 5, iter_print<char>);
	std::cout << std::endl;
	iter(float_array, 5, iter_print<float>);
	std::cout << std::endl;
	iter(string_array, 5, iter_print<std::string>);
	std::cout << std::endl;

	iter(int_array, 10, plus_one<int>);
	iter(char_array, 5, plus_one<char>);
	iter(float_array, 5, plus_one<float>);
	iter(string_array, 5, plus_one<std::string>);

	iter(int_array, 10, iter_print<int>);
	std::cout << std::endl;
	iter(char_array, 5, iter_print<char>);
	std::cout << std::endl;
	iter(float_array, 5, iter_print<float>);
	std::cout << std::endl;
	iter(string_array, 5, iter_print<std::string>);
	std::cout << std::endl;

	return (0);
}