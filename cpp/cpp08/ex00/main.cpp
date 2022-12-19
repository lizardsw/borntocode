#include "easyfind.hpp"
#include <vector>
#include <set>
#include <deque>

int main()
{
	std::vector<int> a_vector;
	std::deque<int> a_deque;

	for (int i = 0; i < 5 ; i++)
	{
		a_vector.push_back(i);
		a_deque.push_back(i);
	}

	std::vector<int>::iterator iter;
	iter = a_vector.begin();
	for (iter = a_vector.begin(); iter != a_vector.end(); iter++)
	{
		std::cout << *iter << " ";
	}
	std::cout << std::endl;

	std::deque<int>::iterator deq_iter;
	deq_iter = a_deque.begin();
	for (deq_iter = a_deque.begin(); deq_iter != a_deque.end(); deq_iter++)
	{
		std::cout << *deq_iter << " ";
	}
	std::cout << std::endl;

	// easyfind!
	try
	{
		std::cout << (*easyfind(a_vector, 3)) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << (*easyfind(a_deque, 4)) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	// easyfind error!
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
		std::cout << (*easyfind(a_deque, 10)) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);	
}