#include "Span.hpp"

int main()
{
	Span spa = Span(5);
	spa.addNumber(6);
	spa.addNumber(3);
	spa.addNumber(17);
	spa.addNumber(9);
	spa.addNumber(11);
	std::cout << spa.shortestSpan() << std::endl;
	std::cout << spa.longestSpan() << std::endl;
	std::cout << std::endl;

	Span sp = Span(5);
	sp.addNumber(INT_MIN);
	sp.addNumber(INT_MAX);
	sp.addNumber(1);
	sp.addNumber(2);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	std::cout << std::endl;

	Span A(10000);
	try
	{
		A.addRandNumber(10000);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << A.shortestSpan() << std::endl;
		std::cout << A.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;

	Span B(3);
	B.addNumber(10);
	try
	{
		std::cout << B.shortestSpan() << std::endl;
		std::cout << B.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}