#include "easyfind.hpp"
#include <vector>
#include <set>

int main()
{
	std::vector<int> a_vector;
	std::set<int> a_set;

	for (int i = 0; i < 5 ; i++)
	{
		a_vector.push_back(i);
		a_set.insert(i);
	}

	std::vector<int>::iterator iter;
	iter = a_vector.begin();
	for (iter = a_vector.begin(); iter != a_vector.end(); iter++)
	{
		std::cout << *iter << " ";
	}
	std::cout << std::endl;
	std::set<int>::iterator set_iter;
	set_iter = a_set.begin();
	for (set_iter = a_set.begin(); set_iter != a_set.end(); set_iter++)
	{
		std::cout << *set_iter << " ";
	}
	std::cout << std::endl;

	try
	{
		std::cout << (*easyfind(a_vector, 4)) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << (*easyfind(a_set, 3)) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}


	try
	{
		std::cout << (*easyfind(a_vector, 10)) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << (*easyfind(a_set, -1)) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);	
}