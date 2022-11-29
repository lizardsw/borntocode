#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

class Span
{
	private:
		std::vector<int> vec;
		Span();
	public:
		Span(const Span &copy);
		Span &operator=(const Span &copy);
		~Span();
		Span(unsigned int N);
		void addNumber();
		unsigned int shortestSpan();
		unsigned int longestSpan();
};

#endif